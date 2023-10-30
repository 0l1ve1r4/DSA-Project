#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <stdlib.h>
#include <stdio.h>

// Define uma estrutura para representar um funcionário
typedef struct {
    int cod;             // Código do funcionário (chave primária)
    char name[50];       // Nome do funcionário (até 50 caracteres)
    char cpf[15];        // CPF do funcionário no formato "xxx.xxx.xxx-xx"
    char birthday[11];   // Data de nascimento do funcionário no formato "dd/mm/aaaa"
    double salary;       // Salário do funcionário 
} employee;

// Função para retornar o tamanho da estrutura 'employee' em bytes
int employee_structSize();

// Função para criar um novo funcionário com as informações fornecidas e retornar um ponteiro para a estrutura criada
employee *new_employee(int cod, char *name, char *cpf, char *birthday, double salary);

// Função para criar um banco de dados aleatório com 'n' funcionários e escrevê-lo em um arquivo de saída
void create_random_employee_database(FILE *out, int n);

// Função para salvar uma estrutura de funcionário em um arquivo de saída
void save_employee(FILE *out, employee *e); 

// Função para ler uma estrutura de funcionário de um arquivo de entrada
employee *read_employee_file(FILE *in);

// Função para imprimir os detalhes de um funcionário na saída padrão
void print_employee(employee *e);

#endif // EMPLOYEE_H
