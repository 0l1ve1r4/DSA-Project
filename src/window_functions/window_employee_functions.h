#ifndef WINDOW_EMPLOYEE_FUNCTIONS_H
#define WINDOW_EMPLOYEE_FUNCTIONS_H
#include "window_utils.h"

// Function declarations
LRESULT CALLBACK Window_Print_Employee(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int print_Employee();
LRESULT CALLBACK Window_Insert_Employee(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int insert_employee();
LRESULT CALLBACK Window_Search_Employee(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int search_employee();


#endif // WINDOW_EMPLOYEE_FUNCTIONS_H
