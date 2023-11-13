#ifndef BUSCAS_BINARIAS_H
#define BUSCAS_BINARIAS_H

#include <stdio.h>
#include <stdlib.h>
#include "../funcionario.h"
#include "../livro.h"

typedef struct LogFileBinary{
    int iteracoes;
    double tempo_ms;
} TLogBinary;


//'buscas_binarias.c', essa funcao cria a base de funcionarios e livros, depois faz buscas binarias neles.
void bases_buscas_binarias(FILE *employeeFileBinary, FILE *bookFileBinary, FILE *logFileBinary, int tamanho_base);

//'buscas_binarias.c', essa funcao busca o funcionario binariamente.
TFunc *buscarFuncionario_binariamente(int chave, FILE *arquivo, int tam, FILE *LogFileBinary);

//'buscas_binarias.c', essa funcao busca o livro binariamente.
TLivro *buscarLivro_binariamente(int chave, FILE *arquivo, int tam, FILE *LogFileBinary);

//'buscas_binarias.c', essa funcao salva o log no arquivo binario.
void salvar_log_file_binary(FILE *out, int iteracoes, double tempo_ms);

#endif // BUSCAS_BINARIAS_H
