#ifndef INTERCALACAO_H_INCLUDED
#define INTERCALACAO_H_INCLUDED

#include "../estruturas.h"

typedef struct{

    float tempo;
    int num_registro_per_partition;
    int num_partitions;
} intercalacao_otima_struct;


/**
 * @brief Comparador genérico para as funções de ordenação para a intercalação básica
 * 
 * @param a Ponteiro para o primeiro registro.
 * @param b Ponteiro para o segundo registro.
 * @param tipo Tipo do registro a ser comparado.
 */
int compare_records(const void *a, const void *b, TipoRegistro tipo);



void intercalacao_otima_Func();
void intercalacao_otima_Livro();
/**
 * @brief Realiza as intercalações ótimas chamando as funções específicas para cada tipo de registro. */
void intercalacoes_otimas();


intercalacao_otima_struct* save_intercalacao_otima_struct(int num_partitions, int num_registro_per_partition, float tempo);
#endif // INTERCALACAOBASICA_H_INCLUDEDcls
