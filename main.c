#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "funcionario.h"
#include "buscas_sequenciais.h"

int main(int argc, char *argv[])    //Para compilar use ->  gcc -o app ./*.c
{
    printf("\033[H\033[J"); //Limpar tela do seu terminal
    FILE *employeeFile, *bookFile, *logFile;
    bases_buscas_sequenciais(employeeFile, bookFile, logFile, 1000);
    
    return 0;
}




