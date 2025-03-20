@echo off
REM 
if not exist "build" mkdir build

REM 
cd build

REM 
cmake ..

REM 
make

REM 
./main.exe

REM 
cd ..
pause
