#include "intercalacaoBasico.h"
/*
void intercalacao_basica(FILE *out, int num_p){

    typedef struct vetor{
        TFunc *fun;
        FILE *f;
    }TVet;

    int fim = 0; //variavel que controla fim do procedimento
    int particao = 0;
    char *nome[20];


        //cria vetor de particoes
        TVet v[num_p];

        //abre arquivos das particoes, colocando variavel de arquivo no campo f do vetor
        //e primeiro funcionario do arquivo no campo func do vetor
        for (int i=0; i < num_p; i++) {

            sprintf(nome, "partition%i.dat", particao);

            //printf("%s",nome);

            v[i].f = fopen(nome, "rb");
            //v[i].aux_p = 0;

            if (v[i].f != NULL) {
                //fseek(v[i].f, v[i].aux_p * tamanho(), SEEK_SET);
                TFunc *f = le(v[i].f);
                if (f == NULL) {
                    //arquivo estava vazio
                    //coloca HIGH VALUE nessa posi??o do vetor
                    v[i].fun = funcionario(INT_MAX, "","","",0);
                }
                else {
                    //conseguiu ler funcionario, coloca na posi??o atual do vetor
                    v[i].fun = f;
                }
            }
            else {
                fim = 1;
            }

            particao++;
        }

        //int aux = 0;

        while (!(fim)) { //conseguiu abrir todos os arquivos
            int menor = INT_MAX;
            int pos_menor;
            //encontra o funcionario com menor chave no vetor
            for(int i = 0; i < num_p; i++){
                if(v[i].fun->cod < menor){
                    menor = v[i].fun->cod;
                    pos_menor = i;
                }
            }
            if (menor == INT_MAX) {
                fim = 1; //terminou processamento
            }
            else {
                //salva funcionario no arquivo de saída
                //fseek(out, aux * tamanho(), SEEK_SET);
                salva(v[pos_menor].fun, out);
                //printf("%d ",pos_menor);
                //atualiza posição pos_menor do vetor com pr?ximo funcionario do arquivo
                //v[pos_menor].aux_p++;
                //fseek(v[pos_menor].f, v[pos_menor].aux_p * tamanho(), SEEK_SET);
                TFunc *f = le(v[pos_menor].f);
                //aux++;
                if (f == NULL) {
                    //arquivo estava vazio
                    //coloca HIGH VALUE nessa posiçao do vetor
                    v[pos_menor].fun = funcionario(INT_MAX, "", "", "",0.0);
                }
                else {
                    v[pos_menor].fun = f;
                }

            }
        }

        //fecha arquivos das partiÇões de entrada
        for(int i = 0; i < num_p; i++){
            fclose(v[i].f);
        //    free(v[i].func);
        }
        //fecha arquivo de saída
        //fclose(out);


}*/