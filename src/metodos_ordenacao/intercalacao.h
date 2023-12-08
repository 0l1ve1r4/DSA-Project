#ifndef INTERCALACAO_H_INCLUDED
#define INTERCALACAO_H_INCLUDED

#include "../configs.h"
#include "../estruturas.h"

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

#endif // INTERCALACAOBASICA_H_INCLUDEDcls
