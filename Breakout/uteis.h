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
}TIJOLO;

typedef struct bola
{
    Vector2 centro;
    Vector2 vel;
    float raio;
    int ativo;
    Color cor;

}BOLA;

void desenha_player(PLAYER *player);

void move_player(PLAYER *player);

void aumenta_player(PLAYER *player);

void desenha_tijolo(TIJOLO tijolo);

void desenha_matriz(TIJOLO matriz[][NUM_COLUNAS],int num_linhas);

void set_game(PLAYER *player,TIJOLO matriz[][NUM_COLUNAS],int num_linhas,BOLA *bola); //inicia os elementos do jogo

void calcula_game(PLAYER *player, int *flag_jogo,BOLA *bola,int *flag_enter,TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS]); //calcula a logica do jogo

void desenha_game(PLAYER *player,TIJOLO matriz[][NUM_COLUNAS],int num_linhas,BOLA *bola,Music musica); //desenha os elementos do jogo

void diminui_vidas(PLAYER *player);

#endif // UTEIS_H_INCLUDED
