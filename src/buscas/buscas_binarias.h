#ifndef BUSCAS_BINARIAS_H
#define BUSCAS_BINARIAS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../estruturas.h"


typedef struct LogFileBinary{
    int iteracoes;
    double tempo_ms;
} TLogBinary;


//'buscas_binarias.c', essa funcao cria a base de funcionarios e livros, ordenada.
int criar_base_ordenada(FILE *employeeFileBinary, FILE *bookFileBinary, FILE *LogFileBinary, int tamanho_base);

//'buscas_binarias.c', essa funcao cria a base de funcionarios e livros, desordenada.
int criar_base_desordenada(FILE *employeeFileBinary, FILE *bookFileBinary, FILE *LogFileBinary, int tamanho_base);

//'buscas_binarias.c', essa funcao busca o funcionario binariamente.
TFunc *buscarFuncionario_binariamente(int chave, FILE *arquivo, int tam, FILE *LogFileBinary);

//'buscas_binarias.c', essa funcao busca o livro binariamente.
TLivro *buscarLivro_binariamente(int chave, FILE *arquivo, int tam, FILE *LogFileBinary);

//'buscas_binarias.c', essa funcao salva o log no arquivo binario.
void salvar_log_file_binary(FILE *out, int iteracoes, double tempo_ms);

#endif // BUSCAS_BINARIAS_H
