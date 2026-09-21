@echo off
REM play.bat — Flash and test the AIPU (Windows CMD)
cd /d "%~dp0"
openFPGALoader -c ft232 -b tangprimer20k top_fpga.fs
python3 %USERPROFILE%\teacher-aipu\software\aipu.py
