#ifndef LIVRO_H
#define LIVRO_H
#include <stdio.h>

typedef struct Livro {
    int cod;
    char nome[50];
    char numero_paginas[11];
    char autor[50];
    char editora[50];
    char data_emprestimo[11];
    double preco;
} TLivro;

int tamanho_registro_livro();
TLivro *criar_livro(int cod, char *nome, char *numero_paginas, char *autor, char *editora, char *data_emprestimo, double preco);
void salvar_livro(TLivro *livro, FILE *out);
int tamanho_arquivo_de_livros(FILE *arq);
TLivro *ler_arquivo_livro(FILE *in);
void imprimir_livro(TLivro *livro);
void criarBase_livros(FILE *out, int tam);
void criarBase_livros_Binario(FILE *out, int tam);
void shuffle_livros(int *vet, int MAX);
void imprimirBase_livros(FILE *out);

#endif // LIVRO_H
