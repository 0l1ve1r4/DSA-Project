#include "livro.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int tamanho_registro_livro() {
    TLivro *temp;
    return sizeof(temp->cod)
           + sizeof(temp->nome)
           + sizeof(temp->numero_paginas)
           + sizeof(temp->autor)
           + sizeof(temp->editora)
           + sizeof(temp->data_emprestimo)
           + sizeof(temp->preco);
}

TLivro *criar_livro(int cod, char *nome, char *numero_paginas, char *autor, char *editora, char *data_emprestimo, double preco) {
    TLivro *livro = (TLivro *) malloc(sizeof(TLivro));
    if (livro) memset(livro, 0, sizeof(TLivro));
    livro->cod = cod;
    strcpy(livro->nome, nome);
    strcpy(livro->numero_paginas, numero_paginas);
    strcpy(livro->autor, autor);
    strcpy(livro->editora, editora);
    strcpy(livro->data_emprestimo, data_emprestimo);
    livro->preco = preco;

    printf("Shell Debug: Livro criado com sucesso.\n");
    return livro;
}

void salvar_livro(TLivro *livro, FILE *out) {
    fwrite(&livro->cod, sizeof(int), 1, out);
    fwrite(livro->nome, sizeof(char), sizeof(livro->nome), out);
    fwrite(livro->numero_paginas, sizeof(char), sizeof(livro->numero_paginas), out);
    fwrite(livro->autor, sizeof(char), sizeof(livro->autor), out);
    fwrite(livro->editora, sizeof(char), sizeof(livro->editora), out);
    fwrite(livro->data_emprestimo, sizeof(char), sizeof(livro->data_emprestimo), out);
    fwrite(&livro->preco, sizeof(double), 1, out);

    printf("Shell Debug: Livro salvo com sucesso. cod: %i\n", livro->cod);

}

int tamanho_arquivo_de_livros(FILE *arq) {
    fseek(arq, 0, SEEK_END);
    int tam = ftell(arq) / tamanho_registro_livro();
    return tam;
}

TLivro *ler_arquivo_livro(FILE *in) {
    TLivro *livro = (TLivro *) malloc(sizeof(TLivro));
    if (0 >= fread(&livro->cod, sizeof(int), 1, in)) {
        free(livro);
        return NULL;
    }
    fread(livro->nome, sizeof(char), sizeof(livro->nome), in);
    fread(livro->numero_paginas, sizeof(char), sizeof(livro->numero_paginas), in);
    fread(livro->autor, sizeof(char), sizeof(livro->autor), in);
    fread(livro->editora, sizeof(char), sizeof(livro->editora), in);
    fread(livro->data_emprestimo, sizeof(char), sizeof(livro->data_emprestimo), in);
    fread(&livro->preco, sizeof(double), 1, in);
    return livro;
}

void imprimir_livro(TLivro *livro) {
    printf("Shell Debug: Livro de codigo %d | Nome: %s | Numero de Paginas: %s | Autor: %s | Editora: %s | Data de Emprestimo: %s | Preco: %.2f\n",
           livro->cod, livro->nome, livro->numero_paginas, livro->autor, livro->editora, livro->data_emprestimo, livro->preco);
}

void criarBase_livros(FILE *out, int tam) {
    int vet[tam];
    TLivro *livro;

    for (int i = 0; i < tam; i++)
        vet[i] = i + 1;

    shuffle_livros(vet, tam);

    printf("\nShell Debug: Gerando a base de dados de livros\n");

    for (int i = 0; i < tam; i++) {
        livro = criar_livro(vet[i], "XXXXXXXXXX", "0", "Autor Desconhecido", "Editora Desconhecida", "00/00/0000", 0);
        salvar_livro(livro, out);
    }

    free(livro);
}


void criarBase_livros_Binario(FILE *out, int tam) {
    int vet[tam];
    TLivro *livro;

    for (int i = 0; i < tam; i++)
        vet[i] = i + 1;

    printf("\nShell Debug: Gerando a base de dados de livros...\n");

    for (int i = 0; i < tam; i++) {
        livro = criar_livro(vet[i], "XXXXXXXXXX", "0", "Autor Desconhecido", "Editora Desconhecida", "00/00/0000", 0);
        salvar_livro(livro, out);
    }

    printf("\nShell Debug: Base de dados de livros gerada com sucesso!\n");

    free(livro);
}

void shuffle_livros(int *vet, int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = vet[j];
        vet[j] = vet[i];
        vet[i] = tmp;
    }
}

void imprimirBase_livros(FILE *out) {
    rewind(out);
    TLivro *livro;
    while ((livro = ler_arquivo_livro(out)) != NULL)
        imprimir_livro(livro);
    free(livro);
}
