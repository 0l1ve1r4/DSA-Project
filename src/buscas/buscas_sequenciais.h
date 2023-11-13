#ifndef BUSCAS_SEQUENCIAIS_H
#define BUSCAS_SEQUENCIAIS_H

#include "../funcionario.h"
#include "../livro.h"

typedef struct LogFile{
    int iteracoes;
    double tempo_ms;
} TLog;

/*'buscas_sequenciais.c' Esta função é a função principal do programa da primeira parte do trabalho. Ela lida com a criação de bases de dados e 
a realização de buscas sequenciais em registros de funcionários, responsável por abrir todos os arquivos binários criar 
uma base de dados de funcionários e livros, e gerar buscas randômicas em ambas as bases.*/
void bases_buscas_sequenciais(FILE *employeeFile, FILE *bookFile, FILE *logFile, int tamanho_base);

/*'buscas_sequenciais.c' Esta função busca um funcionário em um arquivo de forma sequencial. Ela lê registros de funcionários um por um, comparando
 o código do funcionário com o código fornecido como argumento.*/
TFunc *buscarFuncionario_sequencialmente(FILE *arquivo, int codigo, FILE *logFile);

/*'buscas_sequenciais.c' Esta função busca um livro em um arquivo de forma sequencial. Ela lê registros de livros um por um, comparando
 o código do funcionário com o código fornecido como argumento.*/
TLivro *buscarLivro_sequencialmente(FILE *arquivo, int codigo, FILE *logFile);

/*'buscas_sequenciais.c' Esta função salva um registro de log em um arquivo de log. Ela usa fwrite para escrever cada parte do registro.*/
void salvar_log_file(FILE *out, int iteracoes, double tempo_ms);

#endif // BUSCAS_SEQUENCIAIS_H
