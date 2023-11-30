@echo off

:: Set the output executable name
set output_executable=window

:: Compile the code
gcc -o %output_executable% .\src\*.c .\src\buscas\*.c .\src\metodos_ordenacao\*.c .\src\window_functions\*.c .\win_main.c

:: Check if compilation was successful
if %errorlevel% equ 0 (
  echo Compilation successful. Executable: %output_executable%
) else (
  echo Compilation failed.
)
