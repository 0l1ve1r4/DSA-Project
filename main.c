#include "library.c"
#include<stdlib.h>

// O void sistemaBiblioteca() esta em library.c

int main(){


    FILE *funcionaryFile, booksFile;


    if ((funcionaryFile = fopen("./bin/funcionarios.dat", "w+b")) == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    sistemaBiblioteca(funcionaryFile);
}
