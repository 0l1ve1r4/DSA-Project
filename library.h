#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>


//gcc -o nomeDoPrograma arquivoPrincipal.c -I caminhoDosHeaders
//gcc -o main main.c -I .



typedef struct Funcionario {
    int cod;
    char nome[50];
    char cpf[15];
    char data_nascimento[11];
    double salario;
} TFunc;

typedef struct Editora {
    char nome[50];
} TEdit;

typedef struct Livro {
    int cod;
    char nome[50];
    char data_lancamento[11];
    TEdit editora;
} TLivro;

// Retorna tamanho das estruturas
int tamanho_TFunc(); // Funcionario
int tamanho_TEdit(); //Editora
int tamaho_TLivro();  //Livro

// Cria uma estrutura do tipo especificado da funçao
TFunc *newFuncionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario);
TLivro *newLivro(int cod, char *nome, char *data_lancamento, TEdit editora);
TEdit *newEditora(char *nome);


// Salva a estrutura no arquivo out, na posicao atual do cursor
void salvaFunc(TFunc *func, FILE *out);
void salvaEdit(TEdit *editora, FILE *out);
void salvaLivro(TLivro *livro, FILE *out);

// Le um funcionario do arquivo in na posicao atual do cursor
// Retorna um ponteiro para funcionario lido do arquivo
TFunc *leFunc(FILE *in);
TEdit *leEdit(FILE *in);
TLivro *leLivro(FILE *in);


// Imprime o tipo da funçao
void imprimeFunc(TFunc *func);
void imprimeEdit(TEdit *edit);
void imprimeLivro(TLivro *livro);


//Nao implementadas ainda:
void sistemaBiblioteca(FILE *arquivoFuncionarios, FILE *arquivoLivros, FILE *arquivoEditoras); //Fnçao principal do codigo
void buscarLivro();
void realizarEmprestimos();
void devolverLivros();
void registrarUsuarios();
void relatorios();
void renovarEmprestimos();
void gerenciarFuncionarios();


#endif