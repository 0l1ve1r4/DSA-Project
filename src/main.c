/**********************************************************************************************
 * File: main.c
 * Descriptions: File that initializes the program.
 * Authors: Guilherme Santos, Matheus Diniz.
 * 
 * Warnings:
 *  - Change the GUI variable to TRUE or FALSE to enable or disable the GUI.
**********************************************************************************************/

#include "estruturas.h"

int main() {
    printf("\033[H\033[J\nDebug: Iniciando o programa");

    if(GUI == TRUE) {
        printf("\nDebug: Iniciando a GUI");
        
        create_and_run_window(WindowProc_Main, 
        "Window_Main", MAIN_WINDOW_TITLE, 
        WS_OVERLAPPEDWINDOW, 0, 0, SIZE_MAIN_WINDOW_X, SIZE_MAIN_WINDOW_Y);
    }

    else if (GUI == FALSE) {
        printf("\nDebug: Iniciando o programa sem GUI");
        TerminalProc_Main();

    }

    else {
        printf("\nDebug: GUI nao definida");
        error_message("GUI nao definida", "Erro 404");
    }
}

