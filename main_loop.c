#include "main_loop.h"


void init_main_loop(){

    FILE *funcionaryFile, *booksFile, *editorsFile;


    if ((funcionaryFile = fopen("./bin/funcionarios.dat", "a+")) == NULL 
        || (booksFile = fopen("./bin/books.dat", "a+")) == NULL
        || (editorsFile = fopen("./bin/editFile.dat", "a+")) == NULL
                        ) {
        printf("Erro ao abrir os arquivo binarios\n");
        exit(1);
    }

    else
        main_loop(funcionaryFile, booksFile, editorsFile);



}

void main_loop(FILE *funcionaryFile, FILE *booksFile, FILE *editorsFile){
    int option, funcionaryCode, bookCode;
    char bookName[50], launchDate[11], publisherName[50], funcionaryName[50], funcionaryBirthday[11], cpf[15];
    double funcionarySalary;

    while (1) {
        printf("1 - New Employee\n");
        printf("2 - New Book\n");
        printf("3 - New Publisher\n");
        printf("4 - Search Employee\n");
        printf("5 - Search Book\n");
        printf("0 - Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter employee code: "); scanf("%d", &funcionaryCode);
                printf("\nEnter employee salary: "); scanf("%lf", &funcionarySalary);

                printf("\nEnter employee name: ");
                fflush(stdin);
                fgets(funcionaryName, 50, stdin);

                printf("\nEnter employee birth date: ");
                fflush(stdin);
                fgets(funcionaryBirthday, 11, stdin);

                printf("\nEnter employee CPF: ");
                fflush(stdin);
                fgets(cpf, 15, stdin);

                TFunc *temp = newFuncionario(funcionaryCode, funcionaryName, cpf, funcionaryBirthday, funcionarySalary);
                salvaFunc(temp, funcionaryFile);

                free(temp);
                break;

            case 2:
                printf("\nEnter book code: "); scanf("%d", &bookCode);
                printf("\nEnter book name: ");
                fflush(stdin);
                fgets(bookName, 50, stdin);

                printf("\nEnter launch date: ");
                fgets(launchDate, 11, stdin);
                fflush(stdin);

                printf("\nEnter publisher name: ");
                fflush(stdin);
                fgets(publisherName, 50, stdin);

                TEdit *publisherBook = newEditora(publisherName);

                TLivro *book = newLivro(bookCode, bookName, launchDate, *publisherBook);

                salvaLivro(book, booksFile);

                free(book);

                break;

            case 3:
                printf("\nEnter publisher name: ");
                scanf("%s", publisherName);

                TEdit *publisher = newEditora(publisherName);

                salvaEdit(publisher, editorsFile);

                free(publisher);
                break;

            case 4:
                printf("\nEnter employee code: "); scanf("%d", &funcionaryCode);
                findFuncionary(funcionaryFile, funcionaryCode);
                break;

            case 5:
                printf("\nEnter book code: "); scanf("%d", &bookCode);
                findBook(booksFile, bookCode);
                system("pause");
                break;

            case 0:
                printf("Exiting...\n");
                return;

            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }
}
