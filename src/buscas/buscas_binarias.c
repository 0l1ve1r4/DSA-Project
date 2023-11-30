#include "buscas_binarias.h"

int total_iterations;

int criar_base_ordenada(FILE *employeeFileBinary, FILE *bookFileBinary, FILE *LogFileBinary, int tamanho_base) {

        criar_base_func_ordenada(employeeFileBinary, tamanho_base);
        criar_base_livros_ordenada(bookFileBinary, tamanho_base);
        
        return 0;
    }

int criar_base_desordenada(FILE *employeeFileBinary, FILE *bookFileBinary, FILE *LogFileBinary, int tamanho_base) {

        criar_base_func_desordenada(employeeFileBinary, tamanho_base);
        criar_base_livros_desordenada(bookFileBinary, tamanho_base);
        
        return 0;
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
            return registro;

        } else if (registro->cod < chave) {
            esq = meio + 1;
        } else {
            dir = meio - 1;
        }
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
