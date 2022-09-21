#ifndef TOP5_FUNCOES_H_INCLUDED
#define TOP5_FUNCOES_H_INCLUDED

typedef struct jogador
{
    char nome[30];
    int pontuacao;
}JOGADOR;

void troca(JOGADOR *player1,JOGADOR *player2);
JOGADOR pega_ultimo();



void ordena_jogador(JOGADOR vetor[],int num_elementos);

#endif // TOP5_FUNCOES_H_INCLUDED
