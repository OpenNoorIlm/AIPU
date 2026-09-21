#!/usr/bin/env python3
"""
editGrids.py — Interactive G/C/N editor + board selector + full rebuild pipeline

Usage:
  python3 editGrids.py            — interactive mode
  python3 editGrids.py --revert  — revert to safe baseline (G=1 C=1 N=4)
"""
import re, subprocess, sys, os, time, argparse
from pathlib import Path

RTL = Path(__file__).parent
TOP = RTL / "top_fpga.v"
SW  = Path.home() / "teacher-aipu/software/aipu.py"

# ── Safe baseline (original Teacher AIPU, all 7 tests confirmed passing) ──
BASELINE = dict(G=1, C=1, N=4)

# ── Board database ─────────────────────────────────────────────────────────
BOARDS = [
    {
        "name": "Sipeed Tang Primer 20K",
        "chip": "GW2A-18C",
        "luts": 20736,
        "dsps": 48,
        "bram_kb": 828,
        "max_mhz": 200,
        "toolchain": "gowin/nextpnr-gowin",
        "current": True,
        "int8": True, "fp8": False, "bf16": False,
        "note": "Current board — confirmed working",
    },
    {
        "name": "Sipeed Tang Nano 20K",
        "chip": "GW2A-18C",
        "luts": 20736,
        "dsps": 48,
        "bram_kb": 828,
        "max_mhz": 200,
        "toolchain": "gowin/nextpnr-gowin",
        "current": False,
        "int8": True, "fp8": False, "bf16": False,
        "note": "Same chip as Tang Primer 20K",
    },
    {
        "name": "Sipeed Tang Primer 25K",
        "chip": "GW5A-25",
        "luts": 23040,
        "dsps": 28,
        "bram_kb": 1008,
        "max_mhz": 250,
        "toolchain": "gowin/nextpnr-gowin",
        "current": False,
        "int8": True, "fp8": False, "bf16": False,
        "note": "Slightly more LUTs, newer GW5 series",
    },
    {
        "name": "Sipeed Tang Mega 138K",
        "chip": "GW5AST-138B",
        "luts": 134217,
        "dsps": 320,
        "bram_kb": 6120,
        "max_mhz": 300,
        "toolchain": "gowin/nextpnr-gowin",
        "current": False,
        "int8": True, "fp8": False, "bf16": False,
        "note": "Large Gowin — G=8 or higher feasible",
    },
    {
        "name": "Lattice iCE40UP5K",
        "chip": "iCE40UP5K",
        "luts": 5280,
        "dsps": 8,
        "bram_kb": 120,
        "max_mhz": 24,
        "toolchain": "icestorm/nextpnr-ice40",
        "current": False,
        "int8": True, "fp8": False, "bf16": False,
        "note": "Very small — G=1 N=2 only",
    },
    {
        "name": "Lattice ECP5 25F",
        "chip": "LFE5U-25F",
        "luts": 24288,
        "dsps": 28,
        "bram_kb": 1008,
        "max_mhz": 250,
        "toolchain": "prjtrellis/nextpnr-ecp5",
        "current": False,
        "int8": True, "fp8": False, "bf16": False,
        "note": "Open toolchain, widely supported",
    },
    {
        "name": "Lattice ECP5 85F",
        "chip": "LFE5U-85F",
        "luts": 83640,
        "dsps": 156,
        "bram_kb": 3888,
        "max_mhz": 250,
        "toolchain": "prjtrellis/nextpnr-ecp5",
        "current": False,
        "int8": True, "fp8": False, "bf16": False,
        "note": "Good mid-range open-source board",
    },
    {
        "name": "Xilinx Arty A7-35T",
        "chip": "XC7A35T",
        "luts": 20800,
        "dsps": 90,
        "bram_kb": 1800,
        "max_mhz": 450,
        "toolchain": "vivado/nextpnr-xilinx",
        "current": False,
        "int8": True, "fp8": False, "bf16": False,
        "note": "More DSPs than Gowin at similar LUT count",
    },
    {
        "name": "Xilinx Arty A7-100T",
        "chip": "XC7A100T",
        "luts": 63400,
        "dsps": 240,
        "bram_kb": 4860,
        "max_mhz": 450,
        "toolchain": "vivado/nextpnr-xilinx",
        "current": False,
        "int8": True, "fp8": False, "bf16": False,
        "note": "G=4 or G=5 feasible",
    },
    {
        "name": "Intel DE10-Nano (Cyclone V)",
        "chip": "5CSEBA6U23I7",
        "luts": 41910,
        "dsps": 112,
        "bram_kb": 5570,
        "max_mhz": 400,
        "toolchain": "quartus",
        "current": False,
        "int8": True, "fp8": False, "bf16": False,
        "note": "Used by MiSTer FPGA project",
    },
]

