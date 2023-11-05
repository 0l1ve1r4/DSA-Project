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


/*  Esta função calcula o tamanho total em bytes de um registro de funcionário. 
Isso é feito somando os tamanhos das várias partes do registro, como código (int), 
nome (string), CPF (string), data de nascimento (string) e salário (double).*/
int tamanho_registro_funcionario();

/* Esta função aloca dinamicamente memória para um novo registro de funcionário (TFunc),
e preenche os campos com os valores passados como argumento.*/
TFunc *criar_funcionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario);

/* Esta função escreve os detalhes de um funcionário em um arquivo fornecido (out) 
em um formato binário. Ela usa fwrite para escrever cada parte do registro.*/
void salvar_funcionario(TFunc *func, FILE *out);

/* Esta função calcula o número de registros de funcionários em um arquivo fornecido, 
dividindo o tamanho do arquivo pelo tamanho de um único registro de funcionário.*/
int tamanho_arquivo_de_funcionarios(FILE *arq);

/* Essa função lê um registro de funcionário de um arquivo em formato binário, 
alocando memória para um novo TFunc e preenchendo seus campos com os valores lidos do arquivo*/
TFunc *ler_arquivo_funcionario(FILE *in);

/*Essa função imprime os detalhes de um funcionário na saída padrão. 
Ela usa printf para formatar e exibir as informações.*/
void imprimir_funcionario(TFunc *func);

/*Essa função cria uma base de dados de funcionários, gerando registros com códigos 
sequenciais e informações padrão ("XXXXXXXXXX", "000.000.000-00", "00/00/0000", 0).
 Ela também utiliza a função shuffle_funcionarios para embaralhar os códigos dos funcionários.*/
void criarBase_funcionarios(FILE *out, int tam);

/*Sem shuffle para Binários*/
void criarBase_funcionarios_Binario(FILE *out, int tam);

/*Essa função embaralha um vetor de códigos de funcionários, randomizando a ordem dos códigos.*/
void shuffle_funcionarios(int *vet,int MAX);


/*Esta função lê e imprime todos os registros de funcionários em um arquivo, 
usando a função ler_arquivo_funcionario e imprimir_funcionario.*/
void imprimirBase_funcionarios(FILE *out);


#endif // FUNCIONARIO_H
