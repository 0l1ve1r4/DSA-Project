#ifndef BUSCAS_BINARIAS_H
#define BUSCAS_BINARIAS_H

#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"
#include "livro.h"

typedef struct LogFileBinary{
    int iteracoes;
    double tempo_ms;
} TLogBinary;

void bases_buscas_binarias(FILE *employeeFileBinary, FILE *bookFileBinary, FILE *logFileBinary, int tamanho_base);

TFunc *buscarFuncionario_binariamente(int chave, FILE *arquivo, int tam, FILE *LogFileBinary);

TLivro *buscarLivro_binariamente(int chave, FILE *arquivo, int tam, FILE *LogFileBinary);


void salvar_log_file_binary(FILE *out, int iteracoes, double tempo_ms);

#endif // BUSCAS_BINARIAS_H
