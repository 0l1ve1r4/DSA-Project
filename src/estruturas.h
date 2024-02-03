/**********************************************************************************************
 * File: estruturas.h
 * Descriptions: File with all the structures and functions used in the project.
 * Authors: Guilherme Santos, Matheus Diniz.
 * 
 * Warnings:
 * This program uses the Windows API. It will not compile on Linux or Mac OS.
 * 
 * Bugs Kwown:
 * [1]. The program will not compile if the user does not have the MinGW compiler installed.
 * [2]. The program will not compile if the user does not have the Windows API installed.
 * [3]. The program will not run properly if the ./src/bin folder does not exist.
 * [4]. Some functions will not run properly if the ./src/bin/partitions folder does not exist.
 * [5]. Sometimes, the Internal Classification function will not run properly and can create infinity partitions.
 * [6]. Sometimes, when you create a book or employee, the program will not show the new data in the database.
 * 
 * 
 * 
**********************************************************************************************/

#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

//----------------------------------------------------------------------------------
// Default Libraries
//----------------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>
#include <windows.h>

//----------------------------------------------------------------------------------
// Basic Definitions
//----------------------------------------------------------------------------------

#define TRUE 1    // simple boolean
#define FALSE 0   // simple boolean
#define TABLE_SIZE 13 // hash table divisor

// Constantes dos paths dos arquivos ** NÃO ALTERAR, PODERÁ OCASIONAR ERROS ** 
#define EMPLOYEE_FILE_PATH "src/bin/window_employee.dat" // Path do arquivo de funcionários
#define BOOK_FILE_PATH "src/bin/window_books.dat" // Path do arquivo de livros
#define LOG_FILE_PATH "src/bin/window_log.dat" // Path do arquivo de log
#define PARTITIONS_PATH "src/bin/partitions" // Path das partições de funcionários e livros
#define HASH_TABLE_PATH "src/bin/hashTable.dat" // Path da tabela hash
#define PARTITIONS_PER_STRUCTS 100 // Número de partições que serão criadas para cada partições de funcionários e livros	

int NUM_PARTITIONS; // Número de partições que foram criadas para o for da intercalação ótima

// Typedefs para facilitar a manipulação de dados das estruturas. 
// Recomendação: não alterar. Caso for, deixe em bases de potência de 2 preferencialmente maiores que as atuais.
typedef char NUMERO_PAGINAS[8]; // struct TLivro 
typedef char CPF[16]; // struct TFunc e struct TCliente
typedef char DATA[16]; // struct TFunc e struct TLivro
typedef char NOME[32]; // struct TFunc e struct TLivro, struct TCliente
typedef char AUTOR[32]; // struct TLivro
typedef char EDITORA[32]; // struct TLivro


//----------------------------------------------------------------------------------
// Structures Definition
//----------------------------------------------------------------------------------

// Enum para facilitar a manipulação de dados das estruturas em funções genéricas
typedef enum {
    FUNCIONARIO, 
    LIVRO,
    CLIENTE 
} TipoRegistro;

typedef struct {
    int cod;    
    NOME nome;
    CPF cpf;
    DATA data_nascimento;  
    double salario;
} TFunc;

typedef struct {
    NOME nome;
    CPF cpf;
} TCliente;

typedef struct {
    int cod;
    NOME nome;
    NUMERO_PAGINAS numero_paginas;
    AUTOR autor; 
    EDITORA editora; 
    DATA data_emprestimo;  
    double preco;

    TFunc *funcionario;
    TCliente *cliente;
} TLivro;

typedef struct{
    float tempo;
    int num_registro_per_partition;
    int num_partitions;
} classificacao_struct;

typedef struct{

    float tempo;
    int num_registro_per_partition;
    int num_partitions;
} intercalacao_otima_struct;

typedef struct LogFileBinary{
    int iteracoes;
    double tempo_ms;
} TLogBinary;

typedef struct LogFile{
    int iteracoes;
    double tempo_ms;
} TLog;

// Nó para a lista encadeada
typedef struct Node {
    int key;
    TLivro livro;
    struct Node *next;
} Node;

// Tabela Hash
typedef struct HashTable {
    Node *table[TABLE_SIZE];
} HashTable;


/***********************************************************************************
 * Generic Functions
 * 
 * Funções genéricas para manipulação de dados das estruturas.
 * 
***********************************************************************************/

void shuffle(int *vet, int size); // Função para embaralhar um vetor de inteiros
void TerminalProc_Main(); // Função para rodar o programa sem a GUI

