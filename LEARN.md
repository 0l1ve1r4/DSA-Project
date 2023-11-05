Data Structures & Algorithms II
This repository was built for the study of Algorithms and Data Structures II, demonstrating practically how file manipulation works in secondary memory using the C language. As an example, an application was created that provides a set of features for library administration. With the help of this system, you can oversee the control of literary copies, user management, publisher and employee records, and more.

Essential Requirements

Programming Language: [C] - The application was designed using the C programming language exclusively.

Database: [Custom Database] - The system uses a custom database that stores information in binary files located in the 'bin' folder.

Compiler: [Minimalist GNU for Windows] - The application was developed using MinGW as the compiler. To ensure the proper performance of the program and avoid potential bugs, it is highly recommended to INSTALL MinGW or GCC, as code corrections are based on specific compiler commands.

Other Dependencies: [Windows] - It's important to note that the program is exclusively compatible with the Windows operating system due to the use of a specific graphics library, <windows.h>.

Languages: [PT-BR/EN] - Currently, most of the program's functions are in English, but the messages displayed in the terminal are predominantly in Brazilian Portuguese.

Usage
To start using the Library Management System, follow these steps:

Compile the source code:

```shell 
gcc -o window ./src/*.c ./src/buscas/*.c ./windows_main.c
```

We are open to contributions and improvements in this project. If you want to contribute or suggest enhancements, please feel free to open issues, send pull requests, and collaborate in development.
