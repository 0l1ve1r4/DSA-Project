#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./src/livro.h"
#include "./src/funcionario.h"
#include "./src/buscas/buscas_sequenciais.h"
#include "./src/buscas/buscas_binarias.h"


int main(int argc, char *argv[])   
{
    printf("\033[H\033[J"); //Limpar tela do seu terminal
    FILE *employeeFile, *bookFile, *logFile;
    employeeFile = fopen("./src/bin/shell_funcionarios.dat", "wb+");
    bookFile = fopen("./src/bin/shell_books.dat", "wb+");
    logFile = fopen("./src/bin/shell_log.dat", "w");
    printf("Buscas Sequenciais\n");
    bases_buscas_sequenciais(employeeFile, bookFile, logFile, 1000);

    system("pause");
    
    int tamanho_base = 10000; // Escolha o tamanho da base desejada
    bases_buscas_binarias(employeeFile, bookFile, logFile, tamanho_base);

    fclose(employeeFile);
    fclose(bookFile);
    fclose(logFile);
    return 0;
}

//gcc -o window ./src/*.c ./src/buscas/*.c ./unit_tests/shellTests.c

