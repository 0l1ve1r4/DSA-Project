@echo off

:: Set the output executable name
set output_executable=library-system
cls

:: Compile the code using gcc and redirect the output to a file
gcc -o %output_executable% .\src\*.c .\src\buscas\*.c .\src\metodos_ordenacao\*.c .\src\window_functions\*.c -lgdi32 >> output.log 2>&1

:: Check if compilation was successful
if %errorlevel% equ 0 (
  echo Compilation successful. Executable: %output_executable%
  
  :: Remove the output.log file if compilation was successful
  if exist output.log del output.log
) else (
  echo Compilation failed. Check output.log for details.
)
