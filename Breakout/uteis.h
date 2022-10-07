#ifndef UTEIS_H_INCLUDED
#define UTEIS_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include"raylib.h"
#include"uteis.h"
#define screenWidth 800
#define screenHeight 450
#define TRUE 1
#define FALSE 0
#define NUM_LINHAS 5
#define NUM_COLUNAS 10


typedef struct player
{
    Color cor;
    Rectangle corpo;
    int num_vidas;
    int score;
    Vector2 vel;

}PLAYER;

typedef struct tijolo
{
    Color cor;
    Rectangle corpo;
    int ativo;
    char especial;
}TIJOLO;

typedef struct bola
{
    Vector2 centro;
    Vector2 vel;
    float raio;
    int ativo;
    Color cor;

}BOLA;

//CALCULO DO JOGO

void set_player(PLAYER *player);

void move_player(PLAYER *player);

int acabou_matriz(TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS]);

void game_over(PLAYER *player,int *flag_jogo,int *flag_enter,TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS],BOLA *bola,FILE *arq_nivel,int *nivel);

void set_matriz(TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS],FILE *arq_nivel,int *nivel_c);

void win(PLAYER *player,TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS],BOLA *bola,FILE *arq_nivel,int *nivel);

void lanca_bola(BOLA *bola);

void pause_musica(Music musica,int *flag_musica);

void set_game(PLAYER *player,TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS],BOLA *bola,FILE *arq_nivel,int *nivel); //inicia os elementos do jogo

void calcula_game(PLAYER *player, int *flag_jogo,BOLA *bola,int *flag_enter,TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS],FILE *arq_nivel,int *nivel); //calcula a logica do jogo


//DESENHO DO JOGO
void desenha_player(PLAYER *player);

void desenha_tijolo(TIJOLO tijolo);

char le_cor(FILE *arq); //funcao para ler do arq texto

Color gera_cor(char cor); //recebe char e retorna uma COR

void desenha_tijolo(TIJOLO tijolo);

void desenha_matriz(TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS]);

void desenha_game(PLAYER *player,TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS],BOLA *bola,Music musica,int *flag_musica); //desenha os elementos do jogo


#endif // UTEIS_H_INCLUDED
