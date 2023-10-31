#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Funcionario {
    int cod;
    char nome[50];
    char cpf[15];
    char data_nascimento[11];
    double salario;
} TFunc;


// Retorna tamanho do funcionario em bytes
int tamanho_registro_funcionario();

// Cria funcionario.
TFunc *criar_funcionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario);


// Salva funcionario no arquivo out, na posicao atual do cursor
void salvar_funcionario(TFunc *func, FILE *out);


// retorna a quantidade de registros no arquivo
int tamanho_arquivo_de_funcionarios(FILE *arq);


// Le um funcionario do arquivo in na posicao atual do cursor
// Retorna um ponteiro para funcionario lido do arquivo
TFunc *ler_arquivo_funcionario(FILE *in);


// Imprime funcionario
void imprimir_funcionario(TFunc *func);


// Cria a base de dados
void criarBase_funcionarios(FILE *out, int tam);

//embaralha base de dados
void shuffle_funcionarios(int *vet,int MAX,int MIN);

// Imprime a base de dados
void imprimirBase_funcionarios(FILE *out);


#endif // EMPLOYEE_H