/***********************************************************************************
 *                          Hash Functions
 * 
 * A função hash adotada é uma função hash INTERNA. 
 * A key é o módulo da chave pelo tamanho da tabela (key % TABLE_SIZE).
 * 
 * Ao tratamento de colisões, foi utilizada a técnica de encadeamento.
 * Quando ocorre uma colisão, o novo registro é adicionado à lista encadeada. 
 * As operações de busca, inserção e remoção percorrem a lista encadeada 
 * na posição correspondente para encontrar o registro desejado.
 * O(1) no caso médio. O(n) no pior caso. 
 * 
***********************************************************************************/

int hash(int key);
void insert_hash(HashTable *ht, int key, TLivro livro);
TLivro search_hash(HashTable *ht, int key);
void remove_hash(HashTable *ht, int key);
void saveHashTable(HashTable *ht);
HashTable *loadHashTable();
void printLivroInfo(TLivro livro);
HashTable *createHashTable();

#define MY_HASH_TABLE_SIZE 10
HashTable *myHashTable;


/***********************************************************************************
 * Client Functions
 * 
***********************************************************************************/

TCliente *criar_cliente(char *nome, char *cpf); // Função para criar um cliente de acordo com a estrutura

/***********************************************************************************
 * Employee Functions
 * 
***********************************************************************************/

TFunc *criar_funcionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario); // Função para criar um funcionário de acordo com a estrutura
TFunc *ler_arquivo_funcionario(FILE *in); // Função para ler um funcionário de um arquivo
int tamanho_registro_funcionario(); // Função para retornar o tamanho de um registro de funcionário
int tamanho_arquivo_de_funcionarios(FILE *arq); // Função para retornar o tamanho de um arquivo de funcionários
void salvar_funcionario(TFunc *func, FILE *out); // Função para salvar um funcionário em um arquivo
void criar_base_func_desordenada(FILE *out, int tam); // Função para criar uma base de funcionários desordenada
void criar_base_func_ordenada(FILE *out, int tam); // Função para criar uma base de funcionários ordenada
void imprimirBase_funcionarios(FILE *out); // Função para imprimir uma base de funcionários

/***********************************************************************************
 * Book Functions
 * 
***********************************************************************************/

TLivro *criar_livro(int cod, char *nome, char *numero_paginas, char *autor,
                    char *editora, char *data_emprestimo, double preco,     // Função para criar um livro de acordo com a estrutura
                    TFunc *funcionario, TCliente *cliente);
TLivro *ler_arquivo_livro(FILE *in); // Função para ler um livro de um arquivo
int tamanho_arquivo_de_livros(FILE *arq); // Função para retornar o tamanho de um arquivo de livros
int tamanho_registro_livro(); // Função para retornar o tamanho de um registro de livro
void salvar_livro(TLivro *livro, FILE *out); // Função para salvar um livro em um arquivo
void imprimir_livro(TLivro *livro); // Função para imprimir um livro
void criar_base_livros_desordenada(FILE *out, int tam); // Função para criar uma base de livros desordenada
void criar_base_livros_ordenada(FILE *out, int tam);     // Função para criar uma base de livros ordenada
void imprimirBase_livros(FILE *out); // Função para imprimir uma base de livros

/***********************************************************************************
 * Classication Functions
 * 
***********************************************************************************/

int classificacao_interna_Func(int M); 
int classificacao_interna_Livro(int M);
void classificacoes(int M);

/***********************************************************************************
 * Intercalation Functions
 * 
***********************************************************************************/

int compare_records(const void *a, const void *b, TipoRegistro tipo);
intercalacao_otima_struct* save_intercalacao_otima_struct(int num_partitions, int num_registro_per_partition, float tempo);
void intercalacao_otima_Func();
void intercalacao_otima_Livro();
void intercalacoes_otimas();

/***********************************************************************************
 * Quick Sort Functions
 * 
***********************************************************************************/

void quicksort_employees(FILE *arq, int tam);
void quicksort_books(FILE *arq, int tam);
void quicksort_both();
void printLivroCodes(FILE *arq, int tam);

/***********************************************************************************
 * Binary Search Functions
 * 
***********************************************************************************/

int criar_base_ordenada(FILE *employeeFileBinary, FILE *bookFileBinary, FILE *LogFileBinary, int tamanho_base);
int criar_base_desordenada(FILE *employeeFileBinary, FILE *bookFileBinary, FILE *LogFileBinary, int tamanho_base);
TFunc *buscarFuncionario_binariamente(int chave, FILE *arquivo, int tam, FILE *LogFileBinary);
TLivro *buscarLivro_binariamente(int chave, FILE *arquivo, int tam, FILE *LogFileBinary);
void salvar_log_file_binary(FILE *out, int iteracoes, double tempo_ms);

/***********************************************************************************
 * Sequential Search Functions
 * 
***********************************************************************************/

