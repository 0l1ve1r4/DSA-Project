#include "library.c"


// O void sistemaBiblioteca() esta em library.c

int main(){


    FILE *funcionaryFile, booksFile;


    //abre arquivo na pasta bin (binarios)
    funcionaryFile = fopen("./bin/funcionarios.dat", "w+b") == NULL ? printf("\nAberto com sucesso."): printf("\nErro ao abrir arquivo");

    sistemaBiblioteca(funcionaryFile);
}
