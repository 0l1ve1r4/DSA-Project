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


//---------------------------------------*--------------------------------------


// Salva funcionario no arquivo out, na posicao atual do cursor
void salvaFunc(TFunc *func, FILE *out) {
    fwrite(&func->cod, sizeof(int), 1, out);
    //func->nome ao inves de &func->nome, pois string ja eh um ponteiro
    fwrite(func->nome, sizeof(char), sizeof(func->nome), out);
    fwrite(func->cpf, sizeof(char), sizeof(func->cpf), out);
    fwrite(func->data_nascimento, sizeof(char), sizeof(func->data_nascimento), out);
    fwrite(&func->salario, sizeof(double), 1, out);
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


void findFuncionary(FILE *in, int code) {
    TFunc *func;
    int comparison = 0;
    int found = 0;
    clock_t start, end;
    double cpu_time_used;

    rewind(in); 
    start = clock();

    while ((func = leFunc(in)) != NULL) {
        comparison++;
        if (func->cod == code) {
            found = 1;
            imprimeFunc(func); 
            free(func); 
            break; 
        }
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    if (found == 1) {
        printf("\nBusca Sequencial...");
        printf("\nNumero de comparacoes realizadas: %d\n", comparison);
        printf("Tempo gasto: %f segundos\n", cpu_time_used);
    }else{
        printf("Employee with code %d not found.\n", code);
    }
}

void findBook(FILE *in, int code) {
    TLivro *livro;
    int comparison = 0;
    clock_t start, end;
    double cpu_time_used;

    rewind(in);
    start = clock();

    while ((livro = leLivro(in)) != NULL) {
        comparison++;
        if (livro->cod == code) {
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Busca sequecial finalizada...");
            printf("\nNumero de comparacoes: %d | Tempo: %f \n", comparison, cpu_time_used);
            imprimeLivro(livro);
            free(livro);
            return;
        }
    } printf("Book with code %d not found.\n", code);
    }



//Criar editora
TEdit *newEditora(char *nome) {
    TEdit *editora = (TEdit *)malloc(sizeof(TEdit));
    if (editora) {
        strcpy(editora->nome, nome);
    }
    return editora;
}

void salvaEdit(TEdit *editora, FILE *out) {
    fwrite(editora->nome, sizeof(char), sizeof(editora->nome), out);
}

TEdit *leEdit(FILE *in) {
    TEdit *editora = (TEdit *)malloc(sizeof(TEdit));
    if (editora) {
        fread(editora->nome, sizeof(char), sizeof(editora->nome), in);
    }
    return editora;
}

void imprimeEdit(TEdit *editora) {
    printf("Editora: %s\n", editora->nome);
}

void salvaLivro(TLivro *livro, FILE *out) {
    fwrite(&livro->cod, sizeof(int), 1, out);
    fwrite(livro->nome, sizeof(char), sizeof(livro->nome), out);
    fwrite(livro->data_lancamento, sizeof(char), sizeof(livro->data_lancamento), out);
    salvaEdit(&livro->editora, out);
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

void imprimeLivro(TLivro *livro) {
    printf("Nome: %s | Codigo: %d\n",livro->nome, livro->cod);
    printf("Lancamento: %s | Editora: %s\n", livro->data_lancamento, livro->editora.nome);

}


void sistemaBiblioteca(FILE *arquivoFuncionarios, FILE *arquivoLivros, FILE *arquivoEditoras){
int opcao;
int funcionaryCode, bookCode;
char bookName[50], launchBook[11], publisherName[50];
double funcionarySalary;
char funcionaryName[50], funcionaryBirthday[11], cpf[15];

    while (1) {
        printf("\nSelecione uma opcao:\n");
        printf("1 - Novo Funcionario\n");
        printf("2 - Novo Livro\n");
        printf("3 - Nova Editora\n");
        printf("4 - Buscar Funcionario\n");
        printf("5 - Buscar Livro\n");
        printf("8 - Imprimir Funcionario\n");
        printf("9 - Imprimir Livro\n");
        printf("10 - Imprimir Editora\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) { // Funcionando
            case 1:
                printf("\nInsira o codigo do funcionario: "); scanf("%d", &funcionaryCode);
                printf("\nInsira o salario do funcionario: "); scanf("%lf", &funcionarySalary);

                printf("\nInsira o nome do funcionario: ");
                fflush(stdin);
                fgets(funcionaryName,50,stdin);

                printf("\nInsira a data de nascimento do funcionario: ");
                fflush(stdin);
                fgets(funcionaryBirthday,11,stdin);

                printf("\nInsira o CPF do funcionario: ");
                fflush(stdin);
                fgets(cpf,15,stdin);
                
                TFunc *temp = newFuncionario(funcionaryCode, funcionaryName, cpf, funcionaryBirthday, funcionarySalary);
                salvaFunc(temp, arquivoFuncionarios);
                
                free(temp);
                break;

            case 2:
                printf("\nInsira o codigo do livro: "); scanf("%d",&bookCode);
                printf("\nInsira o nome do livro: "); 
                fflush(stdin);
                fgets(bookName,50,stdin);

                printf("\nInsira a data de lancamento: "); 
                fgets(launchBook,11,stdin);
                fflush(stdin);

                printf("\nInsira o nome da editora: ");
                fflush(stdin);
                fgets(publisherName,50,stdin);
                
                TEdit *publisherBook = newEditora(publisherName);
    
                TLivro *book = newLivro(bookCode, bookName, launchBook, *publisherBook);

                salvaLivro(book, arquivoLivros);

                free(book);
                
                break;
            case 3:
                printf("\nInsira o nome da editora: ");
                scanf("%s", publisherName);

                TEdit *publisher = newEditora(publisherName);

                salvaEdit(publisher, arquivoEditoras);

                free(publisher);
                break;
            case 4: // Funcionando
                printf("\nInsira o codigo do funcionario: "); scanf("%d", &funcionaryCode);
                findFuncionary(arquivoFuncionarios,funcionaryCode);
                break;
            case 5:
                printf("\nInsira o codigo do livro: "); scanf("%d", &bookCode);
                findBook(arquivoLivros,bookCode);
                system("pause");
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