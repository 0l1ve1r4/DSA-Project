/**********************************************************************************************
 * File: main.c
 * Descriptions: File that initializes the program.
 * Authors: Guilherme Santos, Matheus Diniz.
 * 
 * Warnings:
 *  - Change the GUI variable to TRUE or FALSE to enable or disable the GUI.
**********************************************************************************************/

#include "estruturas.h"
#define GUI TRUE // Change this to TRUE to enable the GUI or FALSE to disable it.

int main() {
    printf("\033[H\033[J\n");

    if(GUI == TRUE) {
        printf("\n[+] Debug: Iniciando a GUI");
        
        create_and_run_window(WindowProc_Main, 
        "Window_Main", MAIN_WINDOW_TITLE, 
        WS_OVERLAPPEDWINDOW, 0, 0, SIZE_MAIN_WINDOW_X, SIZE_MAIN_WINDOW_Y);
    }

    else if (GUI == FALSE) {
        printf("\n[+] Debug: Iniciando o programa sem GUI");
        TerminalProc_Main();

    }

    else {
        printf("\n[+] Debug: GUI nao definida");
        error_message("GUI nao definida", "Erro 404");
    }
}

