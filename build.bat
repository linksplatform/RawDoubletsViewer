@echo off
echo Building RawDoubletsViewer...
echo.

cd winapi

echo Compiling resources...
windres main.rc -o main.o
if %errorlevel% neq 0 (
    echo Error: Failed to compile resources. Make sure windres is installed.
    pause
    exit /b 1
)

echo Compiling application...
g++ -o RawLinks.exe main.cpp engine.cpp main.o -lcomctl32 -mwindows
if %errorlevel% neq 0 (
    echo Error: Failed to compile application. Make sure MinGW is installed and in PATH.
    pause
    exit /b 1
)

echo.
echo Build successful! RawLinks.exe created in winapi directory.
echo To run the application, execute: winapi\RawLinks.exe
echo.
pause