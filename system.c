#include "library.c"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void sistemaBiblioteca(){
int opcao;
int funcionaryCode;
double funcionarySalary;
char funcionaryName[50], funcionaryBirthday[11], cpf[15];

    while (1) {
        printf("Selecione uma opção:\n");
        printf("1 - Novo Funcionário\n");
        printf("2 - Novo Livro\n");
        printf("3 - Nova Editora\n");
        printf("4 - Salvar Tudo\n");
        printf("5 - Ler Funcionário\n");
        printf("6 - Ler Livro\n");
        printf("7 - Ler Editora\n");
        printf("8 - Imprimir Funcionário\n");
        printf("9 - Imprimir Livro\n");
        printf("10 - Imprimir Editora\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("\nInsira o codigo do funcionario: "); scanf("%d", &funcionaryCode);
                printf("\nInsira o salario do funcionario: "); scanf("%lf", &funcionarySalary);
                printf("\nInsira o nome do funcionario: "); scanf("%s", &funcionaryName);
                printf("\nInsira a data de nascimento do funcionario: "); scanf("%s", &funcionaryBirthday);
                printf("\nInsira o CPF do funcionario: "); scanf("%s", &cpf);
                
                newFuncionario(funcionaryCode, funcionaryName, cpf, funcionaryBirthday, funcionarySalary);
                break;
            case 2:
                // Código para criar um novo livro
                break;
            case 3:
                // Código para criar uma nova editora
                break;
            case 4:
                // Código para salvar um funcionário em um arquivo
                break;
            case 5:
                // Código para salvar um livro em um arquivo
                break;
            case 6:
                // Código para salvar uma editora em um arquivo
                break;
            case 7:
                // Código para ler um funcionário de um arquivo
                break;
            case 8:
                // Código para ler um livro de um arquivo
                break;
            case 9:
                // Código para ler uma editora de um arquivo
                break;
            case 10:
                // Código para imprimir um funcionário
                break;
            case 11:
                // Código para imprimir um livro
                break;
            case 12:
                // Código para imprimir uma editora
                break;
            case 0:
                printf("Saindo...\n");
                return;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    }




}

int main(){
    sistemaBiblioteca();
}
