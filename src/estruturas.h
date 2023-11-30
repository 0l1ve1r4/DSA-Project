#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H
#include "configs.h"

/**
 * @param cod:int
 * @param nome:char[50]
 * @param cpf:char[15]
 * @param data_nascimento:char[11]
 * @param salario:float 
 */
typedef struct {
    int cod;
    char nome[50], 
    cpf[15], 
    data_nascimento[11];
    double salario;
} TFunc;

/**
 * @param nome:char[50]
 * @param cpf:char[15]
 */
typedef struct {
    char nome[50];
    char cpf[15];

} TCliente;

/**
 * @param cod:int
 * @param nome:char[50]
 * @param numero_paginas:char[11]
 * @param autor:char[50]
 * @param editora:char[50]
 * @param data_emprestimo:char[11]
 * @param preco:float
 * @param funcionario:TFunc
 * @param cliente:TCliente
 */
typedef struct {
    int cod;
    char nome[50], numero_paginas[11], 
    autor[50], 
    editora[50], 
    data_emprestimo[11];
    double preco;

    TFunc *funcionario;
    TCliente *cliente;

} TLivro;

/**
 * @brief Randomiza um vetor de inteiros de tamanho size.
 * 
 */
void shuffle(int *vet, int size);

/**
 * @brief Cria e um cliente com os dados fornecidos.
 * 
 * @return Retorna um ponteiro para uma estrutura criada
 */
TCliente *criar_cliente(char *nome, char *cpf);

//##############################################################################################################
// Funcoes de manipulacao de funcionarios

/**
 * @brief Retorna o tamanho do registro de um funcionário em bytes.
 * 
 * @return O tamanho do registro de um funcionário.
 */
int tamanho_registro_funcionario();

/**
 * @brief Cria e retorna um ponteiro para uma estrutura de funcionário com os dados fornecidos.
 * 
 * @param cod Código do funcionário.
 * @param nome Nome do funcionário.
 * @param cpf CPF do funcionário.
 * @param data_nascimento Data de nascimento do funcionário.
 * @param salario Salário do funcionário.
 * @return Um ponteiro para a estrutura de funcionário criada.
 */
TFunc *criar_funcionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario);

/**
 * @brief Salva a estrutura de um funcionário em um arquivo.
 * 
 * @param func Ponteiro para a estrutura de funcionário.
 * @param out Ponteiro para o arquivo de saída.
 */
void salvar_funcionario(TFunc *func, FILE *out);

/**
 * @brief Retorna o número de registros de funcionários em um arquivo.
 * 
 * @param arq Ponteiro para o arquivo de funcionários.
 * @return O número de registros de funcionários.
 */
int tamanho_arquivo_de_funcionarios(FILE *arq);

/**
 * @brief Lê um registro de funcionário de um arquivo e retorna a estrutura correspondente.
 * 
 * @param in Ponteiro para o arquivo de entrada.
 * @return Um ponteiro para a estrutura de funcionário lida.
 */
TFunc *ler_arquivo_funcionario(FILE *in);

/**
 * @brief Cria uma base de funcionários desordenada e a salva em um arquivo.
 * 
 * @param out Ponteiro para o arquivo de saída.
 * @param tam Tamanho da base de funcionários a ser criada.
 */
void criar_base_func_desordenada(FILE *out, int tam);

/**
 * @brief Cria uma base de funcionários ordenada e a salva em um arquivo.
 * 
 * @param out Ponteiro para o arquivo de saída.
 * @param tam Tamanho da base de funcionários a ser criada.
 */
void criar_base_func_ordenada(FILE *out, int tam);

/**
 * @brief Imprime no console todos os registros da base de funcionários contidos em um arquivo.
 * 
 * @param out Ponteiro para o arquivo de funcionários.
 */
void imprimirBase_funcionarios(FILE *out);


//##############################################################################################################
// Funcoes de manipulacao de livros

/**
 * @brief Retorna o tamanho do registro de um livro em bytes.
 * 
 * @return O tamanho do registro de um livro.
 */
int tamanho_registro_livro();

/**
 * @brief Cria e retorna um ponteiro para uma estrutura de livro com os dados fornecidos.
 * 
 * @param cod Código do livro.
 * @param nome Nome do livro.
 * @param numero_paginas Número de páginas do livro.
 * @param autor Autor do livro.
 * @param editora Editora do livro.
 * @param data_emprestimo Data de empréstimo do livro.
 * @param preco Preço do livro.
 * @param funcionario Ponteiro para a estrutura de funcionário associada ao livro.
 * @param cliente Ponteiro para a estrutura de cliente associada ao livro.
 * @return Um ponteiro para a estrutura de livro criada.
 */
TLivro *criar_livro(int cod, char *nome, char *numero_paginas, char *autor,
                    char *editora, char *data_emprestimo, double preco,
                    TFunc *funcionario, TCliente *cliente);

/**
 * @brief Salva a estrutura de um livro em um arquivo.
 * 
 * @param livro Ponteiro para a estrutura de livro.
 * @param out Ponteiro para o arquivo de saída.
 */
void salvar_livro(TLivro *livro, FILE *out);

/**
 * @brief Retorna o número de registros de livros em um arquivo.
 * 
 * @param arq Ponteiro para o arquivo de livros.
 * @return O número de registros de livros.
 */
int tamanho_arquivo_de_livros(FILE *arq);

/**
 * @brief Lê um registro de livro de um arquivo e retorna a estrutura correspondente.
 * 
 * @param in Ponteiro para o arquivo de entrada.
 * @return Um ponteiro para a estrutura de livro lida.
 */
TLivro *ler_arquivo_livro(FILE *in);

/**
 * @brief Imprime no console os detalhes de um livro.
 * 
 * @param livro Ponteiro para a estrutura de livro.
 */
void imprimir_livro(TLivro *livro);

/**
 * @brief Cria uma base de livros desordenada e a salva em um arquivo.
 * 
 * @param out Ponteiro para o arquivo de saída.
 * @param tam Tamanho da base de livros a ser criada.
 */
void criar_base_livros_desordenada(FILE *out, int tam);

/**
 * @brief Cria uma base de livros ordenada e a salva em um arquivo.
 * 
 * @param out Ponteiro para o arquivo de saída.
 * @param tam Tamanho da base de livros a ser criada.
 */
void criar_base_livros_ordenada(FILE *out, int tam);

/**
 * @brief Imprime no console todos os registros da base de livros contidos em um arquivo.
 * 
 * @param out Ponteiro para o arquivo de livros.
 */
void imprimirBase_livros(FILE *out);


#endif // ESTRUTURAS_H
