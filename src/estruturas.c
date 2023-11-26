#include "estruturas.h"

int tamanho_registro_funcionario() {
    TFunc *temp;
    return sizeof(temp->cod) 
           + sizeof(temp->nome) 
           + sizeof(temp->cpf) 
           + sizeof(temp->data_nascimento) 
           + sizeof(temp->salario); 
}

TFunc *criar_funcionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario) {
    TFunc *func = (TFunc *) malloc(sizeof(TFunc));
    if (func) memset(func, 0, sizeof(TFunc));
    func->cod = cod;
    strcpy(func->nome, nome);
    strcpy(func->cpf, cpf);
    strcpy(func->data_nascimento, data_nascimento);
    func->salario = salario;
    return func;
}


void salvar_funcionario(TFunc *func, FILE *out) {
    fwrite(&func->cod, sizeof(int), 1, out);
    fwrite(func->nome, sizeof(char), sizeof(func->nome), out);
    fwrite(func->cpf, sizeof(char), sizeof(func->cpf), out);
    fwrite(func->data_nascimento, sizeof(char), sizeof(func->data_nascimento), out);
    fwrite(&func->salario, sizeof(double), 1, out);

    printf("\nShell Debug: Funcionario salvo com sucesso!\n");
}

int tamanho_arquivo_de_funcionarios(FILE *arq) {
    fseek(arq, 0, SEEK_END);
    int tam = trunc(ftell(arq) / tamanho_registro_funcionario());
    return tam;
}


TFunc *ler_arquivo_funcionario(FILE *in) {
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


void imprimir_funcionario(TFunc *func) {
    printf("Shell Debug: Funcionario de codigo %d | Nome: %s | CPF: %s | Data de Nascimento: %s | Salario: %.2f\n", 
    func->cod, func->nome, func->cpf, func->data_nascimento, func->salario);

}

void criarBase_funcionarios(FILE *out, int tam){

    int vet[tam];
    TFunc *f;

    for(int i=0;i<tam;i++)
        vet[i] = i+1;

    shuffle_funcionarios(vet, tam);

    for (int i=0;i<tam;i++){
        f = criar_funcionario(vet[i], "XXXXXXXXXX", "000.000.000-00", "00/00/0000", 0);
        salvar_funcionario(f, out);
    }

    free(f);

}

void criarBase_funcionarios_Binario(FILE *out, int tam){

    int vet[tam];
    TFunc *f;

    for(int i=0;i<tam;i++)
        vet[i] = i+1;

    for (int i=0;i<tam;i++){
        f = criar_funcionario(vet[i], "XXXXXXXXXX", "000.000.000-00", "00/00/0000", 0);
        salvar_funcionario(f, out);
    }

    free(f);

}

void shuffle_funcionarios(int *vet, int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = vet[j];
        vet[j] = vet[i];
        vet[i] = tmp;
    }
}

void imprimirBase_funcionarios(FILE *out){
    
    rewind(out);
    TFunc *f;
    while ((f = ler_arquivo_funcionario(out)) != NULL)
        imprimir_funcionario(f);
    free(f);

}


int tamanho_registro_livro() {
    TLivro *temp;
    return sizeof(temp->cod)
           + sizeof(temp->nome)
           + sizeof(temp->numero_paginas)
           + sizeof(temp->autor)
           + sizeof(temp->editora)
           + sizeof(temp->data_emprestimo)
           + sizeof(temp->preco)
           + sizeof(temp->funcionario)
           + sizeof(temp->cliente);
}

TLivro *criar_livro(int cod, char *nome, char *numero_paginas, char *autor, char *editora, char *data_emprestimo, double preco, TFunc *funcionario, TCliente *cliente) {
    TLivro *livro = (TLivro *) malloc(sizeof(TLivro));
    if (livro) memset(livro, 0, sizeof(TLivro));
    livro->cod = cod;
    strcpy(livro->nome, nome);
    strcpy(livro->numero_paginas, numero_paginas);
    strcpy(livro->autor, autor);
    strcpy(livro->editora, editora);
    strcpy(livro->data_emprestimo, data_emprestimo);
    livro->preco = preco;

    livro->funcionario = funcionario;
    livro->cliente = cliente;

    printf("Shell Debug: Livro criado com sucesso.\n");
    return livro;
}

