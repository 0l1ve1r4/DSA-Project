#include "sequential_search.h"

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

void findEmployee(FILE *in, int code){
    TFunc funcionario;
    int comparison = 0;
    clock_t start = clock();

    rewind(in);

    while (fread(&funcionario, sizeof(TFunc), 1, in) == 1) {
        comparison++;
        if (funcionario.cod == code) {
            double cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
            printf("Busca sequencial finalizada...\n");
            printf("Numero de comparacoes: %d | Tempo: %f\n", comparison, cpu_time_used);
            imprimeFuncionario(&funcionario);
            return;
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