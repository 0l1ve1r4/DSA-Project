#ifndef BUSCAS_SEQUENCIAIS_H
#define BUSCAS_SEQUENCIAIS_H
#include "funcionario.h"

typedef struct LogFile{
    int iteracoes;
    double tempo_ms;
} TLog;

/*Esta função é a função principal do programa da primeira parte do trabalho. Ela lida com a criação de bases de dados e 
a realização de buscas sequenciais em registros de funcionários. É responsável por abrir arquivos binários de funcionários, 
livros e logs, criar uma base de dados de funcionários, gerar um número aleatório de vezes para buscar */
void bases_buscas_sequenciais(FILE *employeeFile, FILE *bookFile, FILE *logFile, int tamanho_base);

/* Esta função busca um funcionário em um arquivo de forma sequencial. Ela lê registros de funcionários um por um, comparando
 o código do funcionário com o código fornecido como argumento. Se encontrar um funcionário com o código correspondente,
  registra o número de iterações necessárias, o tempo gasto na busca e imprime os detalhes do funcionário. Caso contrário, 
  continua a busca até o final do arquivo.*/
TFunc *buscarFuncionario_sequencialmente(FILE *arquivo, int codigo, FILE *logFile);

/* Esta função busca um funcionário em um arquivo de forma sequencial. Ela lê registros de funcionários um por um, 
comparando o código do funcionário com o código fornecido como argumento. Se encontrar um funcionário com o código correspondente,
 registra o número de iterações necessárias, o tempo gasto na busca e imprime os detalhes do funcionário. 
 Caso contrário, continua a busca até o final do arquivo.*/
void salvar_log_file(FILE *out, int iteracoes, double tempo_ms);

#endif // BUSCAS_SEQUENCIAIS_H
