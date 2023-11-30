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


/**
 * @brief Cria a base de funcionários e livros de forma ordenada.
 * 
 * @param employeeFileBinary Ponteiro para o arquivo binário de funcionários.
 * @param bookFileBinary Ponteiro para o arquivo binário de livros.
 * @param LogFileBinary Ponteiro para o arquivo binário de log.
 * @param tamanho_base Tamanho da base de dados a ser criada.
 * @return Um valor indicando o sucesso da operação (por exemplo, 0 para sucesso, -1 para falha).
 */
int criar_base_ordenada(FILE *employeeFileBinary, FILE *bookFileBinary, FILE *LogFileBinary, int tamanho_base);

/**
 * @brief Cria a base de funcionários e livros de forma desordenada.
 * 
 * @param employeeFileBinary Ponteiro para o arquivo binário de funcionários.
 * @param bookFileBinary Ponteiro para o arquivo binário de livros.
 * @param LogFileBinary Ponteiro para o arquivo binário de log.
 * @param tamanho_base Tamanho da base de dados a ser criada.
 * @return Um valor indicando o sucesso da operação (por exemplo, 0 para sucesso, -1 para falha).
 */
int criar_base_desordenada(FILE *employeeFileBinary, FILE *bookFileBinary, FILE *LogFileBinary, int tamanho_base);

/**
 * @brief Busca um funcionário binariamente.
 * 
 * @param chave Código do funcionário a ser buscado.
 * @param arquivo Ponteiro para o arquivo binário de funcionários.
 * @param tam Tamanho da base de dados.
 * @param LogFileBinary Ponteiro para o arquivo binário de log.
 * @return Um ponteiro para a estrutura de funcionário encontrada ou NULL se não encontrado.
 */
TFunc *buscarFuncionario_binariamente(int chave, FILE *arquivo, int tam, FILE *LogFileBinary);

/**
 * @brief Busca um livro binariamente.
 * 
 * @param chave Código do livro a ser buscado.
 * @param arquivo Ponteiro para o arquivo binário de livros.
 * @param tam Tamanho da base de dados.
 * @param LogFileBinary Ponteiro para o arquivo binário de log.
 * @return Um ponteiro para a estrutura de livro encontrada ou NULL se não encontrado.
 */
TLivro *buscarLivro_binariamente(int chave, FILE *arquivo, int tam, FILE *LogFileBinary);

/**
 * @brief Salva o log no arquivo binário.
 * 
 * @param out Ponteiro para o arquivo binário de log.
 * @param iteracoes Número de iterações realizadas.
 * @param tempo_ms Tempo em milissegundos.
 */
void salvar_log_file_binary(FILE *out, int iteracoes, double tempo_ms);


#endif // BUSCAS_BINARIAS_H
