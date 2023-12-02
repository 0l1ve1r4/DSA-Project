#ifndef INTERCALACAOBASICO_H_INCLUDED
#define INTERCALACAOBASICO_H_INCLUDED

#include "../configs.h"
#include "../estruturas.h"
#include "classificacao_internas.h"

/**
 * @brief Comparador genérico para as funções de ordenação para a intercalação básica
 * 
 * @param a Ponteiro para o primeiro registro.
 * @param b Ponteiro para o segundo registro.
 * @param tipo Tipo do registro a ser comparado.
 */
int compare_records(const void *a, const void *b, TipoRegistro tipo);

/**
 * @brief Realiza a intercalação básica entre os arquivos de partição das structs TFunc & TLivro.
 * @brief A função de comparação é a compare_records, é feita com Intercalação Balanceada.
 */
void intercalacoes();

void intercalacao_basica_Func();
void intercalacao_basica_Livro();

#endif // INTERCALACAOBASICA_H_INCLUDED