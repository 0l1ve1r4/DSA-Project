
#include "buscas_sequenciais.h"
#include <time.h>

int total_iterations_sequencial = 0;


TFunc *buscarFuncionario_sequencialmente(FILE *arquivo, int codigo, FILE *logFile) {
    TFunc *funcionario = (TFunc *)malloc(sizeof(TFunc));
    int numero_iteracoes = 0;
    clock_t start_time = clock();

    rewind(arquivo); 

    while (fread(&funcionario->cod, sizeof(int), 1, arquivo) == 1) {
        numero_iteracoes++;
        total_iterations_sequencial++;
        if (funcionario->cod == codigo) {
            clock_t end_time = clock();
            double time_elapsed_ms = ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000.0;

            printf("\nCodigo: %i | Iteracoes: %d | Tempo de busca: %.2f ms\n", codigo, numero_iteracoes, time_elapsed_ms);
            salvar_log_file(logFile, numero_iteracoes, time_elapsed_ms);
            
            return funcionario;
        } else {
            fseek(arquivo, sizeof(char) * sizeof(funcionario->nome)
                            + sizeof(char) * sizeof(funcionario->cpf)
                            + sizeof(char) * sizeof(funcionario->data_nascimento)
                            + sizeof(double), SEEK_CUR);
        }
    }

    clock_t end_time = clock();
    double time_elapsed_ms = ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000.0;
    printf("\nFuncionario com o codigo %i nao encontrado | Iteracoes: %d | Tempo: %.2f ms\n", codigo, numero_iteracoes, time_elapsed_ms);
    free(funcionario);
    return NULL;
}

TLivro *buscarLivro_sequencialmente(FILE *arquivo, int codigo, FILE *logFile) {
    TLivro *livro = (TLivro *)malloc(sizeof(TLivro));
    int numero_iteracoes = 0;
    clock_t start_time = clock();

    rewind(arquivo);

    while (fread(&livro->cod, sizeof(int), 1, arquivo) == 1) {
        numero_iteracoes++;
        total_iterations_sequencial++;
        if (livro->cod == codigo) {
            clock_t end_time = clock();
            double time_elapsed_ms = ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000.0;

            printf("\nCodigo: %i | Iteracoes: %d | Tempo: %.2f ms\n", codigo, numero_iteracoes, time_elapsed_ms);
            salvar_log_file(logFile, numero_iteracoes, time_elapsed_ms);

            return livro;
        } else {
            fseek(arquivo, sizeof(char) * sizeof(livro->nome)
                            + sizeof(char) * sizeof(livro->numero_paginas)
                            + sizeof(char) * sizeof(livro->autor)
                            + sizeof(char) * sizeof(livro->editora)
                            + sizeof(char) * sizeof(livro->data_emprestimo)
                            + sizeof(double), SEEK_CUR);
        }
    }

    clock_t end_time = clock();
    double time_elapsed_ms = ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000.0;
    printf("\nLivro %i nao encontrado | Iteracoes: %d | Tempo: %.2f ms\n", codigo, numero_iteracoes, time_elapsed_ms);
    free(livro);
    return NULL;
}


void salvar_log_file(FILE *out, int iteracoes, double tempo_ms) {
    TLog *e = (TLog *)malloc(sizeof(TLog));
    e->iteracoes = iteracoes;
    e->tempo_ms = tempo_ms;
    fwrite(&e->iteracoes, sizeof(int), 1, out);
    fwrite(&e->tempo_ms, sizeof(int), 1, out);
  
    free(e);
}
