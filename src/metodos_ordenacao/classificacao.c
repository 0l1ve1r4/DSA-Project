#include "classificacao.h"

int classificacao_interna_Func(int M) {
    FILE *arq = fopen(EMPLOYEE_FILE_PATH, "rb+");
    rewind(arq);

    int reg = 0;
    int nFunc = tamanho_arquivo_de_funcionarios(arq);
    int qtdParticoes = 0;
    int t = sizeof(TFunc);
    char nomeParticao[20];

    while (reg != nFunc) {

        TFunc *v[M];
        int i = 0;
        while (!feof(arq)) {
            fseek(arq, (reg) * t, SEEK_SET);
            v[i] = (TFunc*)malloc(sizeof(TFunc));
            fread(v[i], sizeof(TFunc), 1, arq);
            i++;
            reg++;
            if (i >= M) break;
        }

        if (i != M) {
            M = i;
        }

        // Seleção natural
        for (int j = 0; j < M / 2; j++) {
            int minIndex = j;
            int maxIndex = j;
            for (int k = j + 1; k < M - j; k++) {
                if (v[k]->cod < v[minIndex]->cod) {
                    minIndex = k;
                } else if (v[k]->cod > v[maxIndex]->cod) {
                    maxIndex = k;
                }
            }
            if (minIndex != maxIndex) {
                TFunc *temp = v[minIndex];
                v[minIndex] = v[j];
                v[j] = temp;

                if (maxIndex == j) {
                    maxIndex = minIndex;
                }

                temp = v[maxIndex];
                v[maxIndex] = v[M - j - 1];
                v[M - j - 1] = temp;
            }
        }

        // Cria arquivo de partição e faz a gravação
        sprintf(nomeParticao, "%s/partition%i.dat", PARTITIONS_PATH, qtdParticoes);

        FILE *p;

        if ((p = fopen(nomeParticao, "wb+")) == NULL) {
            printf("Erro ao criar arquivo de saída\n");
        } else {
            for (int i = 0; i < M; i++) {
                fseek(p, (i) * t, SEEK_SET);
                fwrite(v[i], sizeof(TFunc), 1, p);
            }
            fclose(p);
            qtdParticoes++;
        }
        for (int jj = 0; jj < M; jj++)
            free(v[jj]);
    }

    NUM_PARTITIONS = qtdParticoes;
    return 0;
}

int classificacao_interna_Livro(int M) {
    FILE *arq = fopen(BOOK_FILE_PATH, "rb+");
    rewind(arq);

    int reg = 0;
    int nLivros = tamanho_arquivo_de_livros(arq);
    int qtdParticoes = 0;
    int t = sizeof(TLivro);
    char nomeParticao[20];

    while (reg != nLivros) {

        TLivro *v[M];
        int i = 0;
        while (!feof(arq)) {
            fseek(arq, (reg) * t, SEEK_SET);
            v[i] = (TLivro*)malloc(sizeof(TLivro));
            fread(v[i], sizeof(TLivro), 1, arq);
            i++;
            reg++;
            if (i >= M) break;
        }

        if (i != M) {
            M = i;
        }

        // Seleção natural
        for (int j = 0; j < M / 2; j++) {
            int minIndex = j;
            int maxIndex = j;
            for (int k = j + 1; k < M - j; k++) {
                if (v[k]->cod < v[minIndex]->cod) {
                    minIndex = k;
                } else if (v[k]->cod > v[maxIndex]->cod) {
                    maxIndex = k;
                }
            }
            if (minIndex != maxIndex) {
                TLivro *temp = v[minIndex];
                v[minIndex] = v[j];
                v[j] = temp;

                if (maxIndex == j) {
                    maxIndex = minIndex;
                }

                temp = v[maxIndex];
                v[maxIndex] = v[M - j - 1];
                v[M - j - 1] = temp;
            }
        }

        // Cria arquivo de partição e faz a gravação
        sprintf(nomeParticao, "%s/partition_B%i.dat", PARTITIONS_PATH, qtdParticoes);

        FILE *p;

        if ((p = fopen(nomeParticao, "wb+")) == NULL) {
            printf("Erro ao criar arquivo de saída\n");
        } else {
            for (int i = 0; i < M; i++) {
                fseek(p, (i) * t, SEEK_SET);
                fwrite(v[i], sizeof(TLivro), 1, p);
            }
            fclose(p);
            qtdParticoes++;
        }
        for (int jj = 0; jj < M; jj++)
            free(v[jj]);
    }

    NUM_PARTITIONS = qtdParticoes;
    return 0;
}

void classificacoes(int M) {

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    classificacao_interna_Func(M);
    classificacao_interna_Livro(M);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nLog da classificacao:\n");
    printf("\nTempo de execucao: %f\n", cpu_time_used);

}
