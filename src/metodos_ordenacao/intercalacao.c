#include "intercalacao.h"

/*


A intercalação ótima é um método de ordenação externa usado para classificar grandes conjuntos de dados
 que não cabem totalmente na memória principal. Consiste em dividir, ordenar e intercalar as partições
  de maneira a minimizar o número total de leituras e gravações no dispositivo de armazenamento externo.
   A eficiência depende da escolha inteligente das partições a serem intercaladas.

*/


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

    intercalacao_otima_struct *e;
    e = save_intercalacao_otima_struct(NUM_PARTITIONS, PARTITIONS_PER_STRUCTS, cpu_time_used);
    printf("\nLog da intercalacao otima:\n");
    printf("Numero de particoes: %d\n", e->num_partitions);
    printf("Numero de registros por particao: %d\n", e->num_registro_per_partition);
    printf("Tempo de execucao: %f\n", e->tempo);

    NUM_PARTITIONS = 0;
    return;
}


intercalacao_otima_struct* save_intercalacao_otima_struct(int num_partitions, int num_registro_per_partition, float tempo) {
    FILE *file = fopen(LOG_FILE_PATH, "wb+");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    intercalacao_otima_struct *e = malloc(sizeof(intercalacao_otima_struct));
    e->num_partitions = num_partitions;
    e->num_registro_per_partition = num_registro_per_partition;
    e->tempo = tempo;
    fwrite(e, sizeof(intercalacao_otima_struct), 1, file);
    

    fclose(file);
    return e;

}
