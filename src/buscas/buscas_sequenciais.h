#ifndef BUSCAS_SEQUENCIAIS_H
#define BUSCAS_SEQUENCIAIS_H

#include "../estruturas.h"

typedef struct LogFile{
    int iteracoes;
    double tempo_ms;
} TLog;

/**
 * @brief Função principal do programa da primeira parte do trabalho.
 * 
 * Realiza a criação de bases de dados e a realização de buscas sequenciais em registros de funcionários.
 * Abre todos os arquivos binários, cria uma base de dados de funcionários e livros, e gera buscas randômicas em ambas as bases.
 * 
 * @param employeeFile Ponteiro para o arquivo de funcionários.
 * @param bookFile Ponteiro para o arquivo de livros.
 * @param logFile Ponteiro para o arquivo de log.
 * @param tamanho_base Tamanho da base de dados a ser criada.
 */
void bases_buscas_sequenciais(FILE *employeeFile, FILE *bookFile, FILE *logFile, int tamanho_base);

/**
 * @brief Busca um funcionário em um arquivo de forma sequencial.
 * 
 * Lê registros de funcionários um por um, comparando o código do funcionário com o código fornecido como argumento.
 * 
 * @param arquivo Ponteiro para o arquivo de funcionários.
 * @param codigo Código do funcionário a ser buscado.
 * @param logFile Ponteiro para o arquivo de log.
 * @return Um ponteiro para a estrutura de funcionário encontrada ou NULL se não encontrado.
 */
TFunc *buscarFuncionario_sequencialmente(FILE *arquivo, int codigo, FILE *logFile);

/**
 * @brief Busca um livro em um arquivo de forma sequencial.
 * 
 * Lê registros de livros um por um, comparando o código do livro com o código fornecido como argumento.
 * 
 * @param arquivo Ponteiro para o arquivo de livros.
 * @param codigo Código do livro a ser buscado.
 * @param logFile Ponteiro para o arquivo de log.
 * @return Um ponteiro para a estrutura de livro encontrada ou NULL se não encontrado.
 */
TLivro *buscarLivro_sequencialmente(FILE *arquivo, int codigo, FILE *logFile);

/**
 * @brief Salva um registro de log em um arquivo de log.
 * 
 * Usa fwrite para escrever cada parte do registro.
 * 
 * @param out Ponteiro para o arquivo de log.
 * @param iteracoes Número de iterações realizadas.
 * @param tempo_ms Tempo em milissegundos.
 */
void salvar_log_file(FILE *out, int iteracoes, double tempo_ms);


#endif // BUSCAS_SEQUENCIAIS_H
