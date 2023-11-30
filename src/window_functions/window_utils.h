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

/**
 * @brief Cria um botão na janela.
 * 
 * @param hwnd Identificador da janela.
 * @param text Texto exibido no botão.
 * @param id Identificador do botão.
 * @param x Posição horizontal do botão.
 * @param y Posição vertical do botão.
 */
void createButton(HWND hwnd, const char* text, int id, int x, int y);

/**
 * @brief Remove os arquivos binários.
 */
void rmvBin();

/**
 * @brief Seta o ícone da janela.
 * 
 * @param hwnd Identificador da janela.
 * @param path Caminho para o arquivo de ícone.
 */
void set_icon(HWND hwnd, char* path);

/**
 * @brief Remove o botão de maximizar.
 * 
 * @param hwnd Identificador da janela.
 */
void removeExpandButton(HWND hwnd);

/**
 * @brief Cria um botão de input na janela.
 * 
 * @param hwnd Identificador da janela.
 * @param text Texto exibido no botão de input.
 * @param id Identificador do botão de input.
 * @param x Posição horizontal do botão de input.
 * @param y Posição vertical do botão de input.
 */
void createButton(HWND hwnd, const char* text, int id, int x, int y);

/**
 * @brief Cria um input de texto na janela.
 * 
 * @param hwnd Identificador da janela.
 * @param text Texto exibido no input de texto.
 * @param id Identificador do input de texto.
 * @param x Posição horizontal do input de texto.
 * @param y Posição vertical do input de texto.
 */
void create_Input_Label(HWND hwnd, const char* text, int id, int x, int y);

/**
 * @brief Cria um label estático na janela.
 * 
 * @param hwnd Identificador da janela.
 * @param text Texto exibido no label estático.
 * @param x Posição horizontal do label estático.
 * @param y Posição vertical do label estático.
 * @param width Largura do label estático.
 * @param height Altura do label estático.
 * @param id Identificador do label estático.
 */
void create_Static_Label(HWND hwnd, const char* text, int x, int y, int width, int height, int id);

/**
 * @brief Exibe uma mensagem de erro.
 * 
 * @param message Mensagem de erro.
 * @param title Título da janela de erro.
 */
void error_message(char* message, char* title);

/**
 * @brief Oculta a janela do console.
 */
void hideConsoleWindow();

/**
 * @brief Exibe uma mensagem de confirmação.
 * 
 * @param message Mensagem de confirmação.
 * @param title Título da janela de confirmação.
 * @return Um valor indicando a escolha do usuário (por exemplo, IDYES ou IDNO).
 */
int confirm_message(char* message, char* title);

/**
 * @brief Cria e executa uma janela.
 * 
 * @param wndProc Procedimento da janela.
 * @param className Nome da classe da janela.
 * @param windowTitle Título da janela.
 * @param windowStyle Estilo da janela.
 * @param x Posição horizontal da janela.
 * @param y Posição vertical da janela.
 * @param width Largura da janela.
 * @param height Altura da janela.
 * @return Identificador da janela criada.
 */
HWND create_and_run_window(WNDPROC wndProc, const char* className, const char* windowTitle, DWORD windowStyle, int x, int y, int width, int height);

#endif 
