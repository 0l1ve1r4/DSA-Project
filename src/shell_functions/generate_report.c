#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../funcionario.h"
#include "../livro.h"
#include "../buscas/buscas_binarias.h"

typedef struct {
    int num_funcionarios;
    int num_livros;
    double tempo_ms;
} TReport;

//'generate_report.c', essa funcao gera o relatorio.
TReport* generate_report() {
    FILE* LogFileBinary, *employeeFileBinary, *bookFileBinary;
    if ((employeeFileBinary = fopen("./src/bin/window_books.dat", "rb+")) == NULL ||
        (bookFileBinary = fopen("./src/bin/window_employee.dat", "rb+")) == NULL ||
        (LogFileBinary = fopen("./src/bin/window_log.dat", "rb+")) == NULL) {
        printf("Erro ao abrir os arquivos binarios\n");
        exit(1);
    }

    int num_funcionarios = 0;
    int num_livros = 0;
    clock_t start = clock();

    int tam_file_employee = tamanho_arquivo_de_funcionarios(employeeFileBinary);
    int tam_file_book = tamanho_arquivo_de_livros(bookFileBinary);

    printf("\nShell Debug: Tamanho do arquivo de funcionarios: %i\n", tam_file_employee);
    printf("\nShell Debug: Tamanho do arquivo de livros: %i\n", tam_file_book);

    for (int i = 0; i < tam_file_employee; i++) {
        TFunc* f = buscarFuncionario_binariamente(i, employeeFileBinary, tam_file_employee, LogFileBinary);
        if (f != NULL) {
            printf("Funcionario: %i\n", f->cod);
            num_funcionarios++;
        }
    }

    for (int i = 0; i < tam_file_book; i++) {
        TLivro* e = buscarLivro_binariamente(i, bookFileBinary, tam_file_book, LogFileBinary);
        if (e != NULL) {
            printf("Livro: %i\n", e->cod);
            num_livros++;
        }
    }

    fclose(employeeFileBinary);
    fclose(bookFileBinary);
    fclose(LogFileBinary);

    double cpu_time_used = ((double)(clock() - start)) / CLOCKS_PER_SEC;

    TReport* report = (TReport*)malloc(sizeof(TReport));
    if (report == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    report->num_funcionarios = num_funcionarios;
    report->num_livros = num_livros;
    report->tempo_ms = cpu_time_used * 1000;

    printf("\nShell Debug: Report Finished");
    printf("\nShell Debug: Num Funcionarios: %i | Num Livros: %i | Tempo total: %.2f ms\n",
           report->num_funcionarios, report->num_livros, report->tempo_ms);

    return report;
}