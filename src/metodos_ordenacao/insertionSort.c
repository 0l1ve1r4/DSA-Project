
#include "insertionSort.h"

void insertionSort_funcionarios(FILE *arq, int tam) {
    TFunc *funcionarios = (TFunc *)malloc(tam * sizeof(TFunc));

    // Read all records into an array
    fseek(arq, 0, SEEK_SET);
    for (int i = 0; i < tam; i++) {
        fread(&funcionarios[i].cod, sizeof(int), 1, arq);
        fread(funcionarios[i].nome, sizeof(char), sizeof(funcionarios[i].nome), arq);
        fread(funcionarios[i].cpf, sizeof(char), sizeof(funcionarios[i].cpf), arq);
        fread(funcionarios[i].data_nascimento, sizeof(char), sizeof(funcionarios[i].data_nascimento), arq);
        fread(&funcionarios[i].salario, sizeof(double), 1, arq);
    }

    // Perform insertion sort on the array
    for (int j = 1; j < tam; j++) {
        TFunc key = funcionarios[j];
        int i = j - 1;

        while (i >= 0 && funcionarios[i].cod > key.cod) {
            funcionarios[i + 1] = funcionarios[i];
            i--;
        }

        funcionarios[i + 1] = key;
    }

    // Write the sorted array back to the file
    fseek(arq, 0, SEEK_SET);
    for (int i = 0; i < tam; i++) {
        fwrite(&funcionarios[i].cod, sizeof(int), 1, arq);
        fwrite(funcionarios[i].nome, sizeof(char), sizeof(funcionarios[i].nome), arq);
        fwrite(funcionarios[i].cpf, sizeof(char), sizeof(funcionarios[i].cpf), arq);
        fwrite(funcionarios[i].data_nascimento, sizeof(char), sizeof(funcionarios[i].data_nascimento), arq);
        fwrite(&funcionarios[i].salario, sizeof(double), 1, arq);
    }

    free(funcionarios);

    printf("Debug: Insertion Sort Funcionarios Finalizado\n");
    fflush(arq);
}

void insertionSort_livros(FILE *arq, int tam) {
    TLivro *livros = (TLivro *)malloc(tam * sizeof(TLivro));
    fseek(arq, 0, SEEK_SET);
    for (int i = 0; i < tam; i++) {
        fread(&livros[i], sizeof(TLivro), 1, arq);
    }
    for (int j = 1; j < tam; j++) {
        TLivro key = livros[j];
        int i = j - 1;

        while (i >= 0 && livros[i].cod > key.cod) {
            livros[i + 1] = livros[i];
            i--;
        }

        livros[i + 1] = key;
    }
    fseek(arq, 0, SEEK_SET);
    for (int i = 0; i < tam; i++) {
        fwrite(&livros[i], sizeof(TLivro), 1, arq);
    }
    //printLivroCodes(arq, tam); //debug only
    free(livros);

    printf("Debug: Insertion Sort Livros Finalizado\n");
    fflush(arq);
}



void insertion_sort_both(){
        FILE *employee_file, *book_file;
        employee_file = fopen(EMPLOYEE_FILE_PATH, "rb+");
        book_file = fopen(BOOK_FILE_PATH, "rb+");

        if (employee_file == NULL || book_file == NULL) {
            printf("\nDebug:Erro ao abrir os arquivos de funcionarios e livros.\n");
            exit(1);
        }
        printf("\nDebug: insertion_sort_both() Iniciado\n");
        insertionSort_funcionarios(employee_file, tamanho_arquivo_de_funcionarios(employee_file));
        insertionSort_livros(book_file, tamanho_arquivo_de_livros(book_file));
        

        fclose(employee_file);
        fclose(book_file);

}

void printLivroCodes(FILE *arq, int tam) {
    fseek(arq, 0, SEEK_SET);
    TLivro livro;

    for (int i = 0; i < tam; i++) {
        fread(&livro, sizeof(TLivro), 1, arq);
        printf("Livro %d Code: %d\n", i + 1, livro.cod);
    }
}