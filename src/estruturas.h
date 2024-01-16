/**********************************************************************************************
 * Arquivo: estruturas.h
 * Descrição: arquivo de cabeçalho contendo as estruturas de dados utilizadas no programa.
 * Autores: Guilherme S., Matheus D.
 * 
 * Boa sorte!
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
// Definitions
//----------------------------------------------------------------------------------

// Constantes de tamanho das janelas
#define DISTANCE_BUTTONS_Y 50 // Distância entre os botões na vertical
#define DISTANCE_BUTTONS_X 10 // Distância entre os botões na horizontal
#define SIZE_BUTTONS_Y 170 // Tamanho dos botões na vertical
#define SIZE_MAIN_WINDOW_X 600 // Tamanho da janela principal na horizontal
#define SIZE_MAIN_WINDOW_Y 400 // Tamanho da janela principal na vertical
#define SIZE_SUB_WINDOW_X 400 // Tamanho da janela secundária na horizontal
#define SIZE_SUB_WINDOW_Y 300 // Tamanho da janela secundária na vertical
#define TAMANHO_LABEL_INSERT_Y 400 // Tamanho da label de inserção na vertical
#define MAIN_WINDOW_TITLE "Biblioteca - Sistema de Gerenciamento" // Título da janela principal

// Constantes dos botões da janela principal
#define ID_ADD_BOOK 101 // Adionar livro
#define ID_SEARCH_BOOK 102 // Pesquisar livro
#define ID_LOAN_BOOK 103 // Emprestar livro
#define ID_RENEW_LOAN 104 // Renovar emprestimo
#define ID_RETURN_BOOK 105 // Devolver livro
#define ID_ADD_EMPLOYEE 201 // Adicionar funcionário
#define ID_SEARCH_EMPLOYEE 202 // Pesquisar funcionário
#define ID_GENERATE_REPORT 301 // Gerar relatório
#define ID_CREATE_UNSORTED_DB 1 // Criar base de dados desordenada
#define ID_CREATE_SORTED_DB 2 // Criar base de dados ordenada
#define ID_RESET_DB 3 // Resetar base de dados
#define ID_INSERTION_SORT 4 // Ordenar por inserção
#define ID_INTERNAL_CLASSIFICATION 5 // Classificação interna
#define ID_BASIC_INTERCALATION 6 // Intercalação básica

// Constantes dos paths dos arquivos
#define EMPLOYEE_FILE_PATH "src/bin/window_employee.dat"
#define BOOK_FILE_PATH "src/bin/window_books.dat"
#define LOG_FILE_PATH "src/bin/window_log.dat"
#define PARTITIONS_PATH "src/bin/partitions"
#define PARTITIONS_PER_STRUCTS 100
int NUM_PARTITIONS;


// Typedefs para facilitar a manipulação de dados das estruturas
typedef char CPF[15];
typedef char NOME[50];
typedef char DATA[11];
typedef char NUMERO_PAGINAS[11];
typedef char AUTOR[50];
typedef char EDITORA[50];

//----------------------------------------------------------------------------------
// Structures Definition
//----------------------------------------------------------------------------------

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


//----------------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------------


void shuffle(int *vet, int size); // Função para embaralhar um vetor de inteiros

//----------------------------------------------------------------------------------
// Cliente Functions
//----------------------------------------------------------------------------------

TCliente *criar_cliente(char *nome, char *cpf); // Função para criar um cliente de acordo com a estrutura


//----------------------------------------------------------------------------------
// Employee Functions
//----------------------------------------------------------------------------------

TFunc *criar_funcionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario); // Função para criar um funcionário de acordo com a estrutura
TFunc *ler_arquivo_funcionario(FILE *in); // Função para ler um funcionário de um arquivo

int tamanho_registro_funcionario(); // Função para retornar o tamanho de um registro de funcionário
int tamanho_arquivo_de_funcionarios(FILE *arq); // Função para retornar o tamanho de um arquivo de funcionários
void salvar_funcionario(TFunc *func, FILE *out); // Função para salvar um funcionário em um arquivo
void criar_base_func_desordenada(FILE *out, int tam); // Função para criar uma base de funcionários desordenada
void criar_base_func_ordenada(FILE *out, int tam); // Função para criar uma base de funcionários ordenada
void imprimirBase_funcionarios(FILE *out); // Função para imprimir uma base de funcionários

//----------------------------------------------------------------------------------
// Book Functions
//----------------------------------------------------------------------------------

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


#endif // ESTRUTURAS_H
