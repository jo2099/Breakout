#ifndef TOP5_FUNCOES_H_INCLUDED
#define TOP5_FUNCOES_H_INCLUDED
#include"uteis.h"

typedef struct jogador
{
    char nome[30];
    int pontuacao;
}JOGADOR;

void troca(JOGADOR *player1,JOGADOR *player2);

void tela_pede_nome(char nome[30]);

void lista_default(JOGADOR vet[5]);

void novo_jogador(PLAYER *player,char nome[30]);

void desenha_menu5(FILE *pt_arq,Music musica,int*flag_musica);

void set_lista(JOGADOR vet[5],FILE *pt_arq);

void ordena_jogador(JOGADOR vetor[],int num_elementos);

JOGADOR pega_ultimo();



void ordena_jogador(JOGADOR vetor[],int num_elementos);

#endif // TOP5_FUNCOES_H_INCLUDED