# ── LUT estimator (empirical from our builds) ──────────────────────────────
# G=1,C=1,N=4 → ~1914 LUTs   G=2,C=1,N=4 → ~4419 LUTs
# base_overhead ≈ 1082,  per_mac ≈ 52 LUTs
def estimate_luts(G, C, N):
    return int(1082 + G*G * C * N*N * 52)

def lut_utilization(G, C, N, board_luts):
    est = estimate_luts(G, C, N)
    return est, est / board_luts * 100

# ── Auto-install deps ──────────────────────────────────────────────────────
try:
    from rich.console import Console
    from rich.table import Table
    from rich.prompt import Prompt, Confirm
    from rich.panel import Panel
    from tqdm import tqdm
except ImportError:
    subprocess.run([sys.executable, "-m", "pip", "install", "rich", "tqdm", "-q"])
    from rich.console import Console
    from rich.table import Table
    from rich.prompt import Prompt, Confirm
    from rich.panel import Panel
    from tqdm import tqdm

console = Console()

# ── File helpers ───────────────────────────────────────────────────────────
def read_params():
    txt = TOP.read_text()
    m = re.search(r'\.G\((\d+)\),\s*\.C\((\d+)\),\s*\.N\((\d+)\)', txt)
    if not m:
        console.print("[red]Could not find .G/.C/.N in top_fpga.v[/red]")
        sys.exit(1)
    return int(m.group(1)), int(m.group(2)), int(m.group(3))

def write_params(G, C, N):
    txt = TOP.read_text()
    txt = re.sub(
        r'\.G\(\d+\),\s*\.C\(\d+\),\s*\.N\(\d+\)',
        f'.G({G}), .C({C}), .N({N})',
        txt
    )
    cycles = max(300, (4 * N * N + 2 * N + 20) * 2)
    txt = re.sub(r'(task_cycles\s*=\s*32\'d)\d+', f'\\g<1>{cycles}', txt)
    TOP.write_text(txt)

# ── Param + board table ────────────────────────────────────────────────────
def show_param_table(G, C, N, board, label="Parameters"):
    est_luts, pct = lut_utilization(G, C, N, board["luts"])
    fits = pct <= 90
    util_color = "green" if pct < 70 else "yellow" if pct < 90 else "red"
    util_str = f"{est_luts:,} / {board['luts']:,} ({pct:.1f}%)"

    macs = G*G * C * N*N
    tops_27  = macs * 2 * 27e6           / 1e12
    tops_max = macs * 2 * board["max_mhz"] * 1e6 / 1e12

    t = Table(title=f"[bold cyan]{label}[/bold cyan]", show_header=True)
    t.add_column("Param",   style="bold yellow")
    t.add_column("Value",   style="bold green")
    t.add_column("Detail")

    t.add_row("Board",   board["name"], board["chip"])
    t.add_row("G",       str(G),        f"{G}×{G} grid of systolic arrays")
    t.add_row("C",       str(C),        f"{C} chain(s) per cell")
    t.add_row("N",       str(N),        f"{N}×{N} systolic array per chain")
    t.add_row("MACs",    f"{macs:,}",   "multiply-accumulate units")
    t.add_row("TOPS @27MHz",              f"{tops_27:.6f}",  "FPGA crystal clock")
    t.add_row(f"TOPS @{board['max_mhz']}MHz", f"{tops_max:.4f}", "Board max freq estimate")
    t.add_row("Est. LUTs", f"[{util_color}]{util_str}[/{util_color}]",
              "✅ fits" if fits else "❌ EXCEEDS — reduce G/C/N or pick larger board")

    # Precision row
    int8_s = "[green]INT8 ✅[/green]"
    fp8_s  = "[yellow]FP8 ✅[/yellow]"  if board["fp8"]  else "[dim]FP8  (future RTL)[/dim]"
    bf16_s = "[yellow]BF16 ✅[/yellow]" if board["bf16"] else "[dim]BF16 (future RTL)[/dim]"
    t.add_row("Precision", f"{int8_s}  {fp8_s}  {bf16_s}",
              "All FPGAs support FP8/BF16 once RTL is added")

    console.print(t)
    return fits

