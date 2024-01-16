#ifndef CLASSIFICACAO_H
#define CLASSIFICACAO_H
#include "../estruturas.h"


typedef struct{

    float tempo;
    int num_registro_per_partition;
    int num_partitions;
} classificacao_struct;

int classificacao_interna_Func(int M);
int classificacao_interna_Livro(int M);
void classificacoes(int M);

#endif
