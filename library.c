#include "library.h"

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

int tamanho_TFunc() {
    return sizeof(int)  //cod
           + sizeof(char) * 50 //nome
           + sizeof(char) * 15 //cpf
           + sizeof(char) * 11 //data_nascimento
           + sizeof(double); //salario
}

int tamanho_TEdit(){
    return sizeof(char)*50; //Nome

}

int tamaho_TLivro(){
    return sizeof(int) //cod
        + sizeof(char) * 50 //nome
        + sizeof(char) * 11 //data_lançamento
        + tamanho_TEdit(); //Editora do livro
}

//---------------------------------------*--------------------------------------

// Cria funcionario. 
TFunc *newFuncionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario) {
    TFunc *func = (TFunc *) malloc(sizeof(TFunc)); //inicializa espaco de memoria com ZEROS

    if (func) memset(func, 0, sizeof(TFunc));
    func->cod = cod;        //copia valores para os campos de func
    strcpy(func->nome, nome);
    strcpy(func->cpf, cpf);
    strcpy(func->data_nascimento, data_nascimento);
    func->salario = salario;
    return func;
}

void criarFuncAleatorias(int x, FILE *out) {
    TFunc **employees = (TFunc **)malloc(x * sizeof(TFunc *));
    TFunc **randomEmployees = (TFunc **)malloc(x * sizeof(TFunc *));

    for (int i = 0; i < x; i++) {
        // Generate employee parameters
        int cod = i;
        char nome[] = "FuncionarioName ";
        char cpf[] = "0000000000";
        char data_nascimento[] = "00/00/0000";
        double salario = rand() % 10000;

        // Create the employee and add it to the array
        employees[i] = newFuncionario(cod, nome, cpf, data_nascimento, salario);
    }

    // Randomly shuffle the employees into the randomEmployees array
    for (int i = 0; i < x; i++) {
        int randomIndex = rand() % x;
        while (employees[randomIndex] == NULL) {
            randomIndex = rand() % x;
        }

        randomEmployees[i] = employees[randomIndex];
        employees[randomIndex] = NULL;
        // Ensure that the 'salvaFunc' function is properly defined and saves the employee to the 'out' file.
        salvaFunc(randomEmployees[i], out);
    }

    free(employees);
    free(randomEmployees);
}


//Criar livro
TLivro *newLivro(int cod, char *nome, char *data_lancamento, TEdit editora) {
    TLivro *livro = (TLivro *)malloc(sizeof(TLivro));
        if (livro) memset(livro, 0, sizeof(TLivro));
        livro->cod = cod;
        strcpy(livro->nome, nome);
        strcpy(livro->data_lancamento, data_lancamento);
        livro->editora = editora;
    
    return livro;
}

//Criar editora
TEdit *newEditora(char *nome) {
    TEdit *editora = (TEdit *)malloc(sizeof(TEdit));
    if (editora) {
        strcpy(editora->nome, nome);
    }
    return editora;
}



//---------------------------------------*--------------------------------------


// Salva funcionario no arquivo out, na posicao atual do cursor
void salvaFunc(TFunc *func, FILE *out) {
    fwrite(&func->cod, sizeof(int), 1, out);
    fwrite(func->nome, sizeof(char), 50, out); // Specify the size of the name field
    fwrite(func->cpf, sizeof(char), 15, out);   // Specify the size of the CPF field
    fwrite(func->data_nascimento, sizeof(char), 11, out); // Specify the size of the data_nascimento field
    fwrite(&func->salario, sizeof(double), 1, out);
}

void salvaLivro(TLivro *livro, FILE *out) {
    fwrite(&livro->cod, sizeof(int), 1, out);
    fwrite(livro->nome, sizeof(char), sizeof(livro->nome), out);
    fwrite(livro->data_lancamento, sizeof(char), sizeof(livro->data_lancamento), out);
    salvaEdit(&livro->editora, out);
}

void salvaEdit(TEdit *editora, FILE *out) {
    fwrite(editora->nome, sizeof(char), sizeof(editora->nome), out);
}

//---------------------------------------*--------------------------------------


// Le um funcionario do arquivo in na posicao atual do cursor
// Retorna um ponteiro para funcionario lido do arquivo
TFunc *leFunc(FILE *in) {
    TFunc *func = (TFunc *) malloc(sizeof(TFunc));
    if (0 >= fread(&func->cod, sizeof(int), 1, in)) {
        free(func);
        return NULL;
    }
    fread(func->nome, sizeof(char), sizeof(func->nome), in);
    fread(func->cpf, sizeof(char), sizeof(func->cpf), in);
    fread(func->data_nascimento, sizeof(char), sizeof(func->data_nascimento), in);
    fread(&func->salario, sizeof(double), 1, in);
    return func;
}

TEdit *leEdit(FILE *in) {
    TEdit *editora = (TEdit *)malloc(sizeof(TEdit));
    if (editora) {
        fread(editora->nome, sizeof(char), sizeof(editora->nome), in);
    }
    return editora;
}

TLivro *leLivro(FILE *in) {
    TLivro *livro = (TLivro *)malloc(sizeof(TLivro));
    if (livro) {
        fread(&livro->cod, sizeof(int), 1, in);
        fread(livro->nome, sizeof(char), sizeof(livro->nome), in);
        fread(livro->data_lancamento, sizeof(char), sizeof(livro->data_lancamento), in);
        livro->editora = *leEdit(in);
    }
    return livro;
}

//---------------------------------------*--------------------------------------


// Imprime funcionario
void imprimeFunc(TFunc *func) {
    printf("**********************************************");
    printf("\nFuncionario de codigo ");
    printf("%d", func->cod);
    printf("\nNome: ");
    printf("%s", func->nome);
    printf("\nCPF: ");
    printf("%s", func->cpf);
    printf("\nData de Nascimento: ");
    printf("%s", func->data_nascimento);
    printf("\nSalario: ");
    printf("%4.2f", func->salario);
    printf("\n**********************************************");
}

void imprimeEdit(TEdit *editora) {
    printf("Editora: %s\n", editora->nome);
}

void imprimeLivro(TLivro *livro) {
    printf("Nome: %s | Codigo: %d\n",livro->nome, livro->cod);
    printf("Lancamento: %s | Editora: %s\n", livro->data_lancamento, livro->editora.nome);

}


