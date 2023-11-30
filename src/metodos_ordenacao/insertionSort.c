
#include "insertionSort.h"

void insertionSort_funcionarios(FILE *arq, int tam) {
    int i;
    for (int j = 2; j <= tam; j++) {
        fseek(arq, (j-1) * tamanho_registro_funcionario(), SEEK_SET);
        TFunc *fj = ler_arquivo_funcionario(arq);
        i = j - 1;

        while ((i > 0) && (fj->cod > ler_arquivo_funcionario(arq)->cod)) {
            fseek(arq, i * tamanho_registro_funcionario(), SEEK_SET);
            TFunc *fi = ler_arquivo_funcionario(arq);
            salvar_funcionario(fi, arq);

            i--;
            fseek(arq, i * tamanho_registro_funcionario(), SEEK_SET);
        }

        fseek(arq, i * tamanho_registro_funcionario(), SEEK_SET);
        salvar_funcionario(fj, arq);
    }

    printf("Shell Debug: Insertion Sort Funcionarios Finalizado\n");
    fflush(arq);
}


void insertionSort_livros(FILE *arq, int tam){
    int i;
    for (int j = 2; j <= tam; j++) {
        fseek(arq, (j-1) * tamanho_registro_livro(), SEEK_SET);
        TLivro *fj = ler_arquivo_livro(arq);
        i = j - 1;

        while ((i > 0) && (fj->cod > ler_arquivo_livro(arq)->cod)) {
            fseek(arq, i * tamanho_registro_livro(), SEEK_SET);
            TLivro *fi = ler_arquivo_livro(arq);
            salvar_livro(fi, arq);

            i--;
            fseek(arq, i * tamanho_registro_livro(), SEEK_SET);
        }

        fseek(arq, i * tamanho_registro_livro(), SEEK_SET);
        salvar_livro(fj, arq);
    }

    printf("Shell Debug: Insertion Sort Livros Finalizado\n");
    fflush(arq);
}

