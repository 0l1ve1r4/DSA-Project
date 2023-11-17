#include <stdio.h>
#include <stdlib.h>

//'utils.c', essa funcao retorna o caminho atual do programa.
void get_current_path(){
    printf("\nShell Debug: Caminho atual do programa: ");
    system("echo %cd%");
    printf("\n");
}