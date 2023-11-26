#ifndef WINDOW_EMPLOYEE_FUNCTIONS_H
#define WINDOW_EMPLOYEE_FUNCTIONS_H
#include "window_utils.h"

// Function declarations

//Windows para lidar com a impressão de Funcionarios que estarao armazenadas dinamicamente em uma estutura que pesquisada em um arquivo binario;
LRESULT CALLBACK Window_Print_Employee(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//Windows para lidar com a inserção de funcionarios no arquivo binario
LRESULT CALLBACK Window_Insert_Employee(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//Windows para lidar com a busca de funcionarios no arquivo binario
LRESULT CALLBACK Window_Search_Employee(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#endif // WINDOW_EMPLOYEE_FUNCTIONS_H
