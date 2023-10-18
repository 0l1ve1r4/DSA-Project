#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED

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
int tamanho_registro();

// Cria funcionario.
TFunc *funcionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario);


// Salva funcionario no arquivo out, na posicao atual do cursor
void salva(TFunc *func, FILE *out);


// Le um funcionario do arquivo in na posicao atual do cursor
// Retorna um ponteiro para funcionario lido do arquivo
TFunc *le(FILE *in);


// Imprime funcionario
void imprime(TFunc *func);


#endif // FUNCIONARIO_H_INCLUDED
