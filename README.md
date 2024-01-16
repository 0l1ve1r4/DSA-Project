# Data Structures & Algorithms II - Library Management

[![pt-br](https://img.shields.io/badge/lang-pt--br-green.svg)](https://github.com/devYaksha/DSA-Project/blob/main/assets/readme/README.pt-br.md)
[![en](https://img.shields.io/badge/lang-en-red.svg)](https://github.com/devYaksha/DSA-Project/blob/main/README.md)

This repository is intended for students studying **Algorithms and Data Structures II**, offering a practical approach to manipulating files in secondary memory using the C language.

<img src="assets/readme/MAIN_WINDOW.png" alt="Window">

#### Latest Documentation Update: `15/01/2023`

## Summary

1. [Requirements](#Requirements)
2. [How to Use/Install](#Use)
3. [Contribution](#Contribution)

## Requirements

To successfully implement this project, you need the following technologies and tools configured:

- **Programming Language:** [C] - The project was developed exclusively in C.

- **Database:** [Custom Database] - Uses a custom database stored in binary files in the 'bin' folder.

- **Compiler:** [Minimalist GNU for Windows] - Developed using MinGW as compiler. We recommend [installing](https://terminalroot.com.br/2022/12/como-instalar-gcc-gpp-mingw-no-windows.html) MinGW or GCC to ensure adequate performance and avoid bugs, as the fixes are based on specific compiler commands.

- **Operating System:** [Windows] - Exclusively compatible with Windows due to the use of the *<windows.h>* graphics library.

## Use

### Common Usage

To get started using the Library Management System, follow these steps:

1. Compile the source code directly via bat (inside the repository directory):

```command prompt 
./compile.bat
```
2. This will compile all .c files in the directory, then run the main program using the following command:
````command prompt
./window.exe
````
### Own/Modified Use

If you want to make modifications to the project so that it only works via the terminal, I recommend that you follow these steps to avoid bugs:

1. Create your *main* file inside `src/`;

2. After making all the desired modifications to your program, according to the necessary logic:

3. (You can also change compile.bat to make the repetitive process easier)

**Note** If there are bugs in the compilation, you can delete all window handling files and folders, namely:
- `./windows_main.c`
- `./src/window_functions`

## Source-Code

Don't worry, in the `./src` folder, you will find everything documented in the headers, happy reading!

#### General observations:

- Each script is independent and contains its own specific windows and functionality.
- Careful handling of files and validation of user input are important considerations, and their implementations are in `/src/estruturas.c`
- Scripts can be compiled separately, and their functionality can be integrated as needed.


## Contribution

We are open to contributions and improvements to this project. If you want to contribute or suggest improvements, feel free to open issues, submit pull requests, and collaborate on development.
