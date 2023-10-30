#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "employee.h"
#include "book.h"
#include "sequential_search.h"


int main(int argc, char *argv[])    //Para compilar use ->  gcc -o app ./*.c
{

    FILE *employeeFile, *bookFile, *publisherFile;

    if ((employeeFile = fopen("./bin/funcionarios.dat", "a+")) == NULL 
        || (bookFile = fopen("./bin/books.dat", "a+")) == NULL
        || (publisherFile = fopen("./bin/editFile.dat", "a+")) == NULL
                        ) {
        printf("Erro ao abrir os arquivo binarios\n");
        exit(1);
    }

    else{

        printf("\033[H\033[J"); //Limpar tela

        create_random_employee_database(1000, employeeFile);
        int random_number = rand() % 100;

        printf("Numero aleatorio de vezes que iremos procurar funcionario aleatorios: %d\n", random_number); system("pause");
        
        clock_t start = clock();
        for (int i = 0; i < random_number; i++)
            findEmployee(employeeFile, i);
        
        
        double cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
        printf("Tempo total: %f ms\n", cpu_time_used*1000);
            


}

}


