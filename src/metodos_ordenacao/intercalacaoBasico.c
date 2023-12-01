#include "intercalacaoBasico.h"

// Função de comparação para a intercalação
int compare_records(const void *a, const void *b) {
    return ((TFunc*)a)->cod - ((TFunc*)b)->cod;
}

void intercalacao_basica_Func() {
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
            // Marcar partições vazias
            records[i].cod = INT_MAX;
        }
    }

    while (1) {
        int minIndex = -1;
        TFunc minRecord;

        // Encontrar o menor registro entre as partições
        for (int i = 0; i < NUM_PARTITIONS; i++) {
            if (records[i].cod != INT_MAX && (minIndex == -1 || compare_records(&records[i], &minRecord) < 0)) {
                minIndex = i;
                minRecord = records[i];
            }
        }

        if (minIndex == -1) {
            // Todas as partições foram processadas
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


// Função de comparação para a intercalação
int compare_records_livro(const void *a, const void *b) {
    return ((TLivro*)a)->cod - ((TLivro*)b)->cod;
}

void intercalacao_basica_Livro() {
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

    while (1) {
        int minIndex = -1;
        TLivro minRecord;

        // Encontrar o menor registro entre as partições
        for (int i = 0; i < NUM_PARTITIONS; i++) {
            if (records[i].cod != INT_MAX && (minIndex == -1 || compare_records_livro(&records[i], &minRecord) < 0)) {
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