# ── Board selector with search ─────────────────────────────────────────────
def select_board():
    console.print("\n[bold cyan]Board Selection[/bold cyan]")
    console.print("[dim]Type part of a name or chip to filter, or press Enter to list all.[/dim]\n")
    query = Prompt.ask("Search", default="").strip().lower()

    matches = [b for b in BOARDS if
               query in b["name"].lower() or
               query in b["chip"].lower() or
               query in b["note"].lower()] if query else BOARDS

    if not matches:
        console.print("[red]No match — showing all.[/red]")
        matches = BOARDS

    t = Table(show_header=True, title="[bold]Supported Boards[/bold]")
    t.add_column("#",      style="bold", width=3)
    t.add_column("Board",  style="cyan")
    t.add_column("Chip",   style="yellow")
    t.add_column("LUTs",   justify="right")
    t.add_column("DSPs",   justify="right")
    t.add_column("BRAM",   justify="right")
    t.add_column("MaxMHz", justify="right")
    t.add_column("INT8")
    t.add_column("FP8")
    t.add_column("BF16")
    t.add_column("Note",   style="dim")

    for i, b in enumerate(matches):
        marker = " ◀" if b["current"] else ""
        t.add_row(
            str(i+1),
            b["name"] + marker,
            b["chip"],
            f"{b['luts']:,}",
            str(b["dsps"]),
            f"{b['bram_kb']} KB",
            str(b["max_mhz"]),
            "✅" if b["int8"] else "❌",
            "✅" if b["fp8"]  else "—",
            "✅" if b["bf16"] else "—",
            b["note"],
        )
    console.print(t)
    console.print("[dim]FP8/BF16 shows — because those precision formats are RTL not yet implemented.\n"
                  "All boards will support them once mac.v gains FP8/BF16 multiplier units.[/dim]\n")

    default_idx = next((str(i+1) for i, b in enumerate(matches) if b["current"]), "1")
    choice = int(Prompt.ask("Select board #", default=default_idx)) - 1
    if not (0 <= choice < len(matches)):
        console.print("[red]Invalid — keeping current board.[/red]")
        return next(b for b in BOARDS if b["current"])
    return matches[choice]

# ── Pipeline runner ────────────────────────────────────────────────────────
def run_step(label, cmd, cwd=RTL, timeout=300):
    console.print(f"\n[bold blue]▶ {label}[/bold blue]")
    start = time.time()
    proc = subprocess.Popen(
        cmd, shell=True, cwd=str(cwd),
        stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
        text=True, bufsize=1
    )
    lines = []
    for line in proc.stdout:
        lines.append(line)
        if any(k in line for k in ["MHz", "PASS", "FAIL", "ERROR", "Error",
                                    "LUT4", "ALU", "cells", "Load SRAM",
                                    "Match:", "Test", "Done", "DONE"]):
            console.print(f"  [dim]{line.rstrip()}[/dim]")
    proc.wait(timeout=timeout)
    elapsed = time.time() - start
    if proc.returncode != 0:
        console.print(f"[red]✗ FAILED ({elapsed:.1f}s)[/red]")
        for l in lines[-10:]:
            console.print(f"  [red]{l.rstrip()}[/red]")
        return False
    console.print(f"[green]✓ Done ({elapsed:.1f}s)[/green]")
    return True