TFunc *buscarFuncionario_sequencialmente(FILE *arquivo, int codigo, FILE *logFile);
TLivro *buscarLivro_sequencialmente(FILE *arquivo, int codigo, FILE *logFile);
void bases_buscas_sequenciais(FILE *employeeFile, FILE *bookFile, FILE *logFile, int tamanho_base);
void salvar_log_file(FILE *out, int iteracoes, double tempo_ms);

/***********************************************************************************
 * Window Functions
 * 
 * Here are the functions that will be used in the GUI.
 * The functions use windows.h to create and manage the windows.
 * 
 * The functions are divided into:
 * - The first part is the constants and macros of the main window.
 * - The second part is the constants and macros of the sub windows.
 * - The third part is the macros of parameters 
 * - The fourth part is the main window functions.
 * - The fifth part is the sub window functions.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Good luck!
***********************************************************************************/

// Constants of the MAIN WINDOW 
#define MAIN_WINDOW_TITLE "Library Management System" // Title of the main window
#define DISTANCE_BUTTONS_Y 50 
#define DISTANCE_BUTTONS_X 10 
#define SIZE_BUTTONS_Y 170 
#define SIZE_MAIN_WINDOW_X 600 
#define SIZE_MAIN_WINDOW_Y 520

#define ID_ADD_BOOK 101 
#define ADD_BOOK_TEXT "Add new book" 
#define ID_SEARCH_BOOK 102 
#define SEARCH_BOOK_TEXT "Search Book"  
#define ID_LOAN_BOOK 103 
#define LOAN_BOOK_TEXT "Loan book" 
#define ID_RENEW_LOAN 104 
#define RENEW_LOAN_TEXT "Renew loan" 
#define ID_RETURN_BOOK 105
#define ID_ADD_IN_HASH_TABLE 106
#define ADD_IN_HASH_TABLE_TEXT "Add in hash table"
#define ID_REMOVE_IN_HASH_TABLE 107
#define REMOVE_IN_HASH_TABLE_TEXT "Remove in hash table"
#define ID_SEARCH_IN_HASH_TABLE 108
#define SEARCH_IN_HASH_TABLE_TEXT "Search in hash table" 

#define RETURN_BOOK_TEXT "Return book" 
#define ID_ADD_EMPLOYEE 201 
#define ADD_EMPLOYEE_TEXT "Add new employee" 
#define ID_SEARCH_EMPLOYEE 202 
#define SEARCH_EMPLOYEE_TEXT "Search employee" 
#define ID_GENERATE_REPORT 301 

#define GENERATE_REPORT_TEXT "Generate report" 
#define ID_CREATE_UNSORTED_DB 1 
#define CREATE_UNSORTED_DB_TEXT "Create unsorted database" 
#define ID_CREATE_SORTED_DB 2 
#define CREATE_SORTED_DB_TEXT "Create sorted database" 
#define ID_RESET_DB 3 
#define RESET_DB_TEXT "Reset database" 
#define ID_INSERTION_SORT 4 
#define INSERTION_SORT_TEXT "Insertion sort" 
#define ID_INTERNAL_CLASSIFICATION 5 
#define INTERNAL_CLASSIFICATION_TEXT "Internal classification" 
#define ID_BASIC_INTERCALATION 6 
#define BASIC_INTERCALATION_TEXT "Basic intercalation"

// Constants of the SUB WINDOWS
#define SIZE_SUB_WINDOW_X 400 
#define SIZE_SUB_WINDOW_Y 300 
#define TAMANHO_LABEL_INSERT_Y 400 

// Functions constants and macros
#define NEW_WINDOW LRESULT CALLBACK // Definição de função de janela
#define WINDOW_PARAMS HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam // Parâmetros de função de janela
#define CREATE_BUTTON(hwnd, buttonText, buttonID, posX, posY) createButton(hwnd, buttonText, buttonID, DISTANCE_BUTTONS_X * posX, DISTANCE_BUTTONS_Y * posY)

#define CREATE_BOOK_BUTTON(hwnd) CREATE_BUTTON(hwnd, ADD_BOOK_TEXT, ID_ADD_BOOK, 1, 1)
#define SEARCH_BOOK_BUTTON(hwnd) CREATE_BUTTON(hwnd, SEARCH_BOOK_TEXT, ID_SEARCH_BOOK, 1, 2)
#define LOAN_BOOK_BUTTON(hwnd) CREATE_BUTTON(hwnd, LOAN_BOOK_TEXT, ID_LOAN_BOOK, 1, 3)
#define RETURN_BOOK_BUTTON(hwnd) CREATE_BUTTON(hwnd, RETURN_BOOK_TEXT, ID_RETURN_BOOK, 1, 4)
#define ADD_IN_HASH_TABLE_BUTTON(hwnd) CREATE_BUTTON(hwnd, ADD_IN_HASH_TABLE_TEXT, ID_ADD_IN_HASH_TABLE, 1, 5)
#define REMOVE_IN_HASH_TABLE_BUTTON(hwnd) CREATE_BUTTON(hwnd, REMOVE_IN_HASH_TABLE_TEXT, ID_REMOVE_IN_HASH_TABLE, 1, 6)
#define SEARCH_IN_HASH_TABLE_BUTTON(hwnd) CREATE_BUTTON(hwnd, SEARCH_IN_HASH_TABLE_TEXT, ID_SEARCH_IN_HASH_TABLE, 1, 7)

