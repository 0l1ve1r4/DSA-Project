
#include "classificacao_internas.h"
/*
int classificacao_interna(FILE *arq, int M){


    rewind(arq); //posiciona cursor no inicio do arquivo

    int reg = 0;
    int nFunc = tamanho_arquivo(arq);
    int qtdParticoes = 0;
    int t = tamanho_registro();
    char *nomeParticao[20];

    while (reg != nFunc) {
        //le o arquivo e coloca no vetor
        TFunc *v[M];
        int i = 0;
        while (!feof(arq)) {
            fseek(arq, (reg) * t, SEEK_SET);
            v[i] = le(arq);
       //     imprime_funcionario(v[i]);
            i++;
            reg++;
            if(i>=M) break;
        }

        //ajusta tamanho M caso arquivo de entrada tenha terminado antes do vetor
        if (i != M) {
            M = i;
        }

        //faz ordenacao
        for (int j = 1; j < M; j++) {
            TFunc *f = v[j];
            i = j - 1;
            while ((i >= 0) && (v[i]->cod > f->cod)) {
                v[i + 1] = v[i];
                i = i - 1;
            }
            v[i + 1] = f;
        }

        //cria arquivo de particao e faz gravacao

        sprintf(nomeParticao, "partition%i.dat", qtdParticoes);
        //nome = fopen(nomeParticao, "wb");

        //printf("\n%s\n", nome);

        FILE *p;

        if ((p = fopen(nomeParticao, "wb+")) == NULL) {
            printf("Erro criar arquivo de saida\n");
        } else {
            for (int i = 0; i < M; i++) {
                fseek(p, (i) * t, SEEK_SET);
                salva(v[i], p);
                //imprime(v[i]);
            }
            //imprimirBase(p);
            fclose(p);
            qtdParticoes++;
        }
        for(int jj = 0; jj<M; jj++)
            free(v[jj]);
    }

    return qtdParticoes;

}*/