#ifndef BUSCAS_SEQUENCIAIS_H
#define BUSCAS_SEQUENCIAIS_H
#include "funcionario.h"

typedef struct LogFile{
    int iteracoes;
    double tempo_ms;
} TLog;

void bases_buscas_sequenciais(FILE *employeeFile, FILE *bookFile, FILE *logFile, int tamanho_base);
TFunc *buscarFuncionario_sequencialmente(FILE *arquivo, int codigo, FILE *logFile);
void salvar_log_file(FILE *out, int iteracoes, double tempo_ms);

#endif // BUSCAS_SEQUENCIAIS_H
