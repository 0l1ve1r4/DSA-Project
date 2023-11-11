#include <stdio.h>
#include "classificacao_internas.h"
#include "../funcionario.h" 

void insertionSort(TFunc arr[], int n) {
    int i, j;
    TFunc key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].cod > key.cod) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void gerar_particoes(char *path, int n) {
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        printf("Failed to open file\n");
        return;
    }

    int file_size = tamanho_registro_funcionario();
    int partition_size = file_size / n;

    for (int i = 0; i < n; i++) {
        TFunc partition[partition_size];

        long offset = i * partition_size * tamanho_registro_funcionario();
        fseek(file, offset, SEEK_SET);
        fread(partition, sizeof(TFunc), partition_size, file);

        insertionSort(partition, partition_size);

        char outputFileName[20];  
        sprintf(outputFileName, "../src/bin/partitions/partition_%d.dat", i+1);
        FILE *outputFile = fopen(outputFileName, "wb");

        for (int j = 0; j < partition_size; j++) {
            salvar_funcionario(&partition[j], outputFile);
        }

        fclose(outputFile);
    }

    fclose(file);
}

/*int main() {
    gerar_particoes("./src/bin/shell_funcionarios.dat", 5);

    FILE *test = fopen("partition_3.dat", "rb");
    imprimirBase_funcionarios(test);

    return 0;
}*/

