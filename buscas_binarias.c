#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "funcionario.h"
#include "livro.h"
#include "buscas_binarias.h"

int total_iterations;

void bases_buscas_binarias(FILE *employeeFileBinary, FILE *bookFileBinary, FILE *LogFileBinary, int tamanho_base) {
    if ((employeeFileBinary = fopen("./bin/shell_funcionarios.dat", "wb+")) == NULL
        || (bookFileBinary = fopen("./bin/shell_books.dat", "wb+")) == NULL
        || (LogFileBinary = fopen("./bin/shell_log.dat", "w")) == NULL) {
        printf("Erro ao abrir os arquivo binários\n");
        exit(1);
    } else {
        printf("\033[H\033[J");
        criarBase_funcionarios_Binario(employeeFileBinary, tamanho_base);
        criarBase_livros_Binario(bookFileBinary, tamanho_base);

        clock_t start = clock();
        for(int i = 0; i < tamanho_base; i++){
        buscarFuncionario_binariamente(i, employeeFileBinary, tamanho_base, LogFileBinary);
        buscarLivro_binariamente(i, bookFileBinary, tamanho_base, LogFileBinary);

        }

        double cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
        salvar_log_file_binary(LogFileBinary, total_iterations, cpu_time_used * 1000);
        printf("\nShell Debug: Tempo total: %.2f ms | Numero de iteracoes: %i\n", cpu_time_used * 1000, total_iterations);
        total_iterations = 0;
        return;
    }

    
}

TFunc *buscarFuncionario_binariamente(int chave, FILE *arquivo, int tam, FILE *LogFileBinary) {
    TFunc *registro = (TFunc *)malloc(sizeof(TFunc));
    int esq = 0;
    int dir = tam - 1;
    int iteracoes = 0;

    clock_t start_time = clock();

    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        fseek(arquivo, meio * tamanho_registro_funcionario(), SEEK_SET);
        fread(registro, sizeof(TFunc), 1, arquivo);
        iteracoes++;

        if (registro->cod == chave) {
            double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000.0;
            salvar_log_file_binary(LogFileBinary, iteracoes, elapsed_time);
            printf("\nShell Debug: Codigo: %i | Iteracoes: %d | Tempo de busca: %.2f ms\n", chave, iteracoes, elapsed_time);
            imprimir_funcionario(registro);
            return registro;
        } else if (registro->cod < chave) {
            esq = meio + 1;
        } else {
            dir = meio - 1;
        }
        total_iterations += iteracoes;
    }
    free(registro);
    return NULL;
}

TLivro *buscarLivro_binariamente(int chave, FILE *arquivo, int tam, FILE *LogFileBinary) {
    TLivro *registro = (TLivro *)malloc(sizeof(TLivro));
    int esq = 0;
    int dir = tam - 1;
    int iteracoes = 0;
    clock_t start_time = clock(); // Marca o início do tempo de execução

    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        fseek(arquivo, meio * tamanho_registro_livro(), SEEK_SET);
        fread(registro, sizeof(TLivro), 1, arquivo);
        iteracoes++;

        if (registro->cod == chave) {
            double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000.0;
            salvar_log_file_binary(LogFileBinary, iteracoes, elapsed_time);
            printf("\nShell Debug: Codigo: %i | Iteracoes: %d | Tempo de busca: %.2f ms\n", chave, iteracoes, elapsed_time);
            imprimir_livro(registro);
            return registro;
        } else if (registro->cod < chave) {
            esq = meio + 1;
        } else {
            dir = meio - 1;
        }
        total_iterations += iteracoes;
    }
    free(registro);
    return NULL;
}



void salvar_log_file_binary(FILE *out, int iteracoes, double tempo_ms) {
    TLogBinary *e = (TLogBinary *)malloc(sizeof(TLogBinary));
    e->iteracoes = iteracoes;
    e->tempo_ms = tempo_ms;
    fwrite(&e->iteracoes, sizeof(int), 1, out);
    fwrite(&e->tempo_ms, sizeof(int), 1, out);

    free(e);
}
