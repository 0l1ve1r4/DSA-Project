#ifndef WINDOW_UTILS_H
#define WINDOW_UTILS_H
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../estruturas.h"
#include "../buscas/buscas_binarias.h"
#include "../metodos_ordenacao/insertionSort.h"
#include "../buscas/buscas_sequenciais.h"
#include "window_database_functions.h"
#include "window_book_functions.h"
#include "window_employee_functions.h"

//constantes
#define DISTANCE_BUTTONS_Y 50
#define DISTANCE_BUTTONS_X 10
#define SIZE_BUTTONS_Y 170
#define SIZE_MAIN_WINDOW_X 600
#define SIZE_MAIN_WINDOW_Y 400
#define SIZE_SUB_WINDOW_X 400
#define SIZE_SUB_WINDOW_Y 300

// buttons IDs
#define ID_ADD_BOOK 101
#define ID_SEARCH_BOOK 102
#define ID_LOAN_BOOK 103
#define ID_RENEW_LOAN 104
#define ID_RETURN_BOOK 105
#define ID_ADD_EMPLOYEE 201
#define ID_SEARCH_EMPLOYEE 202
#define ID_GENERATE_REPORT 301
#define ID_CREATE_UNSORTED_DB 1
#define ID_CREATE_SORTED_DB 2
#define ID_RESET_DB 3

// Cria um botão na janela
void createButton(HWND hwnd, const char* text, int id, int x, int y);

//Remove os arquivos binários
void rmvBin();

// Seta o icone da janela
void set_icon(HWND hwnd, char* path);

// Remove o botão de maximizar
void removeExpandButton(HWND hwnd);

// Cria um Botão de input
void createButton(HWND hwnd, const char* text, int id, int x, int y);

// Cria um input de texto
void create_Input_Label(HWND hwnd, const char* text, int id, int x, int y);

// Cria um label estático
void create_Static_Label(HWND hwnd, const char* text, int x, int y, int width, int height, int id);

// Exatamente o que o nome diz :-)
void error_message(char* message, char* title);

void hideConsoleWindow();

int confirm_message(char* message, char* title);

HWND create_and_run_window(WNDPROC wndProc, const char* className, const char* windowTitle, DWORD windowStyle, int x, int y, int width, int height);

#endif 
