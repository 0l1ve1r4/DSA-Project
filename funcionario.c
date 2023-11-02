#include "funcionario.h"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int tamanho_registro_funcionario() {
    TFunc *temp;
    return sizeof(temp->cod) 
           + sizeof(temp->nome) 
           + sizeof(temp->cpf) 
           + sizeof(temp->data_nascimento) 
           + sizeof(temp->salario); 
}

TFunc *criar_funcionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario) {
    TFunc *func = (TFunc *) malloc(sizeof(TFunc));
    if (func) memset(func, 0, sizeof(TFunc));
    func->cod = cod;
    strcpy(func->nome, nome);
    strcpy(func->cpf, cpf);
    strcpy(func->data_nascimento, data_nascimento);
    func->salario = salario;
    return func;
}


void salvar_funcionario(TFunc *func, FILE *out) {
    fwrite(&func->cod, sizeof(int), 1, out);
    fwrite(func->nome, sizeof(char), sizeof(func->nome), out);
    fwrite(func->cpf, sizeof(char), sizeof(func->cpf), out);
    fwrite(func->data_nascimento, sizeof(char), sizeof(func->data_nascimento), out);
    fwrite(&func->salario, sizeof(double), 1, out);

    printf("\nShell Debug: Funcionario salvo com sucesso!\n");
}

int tamanho_arquivo_de_funcionarios(FILE *arq) {
    fseek(arq, 0, SEEK_END);
    int tam = trunc(ftell(arq) / tamanho_registro_funcionario());
    return tam;
}


TFunc *ler_arquivo_funcionario(FILE *in) {
    TFunc *func = (TFunc *) malloc(sizeof(TFunc));
    if (0 >= fread(&func->cod, sizeof(int), 1, in)) {
        free(func);
        return NULL;
    }
    fread(func->nome, sizeof(char), sizeof(func->nome), in);
    fread(func->cpf, sizeof(char), sizeof(func->cpf), in);
    fread(func->data_nascimento, sizeof(char), sizeof(func->data_nascimento), in);
    fread(&func->salario, sizeof(double), 1, in);
    return func;
}


void imprimir_funcionario(TFunc *func) {
    printf("Shell Debug: Funcionario de codigo %d | Nome: %s | CPF: %s | Data de Nascimento: %s | Salario: %.2f\n", 
    func->cod, func->nome, func->cpf, func->data_nascimento, func->salario);

}

void criarBase_funcionarios(FILE *out, int tam){

    int vet[tam];
    TFunc *f;

    for(int i=0;i<tam;i++)
        vet[i] = i+1;

    shuffle_funcionarios(vet,tam,(tam*10)/100);

    printf("\nGerando a base de dados...\n");

    for (int i=0;i<tam;i++){
        f = criar_funcionario(vet[i], "XXXXXXXXXX", "000.000.000-00", "00/00/0000", 0);
        salvar_funcionario(f, out);
    }

    free(f);

}

void criarBase_funcionarios_Binario(FILE *out, int tam){

    int vet[tam];
    TFunc *f;

    for(int i=0;i<tam;i++)
        vet[i] = i+1;

    printf("\nGerando a base de dados de funcionario...\n");

    for (int i=0;i<tam;i++){
        f = criar_funcionario(vet[i], "XXXXXXXXXX", "000.000.000-00", "00/00/0000", 0);
        salvar_funcionario(f, out);
    }

    printf("Base de dados de funcionarios gerada com sucesso!\n");

    free(f);

}

void shuffle_funcionarios(int *vet,int MAX,int MIN) {
    srand(time(NULL));
    for (int i = MAX - MIN - 1; i > 0; i--) {
        int j = rand() % (i);
        int tmp = vet[j];
        vet[j] = vet[i];
        vet[i] = tmp;
    }
}

void imprimirBase_funcionarios(FILE *out){
    
    rewind(out);
    TFunc *f;
    while ((f = ler_arquivo_funcionario(out)) != NULL)
        imprimir_funcionario(f);
    free(f);

}