def run_pipeline():
    steps = [
        ("Synthesize", (
            './synlig/synlig -p "read_systemverilog mac.v systolic_NxN.v chain_CxC.v '
            'grid_GxG.v dispatcher.v memory_ctrl.v uart_tx.v uart_rx.v result_sender.v '
            'top.v top_fpga.v; synth_gowin -top top_fpga -json top_fpga.json" 2>&1'
        )),
        ("Patch ES grade", (
            'python3 -c "import re; f=open(\'top_fpga.json\');t=f.read();f.close();'
            't=re.sub(\'GW2A-18C-ES\',\'GW2A-18C\',t);f=open(\'top_fpga_p.json\',\'w\');'
            'f.write(t);f.close()"'
        )),
        ("Place & Route", (
            'nextpnr-himbaechel-gowin --device GW2A-LV18PG256C8/I7 --vopt family=GW2A-18C '
            '--vopt cst=../top.cst --json top_fpga_p.json --write top_fpga_routed.json 2>&1'
        )),
        ("Pack bitstream", "gowin_pack -d GW2A-18C -o top_fpga.fs top_fpga_routed.json 2>&1"),
        ("Flash FPGA",     "openFPGALoader -c ft232 -b tangprimer20k top_fpga.fs 2>&1"),
        ("Run tests",      f"python3 {SW} 2>&1"),
    ]
    with tqdm(total=len(steps), desc="Pipeline", unit="step",
              bar_format="{l_bar}{bar}| {n}/{total} [{elapsed}]") as pbar:
        for label, cmd in steps:
            pbar.set_description(label)
            ok = run_step(label, cmd)
            pbar.update(1)
            if not ok and label != "Flash FPGA":
                if not Confirm.ask(f"[yellow]{label} failed — continue anyway?[/yellow]"):
                    return False
    return True

# ── Entry point ────────────────────────────────────────────────────────────
def main():
    parser = argparse.ArgumentParser(description="OpenNoorIlm AIPU grid editor")
    parser.add_argument("--revert", action="store_true",
                        help="Revert to safe baseline G=1 C=1 N=4 and rebuild")
    args = parser.parse_args()

    console.print(Panel.fit(
        "[bold cyan]OpenNoorIlm AIPU — Grid Parameter Editor[/bold cyan]\n"
        "[dim]Edit G/C/N → board check → synthesize → P&R → flash → test[/dim]"
    ))

    # ── Revert ─────────────────────────────────────────────────────────────
    if args.revert:
        G, C, N = BASELINE["G"], BASELINE["C"], BASELINE["N"]
        board = next(b for b in BOARDS if b["current"])
        console.print(f"\n[yellow]Reverting to safe baseline: G={G} C={C} N={N}[/yellow]")
        write_params(G, C, N)
        show_param_table(G, C, N, board, "Baseline (G=1 C=1 N=4)")
        if Confirm.ask("Rebuild and flash?"):
            run_pipeline()
        console.print(Panel.fit("[bold green]Reverted![/bold green]"))
        return

    # ── Interactive ─────────────────────────────────────────────────────────
    G, C, N = read_params()
    board = next(b for b in BOARDS if b["current"])

    show_param_table(G, C, N, board, "Current Parameters")

    if Confirm.ask("\nChange target board?", default=False):
        board = select_board()

    # Parameter loop — re-prompt if design exceeds board
    while True:
        console.print()
        new_G = int(Prompt.ask("G (grid size)",       default=str(G)))
        new_C = int(Prompt.ask("C (chains per cell)", default=str(C)))
        new_N = int(Prompt.ask("N (array size)",      default=str(N)))

        if new_G == G and new_C == C and new_N == N:
            console.print("[yellow]No changes — nothing to do.[/yellow]")
            return

        fits = show_param_table(new_G, new_C, new_N, board, "New Parameters")

        if not fits:
            est, pct = lut_utilization(new_G, new_C, new_N, board["luts"])
            console.print(
                f"\n[red bold]⚠  Exceeds {board['name']}![/red bold]\n"
                f"  Estimated [red]{est:,}[/red] LUTs  vs  "
                f"board max [green]{board['luts']:,}[/green]  ({pct:.1f}%)\n"
                f"  Reduce G/C/N or pick a larger board.\n"
            )
            if not Confirm.ask("Enter different parameters?", default=True):
                console.print("[dim]Aborted.[/dim]")
                return
            G, C, N = new_G, new_C, new_N
            continue
        break

    if not Confirm.ask("\n[bold]Proceed with full rebuild + flash?[/bold]"):
        console.print("[dim]Aborted.[/dim]")
        return

    write_params(new_G, new_C, new_N)
    console.print(f"[green]top_fpga.v updated → G={new_G} C={new_C} N={new_N}[/green]")
    run_pipeline()
    console.print(Panel.fit("[bold green]Done![/bold green]"))

if __name__ == "__main__":
    main()
