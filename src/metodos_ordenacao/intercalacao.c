#include "intercalacao.h"

int compare_records(const void *a, const void *b, TipoRegistro tipo) {
    switch (tipo) {
        case FUNCIONARIO:
            return ((TFunc*)a)->cod - ((TFunc*)b)->cod;
        case LIVRO:
            return ((TLivro*)a)->cod - ((TLivro*)b)->cod;
        default:
            printf("Debug: Tipo de registro inválido\n");
            return 0;
    }
}

void intercalacao_otima_Func() {
    FILE *file = fopen(EMPLOYEE_FILE_PATH, "wb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    FILE *partitions[NUM_PARTITIONS];
    char partitionPath[50];

    for (int i = 0; i < NUM_PARTITIONS; i++) {
        sprintf(partitionPath, "%s/partition%d.dat", PARTITIONS_PATH, i);
        partitions[i] = fopen(partitionPath, "rb");
        if (partitions[i] == NULL) {
            perror("Erro ao abrir a partição");
            exit(EXIT_FAILURE);
        }
    }

    TFunc records[NUM_PARTITIONS];

    // Inicializar o buffer de leitura
    for (int i = 0; i < NUM_PARTITIONS; i++) {
        if (fread(&records[i], sizeof(TFunc), 1, partitions[i]) != 1) {
            records[i].cod = INT_MAX;
        }
    }

    // Intercalação ótima
    while (1) {
        int minIndex = -1;
        TFunc minRecord;

        // Encontrar o menor registro entre as partições
        for (int i = 0; i < NUM_PARTITIONS; i++) {
            if (records[i].cod != INT_MAX && (minIndex == -1 || compare_records(&records[i], &minRecord, FUNCIONARIO) < 0)) {
                minIndex = i;
                minRecord = records[i];
            }
        }

        if (minIndex == -1) {
            break;
        }

        // Escrever o menor registro no arquivo final
        fwrite(&minRecord, sizeof(TFunc), 1, file);

        // Ler o próximo registro da partição
        if (fread(&records[minIndex], sizeof(TFunc), 1, partitions[minIndex]) != 1) {
            // Marcar a partição como vazia se não houver mais registros
            records[minIndex].cod = INT_MAX;
        }
    }

    fclose(file);

    for (int i = 0; i < NUM_PARTITIONS; i++) {
        fclose(partitions[i]);
    }
}

void intercalacao_otima_Livro() {
    FILE *file = fopen(BOOK_FILE_PATH, "wb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    FILE *partitions[NUM_PARTITIONS];
    char partitionPath[50];

    for (int i = 0; i < NUM_PARTITIONS; i++) {
        sprintf(partitionPath, "%s/partition_B%d.dat", PARTITIONS_PATH, i);
        partitions[i] = fopen(partitionPath, "rb");
        if (partitions[i] == NULL) {
            perror("Erro ao abrir a partição");
            exit(EXIT_FAILURE);
        }
    }

    TLivro records[NUM_PARTITIONS];

    // Inicializar o buffer de leitura
    for (int i = 0; i < NUM_PARTITIONS; i++) {
        if (fread(&records[i], sizeof(TLivro), 1, partitions[i]) != 1) {
            // Marcar partições vazias
            records[i].cod = INT_MAX;
        }
    }

    // Intercalação ótima
    while (1) {
        int minIndex = -1;
        TLivro minRecord;

        // Encontrar o menor registro entre as partições
        for (int i = 0; i < NUM_PARTITIONS; i++) {
            if (records[i].cod != INT_MAX && (minIndex == -1 || compare_records(&records[i], &minRecord, LIVRO) < 0)) {
                minIndex = i;
                minRecord = records[i];
            }
        }

        if (minIndex == -1) {
            // Todas as partições foram processadas
            break;
        }

        // Escrever o menor registro no arquivo final
        fwrite(&minRecord, sizeof(TLivro), 1, file);

        // Ler o próximo registro da partição
        if (fread(&records[minIndex], sizeof(TLivro), 1, partitions[minIndex]) != 1) {
            // Marcar a partição como vazia se não houver mais registros
            records[minIndex].cod = INT_MAX;
        }
    }

    fclose(file);

    for (int i = 0; i < NUM_PARTITIONS; i++) {
        fclose(partitions[i]);
    }
}

void intercalacoes_otimas() {

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    intercalacao_otima_Func();
    intercalacao_otima_Livro();
    system("del src\\bin\\partitions\\*.dat");

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f\n", cpu_time_used);
    NUM_PARTITIONS = 0;
}


