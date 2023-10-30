#include "sequential_search.h"
#include "library.h"

void findBook(FILE *in, int code) {
    TLivro livro;
    int comparison = 0;
    clock_t start = clock();

    rewind(in);

    while (fread(&livro, sizeof(TLivro), 1, in) == 1) {
        comparison++;
        if (livro.cod == code) {
            double cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
            printf("Busca sequencial finalizada...\n");
            printf("Numero de comparacoes: %d | Tempo: %f\n", comparison, cpu_time_used);
            imprimeLivro(&livro);
            return;
        }
    }

    printf("Livro com com o codigo %d nao encontrado.\n", code);
}

void findEmployee(FILE *in, int code) {
    TFunc funcionario;
    int comparison = 0;
    clock_t start = clock();

    rewind(in);

    while (fread(&funcionario.cod, sizeof(int), 1, in) == 1) {
        comparison++;
        if (funcionario.cod == code) {
            // Read the remaining fields
            fread(funcionario.nome, sizeof(char), 50, in);
            fread(funcionario.cpf, sizeof(char), 15, in);
            fread(funcionario.data_nascimento, sizeof(char), 11, in);
            fread(&funcionario.salario, sizeof(double), 1, in);

            double cpu_time_used = ((double)(clock() - start)) / CLOCKS_PER_SEC;
            printf("Busca sequencial finalizada...\n");
            printf("Numero de comparacoes: %d | Tempo: %f\n", comparison, cpu_time_used);
            imprimeFunc(&funcionario);
            return;
        } else {
            // Skip the remaining fields since we didn't find a match
            fseek(in, sizeof(char) * 50 + sizeof(char) * 15 + sizeof(char) * 11 + sizeof(double), SEEK_CUR);
        }
    }

    printf("Funcionario com o codigo %d nao encontrado.\n", code);
}

void findPublisher(FILE *in, char *name){
    TEdit publisher;
    int comparison = 0;
    clock_t start = clock();

    rewind(in);

    while (fread(&publisher, sizeof(TEdit), 1, in) == 1) {
        comparison++;
        if (publisher.nome == name) {
            double cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
            printf("Busca sequencial finalizada...\n");
            printf("Numero de comparacoes: %d | Tempo: %f\n", comparison, cpu_time_used);
            imprimeEdit(&publisher);
            return;
        }
    }

    printf("Editora com o nome %s nao encontrada.\n", name);
    


}