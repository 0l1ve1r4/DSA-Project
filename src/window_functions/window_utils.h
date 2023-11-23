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


// Define constants
#define DISTANCE_BUTTONS_Y 50
#define DISTANCE_BUTTONS_X 10
#define SIZE_BUTTONS_Y 170
#define SIZE_MAIN_WINDOW_X 600
#define SIZE_MAIN_WINDOW_Y 400

// Define button IDs
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

void createButton(HWND hwnd, const char* text, int id, int x, int y);
void rmvBin();
void set_icon(HWND hwnd, char* path);
void removeExpandButton(HWND hwnd);


#endif 
