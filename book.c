#include "book.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//---------------------------------------*--------------------------------------

int publisher_structSize(){
    return sizeof(char)*50;
}

int book_structSize(){
    return sizeof(int)
        + sizeof(char) * 50 
        + sizeof(char) * 11 
        + publisher_structSize(); //Editora do livro
}

//---------------------------------------*--------------------------------------

publisher *newPublisher(char *name){

    publisher *e = (publisher *)malloc(sizeof(publisher));
    if (e) memset(e, 0, sizeof(publisher));
    strcpy(e->name, name);
    return e;
}

book *newBook(int code, char *name, publisher editora){
    
        book *e = (book *)malloc(sizeof(book));
        if (e) memset(e, 0, sizeof(book));
        e->cod = code;
        strcpy(e->name, name);
        e->editora = editora;
        return e;
}

//---------------------------------------*--------------------------------------

void savePublisher(publisher *e, FILE *out){
    fwrite(e->name, sizeof(char), sizeof(e->name), out);
}

void saveBook(book *e, FILE *out){
    fwrite(&e->cod, sizeof(int), 1, out);
    fwrite(e->name, sizeof(char), sizeof(e->name), out);
    savePublisher(&e->editora, out);
}

//---------------------------------------*--------------------------------------

publisher *read_publisher_file(FILE *in){
    publisher *e = (publisher *)malloc(sizeof(publisher));
    if (e) {
        fread(e->name, sizeof(char), sizeof(e->name), in);
    }
    return e;
}

book *read_book_file(FILE *in){
    book *e = (book *)malloc(sizeof(book));
    if (e) {
        fread(&e->cod, sizeof(int), 1, in);
        fread(e->name, sizeof(char), sizeof(e->name), in);
        e->editora = *read_publisher_file(in);
    }
    return e;
}

//---------------------------------------*--------------------------------------

void print_Publisher(publisher *e){
    printf("Nome: %s\n", e->name);
}

void print_Book(book *e){
    printf("Nome: %s | Codigo: %d\n", e->name, e->cod);
    printf("Editora: %s\n", e->editora.name);
}

//---------------------------------------*--------------------------------------


