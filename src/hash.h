#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <stdio.h>
#include <time.h> //uso e manipulação do tipo tempo
#include <stdlib.h>
#include <string.h> //uso e manipulação de strings

//Estrutura para criar uma base de dados de funcionários
typedef struct Funcionariooo {
    int id;
    char nome[50];
    char cpf[15];
    char dataNiver[11];
    double salario;
} TFunccc;

//Função para salvar o registro de um funcionário
void salvarFuncionario(TFunccc *func, FILE *out);

//Função para criar uma Database de funcionários
void criarArquivo(FILE *arq, int nFunc, int *vet);

//Função para ler o registro de um funcionário
TFunccc *lerFuncionario(FILE *in);

//Função para imprimir o registro de um funcionário
void imprimirFuncionario (TFunccc *func);

//Função para imprimir a database de funcionários
void imprimirArquivoFuncionario(FILE *file);

//Função que retorna o tamanho do arquivo
int tamanhoArquivo(FILE *file, int contSizeFile);

//Função que imprime partições realizadas
void imprimeParticao(FILE *file, char partitionName[]);

//Método da tabela Hash
void hashTable(FILE *file, int numberOfPartition, int sizeFile);

//Função para deletar funcionário na tabela hash
void deletar_hash(int employerID, int partitionID);

//Função para inserir funcionário na tabela hash
void inserir_hash(TFunccc*funcHashTableInsert,int employerID, int partitionID);

//Função para particionar tabela hash
void particao_hash(int numberOfPartition);

//Função de busca em uma tabela hash
TFunccc *busca_hash(int employerID, int partitionID);

//Função que verifica o vetor de tamanho 6
int percorreVetor(int vet[6]);

//Função para embaralhar com vetor limitado de tamanho 6
void embaralharVetor(int *vet, int vetSize);

//Função que realiza a Seleção por Substituição
int selecaoSubstituicao (FILE *file, char nameFilePartition[]);

//Método para Intercalacao Otima
void intercalacaoOtima(int numberOfPartition, char nameFilePartition[]);



#endif