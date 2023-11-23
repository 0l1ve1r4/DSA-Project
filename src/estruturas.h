#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Definição da estrutura para o registro de um funcionário
typedef struct {
    int cod;
    char nome[50], 
    cpf[15], 
    data_nascimento[11];
    double salario;
} TFunc;

// Definição da estrutura para o registro de um livro
typedef struct {
    int cod;
    char nome[50], numero_paginas[11], 
    autor[50], 
    editora[50], 
    data_emprestimo[11];
    double preco;
} TLivro;

// Definição da estrutura para o registro de um cliente
typedef struct {
    char nome[50];
    char cpf[15];

} TCliente;

// Função para calcular o tamanho total de um registro de funcionário
int tamanho_registro_funcionario();

// Função para criar e preencher um registro de funcionário
TFunc *criar_funcionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario);

// Função para escrever os detalhes de um funcionário em um arquivo binário
void salvar_funcionario(TFunc *func, FILE *out);

// Função para calcular o número de registros de funcionários em um arquivo
int tamanho_arquivo_de_funcionarios(FILE *arq);

// Função para ler um registro de funcionário de um arquivo binário
TFunc *ler_arquivo_funcionario(FILE *in);

// Função para imprimir os detalhes de um funcionário na saída padrão
void imprimir_funcionario(TFunc *func);

// Função para criar uma base de dados de funcionários
void criarBase_funcionarios(FILE *out, int tam);

// Função para embaralhar códigos de funcionários
void shuffle_funcionarios(int *vet, int MAX);

// Função para ler e imprimir registros de funcionários em um arquivo
void imprimirBase_funcionarios(FILE *out);

// Função para calcular o tamanho total de um registro de livro
int tamanho_registro_livro();

// Função para criar e preencher um registro de livro
TLivro *criar_livro(int cod, char *nome, char *numero_paginas, char *autor, char *editora, char *data_emprestimo, double preco);

// Função para escrever os detalhes de um livro em um arquivo binário
void salvar_livro(TLivro *livro, FILE *out);

// Função para calcular o número de registros de livros em um arquivo
int tamanho_arquivo_de_livros(FILE *arq);

// Função para ler um registro de livro de um arquivo binário
TLivro *ler_arquivo_livro(FILE *in);

// Função para imprimir os detalhes de um livro na saída padrão
void imprimir_livro(TLivro *livro);

// Função para criar uma base de dados de livros
void criarBase_livros(FILE *out, int tam);

// Função para embaralhar códigos de livros
void shuffle_livros(int *vet, int MAX);

// Função para ler e imprimir registros de livros em um arquivo
void imprimirBase_livros(FILE *out);

#endif // ESTRUTURAS_H
