#include "sequential_search.h"
#include "book.h"
#include "employee.h"

void findBook(FILE *in, int code) {
    book livro;
    int comparison = 0;
    clock_t start = clock();

    rewind(in);

    while (fread(&livro, sizeof(book), 1, in) == 1) {
        comparison++;
        if (livro.cod == code) {
            double cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
            printf("Busca sequencial finalizada...\n");
            printf("Numero de comparacoes: %d | Tempo: %f\n", comparison, cpu_time_used);
            print_Book(&livro);
            return;
        }
    }

    printf("Livro com com o codigo %d nao encontrado.\n", code);
}

void findEmployee(FILE *in, int code) {
    employee funcionario;
    int comparison = 0;
    clock_t start = clock();

    rewind(in);

    while (fread(&funcionario.cod, sizeof(int), 1, in) == 1) {
        comparison++;
        if (funcionario.cod == code) {
            // Read the remaining fields
            fread(funcionario.name, sizeof(char), 50, in);
            fread(funcionario.cpf, sizeof(char), 15, in);
            fread(funcionario.birthday, sizeof(char), 11, in);
            fread(&funcionario.salary, sizeof(double), 1, in);

            double cpu_time_used = ((double)(clock() - start)) / CLOCKS_PER_SEC;
            printf("Busca sequencial finalizada...\n");
            printf("Numero de comparacoes: %d | Tempo: %f\n", comparison, cpu_time_used);
            print_employee(&funcionario);
            return;
        } else {
            // Skip the remaining fields since we didn't find a match
            fseek(in, sizeof(char) * 50 + sizeof(char) * 15 + sizeof(char) * 11 + sizeof(double), SEEK_CUR);
        }
    }

    printf("Funcionario com o codigo %d nao encontrado.\n", code);
}

void findPublisher(FILE *in, char *name){
    publisher publi;
    int comparison = 0;
    clock_t start = clock();

    rewind(in);

    while (fread(&publi, sizeof(publisher), 1, in) == 1) {
        comparison++;
        if (publi.name == name) {
            double cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
            printf("Busca sequencial finalizada...\n");
            printf("Numero de comparacoes: %d | Tempo: %f\n", comparison, cpu_time_used);
            print_Publisher(&publi);
            return;
        }
    }

    printf("Editora com o nome %s nao encontrada.\n", name);
    
}