#include "employee.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//---------------------------------------*--------------------------------------

employee_structSize() {
    return sizeof(int)  
           + sizeof(char) * 50 
           + sizeof(char) * 15 
           + sizeof(char) * 11 
           + sizeof(double); 
}

//---------------------------------------*--------------------------------------

employee *new_employee(int cod, char *name, char *cpf, char *birthday, double salary) {
    employee *e = (employee *) malloc(sizeof(employee)); //aloca memoria para o funcionario

    if (e) memset(e, 0, sizeof(employee));
    e->cod = cod;     
    strcpy(e->name, name);
    strcpy(e->cpf, cpf);
    strcpy(e->birthday, birthday);
    e->salary = salary;
    return e;
}

//---------------------------------------*--------------------------------------

void create_random_employee_database(FILE *out, int n) {
    employee **employees = (employee **)malloc(n * sizeof(employee *)); //n é o tamanho desejado do banco de dados
    employee **randomEmployees = (employee **)malloc(n * sizeof(employee *));

    for (int i = 0; i < n; i++) {

        int cod = i;
        char name[] = "Nome do funcionario ";
        char cpf[] = "000.000.000-00";
        char birthday[] = "00/00/0000";
        double salary = rand() % 10000; //Somente o salario e o codigo do funcionario vai ser aleatorio

        employees[i] = new_employee(cod, name, cpf, birthday, salary);
    }

    for (int i = 0; i < n; i++) {       // Coloca randomicamente os funcionarios dentro do array de funcionarios
        int randomIndex = rand() % n;
        while (employees[randomIndex] == NULL) {
            randomIndex = rand() % n;
        }

        randomEmployees[i] = employees[randomIndex];
        employees[randomIndex] = NULL;

        save_employee(randomEmployees[i], out);
    }

    free(employees);
    free(randomEmployees);
}

//---------------------------------------*--------------------------------------

void save_employee(FILE *out, employee *func) {
    fwrite(&func->cod, sizeof(int), 1, out);
    fwrite(func->name, sizeof(char), 50, out); 
    fwrite(func->cpf, sizeof(char), 15, out);  
    fwrite(func->birthday, sizeof(char), 11, out); 
    fwrite(&func->salary, sizeof(double), 1, out);
}

//---------------------------------------*--------------------------------------

employee *read_employee_file(FILE *in) {
    employee *e = (employee *) malloc(sizeof(employee));
    if (0 >= fread(&e->cod, sizeof(int), 1, in)) {
        free(e);
        return NULL;
    }
    fread(e->name, sizeof(char), sizeof(e->name), in);
    fread(e->cpf, sizeof(char), sizeof(e->cpf), in);
    fread(e->birthday, sizeof(char), sizeof(e->birthday), in);
    fread(&e->salary, sizeof(double), 1, in);
    return e;
}

//---------------------------------------*--------------------------------------

void print_employee(employee *e) {
    printf("\n**********************************************");
    printf("\nFuncionario de codigo ");
    printf("%d", e->cod);
    printf("\nNome: ");
    printf("%s", e->name);
    printf("\nCPF: ");
    printf("%s", e->cpf);
    printf("\nData de Nascimento: ");
    printf("%s", e->birthday);
    printf("\nSalario: ");
    printf("%4.2f", e->salary);
    printf("\n**********************************************");
}

//---------------------------------------*--------------------------------------
