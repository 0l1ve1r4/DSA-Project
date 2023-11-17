#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../funcionario.h"
#include "../livro.h"
#include "../buscas/buscas_binarias.h"

typedef struct {
    int num_funcionarios;
    int num_livros;
} TReport;

//'generate_report.c', NOT WORKING YET
TReport* generate_report() {
    FILE* LogFileBinary, *employeeFileBinary, *bookFileBinary;
      if ((bookFileBinary = fopen("./src/bin/window_books.dat", "rb+")) == NULL ||
        (employeeFileBinary = fopen("./src/bin/window_employee.dat", "rb+")) == NULL ||
        (LogFileBinary = fopen("./src/bin/window_log.dat", "rb+")) == NULL) {
        perror("Erro ao abrir os arquivos binários");
        exit(EXIT_FAILURE);
    }

    int num_funcionarios = 0;
    int num_livros = 0;
    clock_t start = clock();

    int tam_file_employee = tamanho_arquivo_de_funcionarios(employeeFileBinary);
    int tam_file_book = tamanho_arquivo_de_livros(bookFileBinary);

    printf("\nShell Debug: Tamanho do arquivo de funcionarios: %i\n", tam_file_employee);
    printf("\nShell Debug: Tamanho do arquivo de livros: %i\n", tam_file_book);

    TReport *report = malloc(sizeof(TReport));

    report->num_funcionarios = tam_file_employee;
    report->num_livros = tam_file_book;

    printf("\nShell Debug: Report Finished");
    printf("\nShell Debug: Num Funcionarios: %i | Num Livros: %i\n",
           report->num_funcionarios, report->num_livros);

    return report;
}