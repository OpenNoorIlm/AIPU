# play.ps1 — Flash and test the AIPU (Windows / WSL PowerShell)
$ErrorActionPreference = "Stop"
$dir = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $dir
openFPGALoader -c ft232 -b tangprimer20k top_fpga.fs
python3 ~/teacher-aipu/software/aipu.py
