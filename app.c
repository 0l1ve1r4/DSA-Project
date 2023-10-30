#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "library.h"
#include "sequential_search.h"

int main(int argc, char *argv[])
{
    printf("Testando...\n");
    FILE *funcionaryFile, *booksFile, *editorsFile;


    if ((funcionaryFile = fopen("./bin/funcionarios.dat", "a+")) == NULL 
        || (booksFile = fopen("./bin/books.dat", "a+")) == NULL
        || (editorsFile = fopen("./bin/editFile.dat", "a+")) == NULL
                        ) {
        printf("Erro ao abrir os arquivo binarios\n");
        exit(1);
    }

    else{
        printf("\033[H\033[J"); //Clear screen
        printf("Arquivos abertos com sucesso\n");
        criarFuncAleatorias(1000, funcionaryFile);
        printf("Arquivos criados com sucesso\n");
        printf("Clique para começar a procura sequencial...\n"); system("pause");
        
        clock_t start = clock();
        for (int i = 0; i < 1000; i++)
        {
            findEmployee(funcionaryFile, i);
        }
        printf("Busca sequencial finalizada...\n");
        double cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
        printf("Tempo total: %f ms\n", cpu_time_used*1000);
            


}

}

//To compile use: gcc -o app ./*.c
