#include <stdio.h>
#include <stdlib.h>
#include "funcionario.c"


int main()
{
    //declara ponteiro para arquivo
    FILE *out;


    //abre arquivo
    if ((out = fopen("funcionario.dat", "w+b")) == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    else {

        // Inserindo funcionarios no arquivo

        TFunc *f;
        f = funcionario(1, "Ana", "000.000.000-00", "01/01/1980", 3000);
        salva(f, out);

        f = funcionario(2, "Carlos", "111.111.111-11", "01/01/1990", 500);
        salva(f, out);

        f = funcionario(3, "Fatima", "222.222.222-22", "02/02/1980", 1000);
        salva(f, out);

        f = funcionario(4, "Marcelo", "333.333.333-33", "03/03/1990", 1500);
        salva(f, out);

        f = funcionario(5, "Silvia", "444.444.444-44", "04/04/1980", 900);
        salva(f, out);


        //lendo funcionarios do arquivo
        printf("\n\nLendo funcionarios do arquivo...\n\n");
        rewind(out);

        while ((f = le(out)) != NULL) {
            imprime(f);
        }

        system("pause");
        system("cls");


        //le segundo_funcionario do arquivo
        printf("\n\nLendo segundo funcionario do arquivo...\n\n");

        //tamanho_registro() indica quantos bytes vamos pular, o que aqui � igual ao tamanho de um registro
        //(vamos pular o primeiro e nos posicionar no inicio do segundo)
        //** ATEN��O, n�o usar sizeof(Funcionario), pois ele pode retornar valor maior que o tamanho ocupado em disco
        //SEEK_SET indica o inicio do arquivo
        //ao final, o cursor estara� posicionado em 0 + tamanho_registro() +1

        fseek(out, tamanho_registro(), SEEK_SET);
        f = le(out);

        if (f != NULL) {
            imprime(f);
        }

        system("pause");
        system("cls");

        //Adicionando funcionario no final do arquivo
        printf("\n\nAdicionando funcionario no final do arquivo...\n\n");
        //pula 5 registros para posicionar no inicio do final do arquivo
        fseek(out, tamanho_registro() * 5, SEEK_SET);
        f = funcionario(6, "Bruna", "666.666.666-66", "06/06/1980", 2500);
        salva(f, out);

        //lendo funcionarios do arquivo
        printf("\n\nLendo funcionarios do arquivo...\n\n");
        rewind(out);

        while ((f = le(out)) != NULL) {
            imprime(f);
        }

        system("pause");
        system("cls");


        //Sobrescreve o quarto_funcionario
        printf("\n\nSobrescrevendo quarto funcionario do arquivo...\n\n");
        //pula primeiros 3 registros para posicionar no inicio do quarto registro
        fseek(out, tamanho_registro() * 3, SEEK_SET);
        f = funcionario(7,"Catarina", "777.777.777-77", "07/07/1990", 5000);
        salva(f, out);

        //lendo funcionarios do arquivo
        printf("\n\nLendo funcionarios do arquivo...\n\n");
        rewind(out);

        while ((f = le(out)) != NULL) {
            imprime(f);
        }

        free(f);

    }


    return 0;
}