void salvar_livro(TLivro *livro, FILE *out) {
    fwrite(&livro->cod, sizeof(int), 1, out);
    fwrite(livro->nome, sizeof(char), sizeof(livro->nome), out);
    fwrite(livro->numero_paginas, sizeof(char), sizeof(livro->numero_paginas), out);
    fwrite(livro->autor, sizeof(char), sizeof(livro->autor), out);
    fwrite(livro->editora, sizeof(char), sizeof(livro->editora), out);
    fwrite(livro->data_emprestimo, sizeof(char), sizeof(livro->data_emprestimo), out);
    fwrite(&livro->preco, sizeof(double), 1, out);
    fwrite(livro->funcionario, sizeof(TFunc), 1, out);
    fwrite(livro->cliente, sizeof(TCliente), 1, out);

    printf("Shell Debug: Livro salvo com sucesso. cod: %i\n", livro->cod);

}

int tamanho_arquivo_de_livros(FILE *arq) {
    fseek(arq, 0, SEEK_END);
    int tam = ftell(arq) / tamanho_registro_livro();
    return tam;
}

TLivro *ler_arquivo_livro(FILE *in) {
    TLivro *livro = (TLivro *) malloc(sizeof(TLivro));
    if (0 >= fread(&livro->cod, sizeof(int), 1, in)) {
        free(livro);
        return NULL;
    }
    fread(livro->nome, sizeof(char), sizeof(livro->nome), in);
    fread(livro->numero_paginas, sizeof(char), sizeof(livro->numero_paginas), in);
    fread(livro->autor, sizeof(char), sizeof(livro->autor), in);
    fread(livro->editora, sizeof(char), sizeof(livro->editora), in);
    fread(livro->data_emprestimo, sizeof(char), sizeof(livro->data_emprestimo), in);
    fread(&livro->preco, sizeof(double), 1, in);
    return livro;
}

void imprimir_livro(TLivro *livro) {
    printf("Shell Debug: Livro de codigo %d | Nome: %s | Numero de Paginas: %s | Autor: %s | Editora: %s | Data de Emprestimo: %s | Preco: %.2f\n",
           livro->cod, livro->nome, livro->numero_paginas, livro->autor, livro->editora, livro->data_emprestimo, livro->preco);
}

/*void criarBase_livros(FILE *out, int tam) {
    int vet[tam];
    TLivro *livro;

    for (int i = 0; i < tam; i++)
        vet[i] = i + 1;

    shuffle_livros(vet, tam);

    printf("\nShell Debug: Gerando a base de dados de livros\n");

    for (int i = 0; i < tam; i++) {
        livro = criar_livro(vet[i], "XXXXXXXXXX", "0", "Autor Desconhecido", "Editora Desconhecida", "00/00/0000", 0);
        salvar_livro(livro, out);
    }

    free(livro);
}


void criarBase_livros_Binario(FILE *out, int tam) {
    int vet[tam];
    TLivro *livro;

    for (int i = 0; i < tam; i++)
        vet[i] = i + 1;

    printf("\nShell Debug: Gerando a base de dados de livros...\n");

    for (int i = 0; i < tam; i++) {
        livro = criar_livro(vet[i], "XXXXXXXXXX", "0", "Autor Desconhecido", "Editora Desconhecida", "00/00/0000", 0);
        salvar_livro(livro, out);
    }

    printf("\nShell Debug: Base de dados de livros gerada com sucesso!\n");

    free(livro);
}*/

void shuffle_livros(int *vet, int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = vet[j];
        vet[j] = vet[i];
        vet[i] = tmp;
    }
}

void imprimirBase_livros(FILE *out) {
    rewind(out);
    TLivro *livro;
    while ((livro = ler_arquivo_livro(out)) != NULL)
        imprimir_livro(livro);
    free(livro);
}
