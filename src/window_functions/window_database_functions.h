#ifndef WINDOW_DATABASE_FUNCTIONS_H
#define WINDOW_DATABASE_FUNCTIONS_H
#include "window_utils.h"

LRESULT CALLBACK Window_Unsorted_DataBase_Search(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int Window_Unsorted_DataBase();

LRESULT CALLBACK Window_Sorted_DataBase_Search(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int Window_Sorted_DataBase();


#endif // WINDOW_DATABASE_FUNCTIONS_H
