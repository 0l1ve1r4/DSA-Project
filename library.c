#include "library.h"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

int tamanho_TFunc() {
    return sizeof(int)  //cod
           + sizeof(char) * 50 //nome
           + sizeof(char) * 15 //cpf
           + sizeof(char) * 11 //data_nascimento
           + sizeof(double); //salario
}

int tamanho_TEdit(){
    return sizeof(char)*50; //Nome

}

int tamaho_TLivro(){
    return sizeof(int) //cod
        + sizeof(char) * 50 //nome
        + sizeof(char) * 11 //data_lançamento
        + tamanho_TEdit(); //Editora do livro
}

//---------------------------------------*--------------------------------------

// Cria funcionario. 
TFunc *newFuncionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario) {
    TFunc *func = (TFunc *) malloc(sizeof(TFunc)); //inicializa espaco de memoria com ZEROS

    if (func) memset(func, 0, sizeof(TFunc));
    func->cod = cod;        //copia valores para os campos de func
    strcpy(func->nome, nome);
    strcpy(func->cpf, cpf);
    strcpy(func->data_nascimento, data_nascimento);
    func->salario = salario;
    return func;
}


//---------------------------------------*--------------------------------------


// Salva funcionario no arquivo out, na posicao atual do cursor
void salvaFunc(TFunc *func, FILE *out) {
    fwrite(&func->cod, sizeof(int), 1, out);
    //func->nome ao inves de &func->nome, pois string ja eh um ponteiro
    fwrite(func->nome, sizeof(char), sizeof(func->nome), out);
    fwrite(func->cpf, sizeof(char), sizeof(func->cpf), out);
    fwrite(func->data_nascimento, sizeof(char), sizeof(func->data_nascimento), out);
    fwrite(&func->salario, sizeof(double), 1, out);
}

//---------------------------------------*--------------------------------------


// Le um funcionario do arquivo in na posicao atual do cursor
// Retorna um ponteiro para funcionario lido do arquivo
TFunc *leFunc(FILE *in) {
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

//---------------------------------------*--------------------------------------


// Imprime funcionario
void imprimeFunc(TFunc *func) {
    printf("**********************************************");
    printf("\nFuncionario de codigo ");
    printf("%d", func->cod);
    printf("\nNome: ");
    printf("%s", func->nome);
    printf("\nCPF: ");
    printf("%s", func->cpf);
    printf("\nData de Nascimento: ");
    printf("%s", func->data_nascimento);
    printf("\nSalario: ");
    printf("%4.2f", func->salario);
    printf("\n**********************************************");
}