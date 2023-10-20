#include "library.c"
#include<stdlib.h>

// O void sistemaBiblioteca() esta em library.c

int main(){


    FILE *funcionaryFile, *booksFile, *editorsFile;


    if ((funcionaryFile = fopen("./bin/funcionarios.dat", "a+")) == NULL 
        || (booksFile = fopen("./bin/books.dat", "a+")) == NULL
        || (editorsFile = fopen("./bin/editFile.dat", "a+")) == NULL
                        ) {
        printf("Erro ao abrir os arquivo binarios\n");
        exit(1);
    }

    else
        sistemaBiblioteca(funcionaryFile, booksFile, editorsFile);
}
