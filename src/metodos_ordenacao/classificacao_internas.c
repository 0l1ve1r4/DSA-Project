#include "classificacao_internas.h"

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

        // faz ordenacao
        for (int j = 1; j < M; j++) {
            TLivro *livro = v[j];
            i = j - 1;
            while ((i >= 0) && (v[i]->cod > livro->cod)) {
                v[i + 1] = v[i];
                i = i - 1;
            }
            v[i + 1] = livro;
        }

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