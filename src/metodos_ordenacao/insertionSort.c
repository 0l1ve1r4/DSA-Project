#include "../funcionario.h"
#include "../livro.h"
#include "insertionSort.h"

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

void insertionSort_funcionarios(FILE *arq, int tam) {
    int i;
    //faz o insertion sort
    for (int j = 2; j <= tam; j++) {
        //posiciona o arquivo no registro j
        fseek(arq, (j-1) * tamanho_registro_funcionario(), SEEK_SET);
        TFunc *fj = ler_arquivo_funcionario(arq);
        i = j - 1;
        //posiciona o cursor no registro i
        fseek(arq, (i-1) * tamanho_registro_funcionario(), SEEK_SET);
        TFunc *fi = ler_arquivo_funcionario(arq);
        while ((i > 0) && (fi->cod > fj->cod)) {
            //posiciona o cursor no registro i+1
            fseek(arq, i * tamanho_registro_funcionario(), SEEK_SET);
            salvar_funcionario(fi, arq);
            i = i - 1;
            //lê registro i
            fseek(arq, (i-1) * tamanho_registro_funcionario(), SEEK_SET);
            fi = ler_arquivo_funcionario(arq);
        }
        //posiciona cursor no registro i + 1
        fseek(arq, (i) * tamanho_registro_funcionario(), SEEK_SET);
        //salva registro j na posição i
        salvar_funcionario(fj, arq);
    }
    //descarrega o buffer para ter certeza que dados foram gravados
    printf("Shell Debug: Insertion Sort Funcionarios Finalizado\n");
    fflush(arq);
}

void insertionSort_livros(FILE *arq, int tam){
    int i;
    //faz o insertion sort
    for (int j = 2; j <= tam; j++) {
        //posiciona o arquivo no registro j
        fseek(arq, (j-1) * tamanho_registro_livro(), SEEK_SET);
        TLivro *fj = ler_arquivo_livro(arq);
        i = j - 1;
        //posiciona o cursor no registro i
        fseek(arq, (i-1) * tamanho_registro_livro(), SEEK_SET);
        TLivro *fi = ler_arquivo_livro(arq);
        while ((i > 0) && (fi->cod > fj->cod)) {
            //posiciona o cursor no registro i+1
            fseek(arq, i * tamanho_registro_livro(), SEEK_SET);
            salvar_livro(fi, arq);
            i = i - 1;
            //lê registro i
            fseek(arq, (i-1) * tamanho_registro_livro(), SEEK_SET);
            fi = ler_arquivo_livro(arq);
        }
        //posiciona cursor no registro i + 1
        fseek(arq, (i) * tamanho_registro_livro(), SEEK_SET);
        //salva registro j na posição i
        salvar_livro(fj, arq);
    }
    //descarrega o buffer para ter certeza que dados foram gravados
    printf("Shell Debug: Insertion Sort Livros Finalizado\n");
    fflush(arq);
}


