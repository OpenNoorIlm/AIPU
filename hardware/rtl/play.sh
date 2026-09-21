#!/bin/bash
# play.sh — Flash and test the AIPU in one command
set -e
cd "$(dirname "$0")"
openFPGALoader -c ft232 -b tangprimer20k top_fpga.fs && \
python3 ~/teacher-aipu/software/aipu.py
