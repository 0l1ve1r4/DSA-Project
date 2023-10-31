#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define uma estrutura para representar uma editora
typedef struct {
    char name[50];  // Nome da editora
} publisher;

// Define uma estrutura para representar um livro com uma editora
typedef struct {
    int cod;          // Código do livro
    char name[50];    // Nome do livro
    publisher editora; // Editora do livro
} book;

// Função para retornar o tamanho da estrutura 'publisher' em bytes
int publisher_structSize();

// Função para retornar o tamanho da estrutura 'book' em bytes
int book_structSize();

// Função para criar uma nova editora com o nome fornecido e retornar um ponteiro para ela
publisher *newPublisher(char *name);

// Função para criar um novo livro com o código, nome e editora fornecidos e retornar um ponteiro para ele
book *newBook(int code, char *name, publisher editora);

void create_random_book_database(int n, FILE *out);

// Função para salvar uma estrutura de editora em um arquivo 
void savePublisher(publisher *e, FILE *out);

// Função para salvar uma estrutura de livro em um arquivo 
void saveBook(book *e, FILE *out);

// Função para ler uma estrutura de editora de um arquivo
publisher *read_publisher_file(FILE *in);

// Função para ler uma estrutura de livro de um arquivo
book *read_book_file(FILE *in);

// Função para imprimir os detalhes de uma editora
void print_Publisher(publisher *e);

// Função para imprimir os detalhes de um livro
void print_Book(book *e);

#endif