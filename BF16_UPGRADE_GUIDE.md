# BF16 Data-Path Upgrade Guide

## Why BF16 needs a separate step

FP8 E4M3 operands are 8 bits — the existing SRAM, wires, and ports are unchanged.
BF16 operands are **16 bits** — every data wire in the systolic array must widen.

## What to change (in order)

### 1. mac.v
- Change `input [7:0] a, b` → `input [15:0] a, b`
- Implement bf16_mul: mantissas are 8-bit (1.mmmmmmm × 1.mmmmmmm = 16-bit product)
  - `ep = ea + eb - 127` (BF16 bias = 127, same as FP32)
  - `mp = {1'b1, a[6:0]} * {1'b1, b[6:0]}` (8×8=16-bit)
  - Normalize mp, pack as FP32

### 2. systolic_NxN.v / chain_CxC.v / grid_GxG.v
- All `[7:0]` a/b wires and ports → `[DATA_W-1:0]` where DATA_W is a parameter
- Add `parameter DATA_W = 8` to each module, pass down the hierarchy

### 3. memory_ctrl.v
- When precision == BF16, load **2 bytes** per matrix element instead of 1
- a_buf and b_buf become `[15:0]`
- SRAM layout for BF16: col k of A starts at src + k*N*2 (2 bytes per element)

### 4. top_fpga.v
- SRAM is already byte-addressed; BF16 just uses twice as many bytes per matrix

## Quick estimate (G=1, C=1, N=4)
- INT8/FP8: 16 MACs × 8×8 multiplier  ≈ 400 LUTs
- BF16:     16 MACs × 8×8 multiplier  ≈ 400 LUTs (same! mantissa multiply stays 8×8)
             + wider routing (8→16-bit wires) ≈ +100 LUTs
- Net cost: ~25% more LUTs for BF16 vs FP8

## Current status
precision=10 in the compute packet aliases the FP8 path as a placeholder.
It will produce FP8 results, not BF16 results, until this guide is implemented.
