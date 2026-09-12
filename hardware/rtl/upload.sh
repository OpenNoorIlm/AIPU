#!/bin/bash
echo "=== Killing old processes ==="
kill $(pgrep -f jtag_bridge) 2>/dev/null
sudo fuser -k /dev/ttyUSB0
sleep 2

echo "=== Starting Python JTAG bridge ==="
sudo python3 jtag_bridge.py &
BRIDGE_PID=$!
sleep 3

echo "=== Flashing Tang Primer 20K ==="
/usr/local/bin/openocd -f tang.cfg -c "pld load gowin.pld top_fpga.fs; shutdown"
RESULT=$?

echo "=== Cleaning up ==="
kill $BRIDGE_PID 2>/dev/null

if [ $RESULT -eq 0 ]; then
    echo "=== FLASH SUCCESS ==="
else
    echo "=== FLASH FAILED ==="
fi