#define ADD_EMPLOYEE_BUTTON(hwnd) CREATE_BUTTON(hwnd, ADD_EMPLOYEE_TEXT, ID_ADD_EMPLOYEE, 20, 1)
#define SEARCH_EMPLOYEE_BUTTON(hwnd) CREATE_BUTTON(hwnd, SEARCH_EMPLOYEE_TEXT, ID_SEARCH_EMPLOYEE, 20, 2)
#define RESET_DB_BUTTON(hwnd) CREATE_BUTTON(hwnd, RESET_DB_TEXT, ID_RESET_DB, 20, 3)
#define CREATE_SORTED_DB_BUTTON(hwnd) CREATE_BUTTON(hwnd, CREATE_SORTED_DB_TEXT, ID_CREATE_SORTED_DB, 40, 1)
#define CREATE_UNSORTED_DB_BUTTON(hwnd) CREATE_BUTTON(hwnd, CREATE_UNSORTED_DB_TEXT, ID_CREATE_UNSORTED_DB, 40, 2)
#define INSERTION_SORT_BUTTON(hwnd) CREATE_BUTTON(hwnd, INSERTION_SORT_TEXT, ID_INSERTION_SORT, 40, 3)
#define INTERNAL_CLASSIFICATION_BUTTON(hwnd) CREATE_BUTTON(hwnd, INTERNAL_CLASSIFICATION_TEXT, ID_INTERNAL_CLASSIFICATION, 40, 4)
#define BASIC_INTERCALATION_BUTTON(hwnd) CREATE_BUTTON(hwnd, BASIC_INTERCALATION_TEXT, ID_BASIC_INTERCALATION, 40, 5)

#define CREDITS_LABEL(hwnd) (void)create_Static_Label(hwnd, "Developed by Guilherme Santos and Matheus Diniz", 0, 450, 600, 50, 0)

// Utilitários
int confirm_message(char* message, char* title);

HWND create_and_run_window(WNDPROC wndProc, const char* className, const char* windowTitle, DWORD windowStyle, int x, int y, int width, int height);

void createButton(HWND hwnd, const char* text, int id, int x, int y);
void rmvBin();
void set_icon(HWND hwnd, char* path);
void removeExpandButton(HWND hwnd);
void createButton(HWND hwnd, const char* text, int id, int x, int y);
void create_Input_Label(HWND hwnd, const char* text, int id, int x, int y);
void create_Static_Label(HWND hwnd, const char* text, int x, int y, int width, int height, int id);
void error_message(char* message, char* title);
void hideConsoleWindow();

// Window book functions
NEW_WINDOW Window_Print_Book(WINDOW_PARAMS);
NEW_WINDOW Window_Insert_Book(WINDOW_PARAMS);
NEW_WINDOW Window_Search_Book(WINDOW_PARAMS);
NEW_WINDOW Windwow_Loan_book(WINDOW_PARAMS);
NEW_WINDOW Window_return_book(WINDOW_PARAMS);
NEW_WINDOW Window_delete_book(WINDOW_PARAMS);

// Database functions
NEW_WINDOW Window_Unsorted_DataBase_Search(WINDOW_PARAMS);
NEW_WINDOW Window_Sorted_DataBase_Search(WINDOW_PARAMS);

// Window employee functions
NEW_WINDOW Window_Print_Employee(WINDOW_PARAMS);
NEW_WINDOW Window_Insert_Employee(WINDOW_PARAMS);
NEW_WINDOW Window_Search_Employee(WINDOW_PARAMS);

// Window main functions
NEW_WINDOW WindowProc_Main(WINDOW_PARAMS);

// Window HASH functions
NEW_WINDOW Window_Insert_Hash(WINDOW_PARAMS);
NEW_WINDOW Window_Search_Hash(WINDOW_PARAMS);
NEW_WINDOW Window_Delete_Hash(WINDOW_PARAMS);
NEW_WINDOW Window_Print_Hash(WINDOW_PARAMS);

#endif // ESTRUTURAS_H
