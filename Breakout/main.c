#include "uteis.h"
#include "raylib.h"
#include "top5_funcoes.h"
#include"menu_principal.h"
#include"bola.h"
#define screenWidth 800
#define screenHeight 450
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "uteis.h"
#define screenWidth 800
#define screenHeight 450
#define TRUE 1
#define FALSE 0
#define NUM_LINHAS 5
#define NUM_COLUNAS 10


int main()
{
    BOTAO botao_jogar;
    botao_jogar.altura=50;
    botao_jogar.largura=100;
    botao_jogar.cor=RED;
    botao_jogar.pos_x=350;
    botao_jogar.pos_y=250;

    BOTAO botao_top5;
    botao_top5.altura=50;
    botao_top5.largura=100;
    botao_top5.cor=RED;
    botao_top5.pos_x=350;
    botao_top5.pos_y=305;


    int flag_jogo=0;
    int flag_over=0;
    int flag_enter=0;
    int flag_maior=0;
    int flag_musica;
    int conta_letras=0;
    int nivel=0;
    TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS];
    JOGADOR melhoress[5];
    FILE *melhores;
    FILE *niveis;
    PLAYER player;
    BOLA bola;
    Music musica;


    InitWindow(screenWidth, screenHeight, "BREAKOUT");
    InitAudioDevice();
    musica=LoadMusicStream("resources/megalovania.mp3");
    PlayMusicStream(musica);

    set_game(&player,matriz,&bola,niveis,&nivel);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {

       pause_musica(musica,&flag_musica);

        calcula_menuP(&botao_jogar,&botao_top5);
        desenha_menuP(botao_jogar,botao_top5);


        if(clica_botao(&botao_jogar)==1)
        {
            flag_jogo=1;
        }

        while(flag_jogo==1)
        {
            jogo(&player,&flag_jogo,&flag_over,matriz,&bola,&flag_enter,&conta_letras,&flag_maior,musica,&flag_musica,niveis,&nivel);
        }

        if(clica_botao(&botao_top5))
        {
            while(!WindowShouldClose())
            {
                desenha_menu5(melhores,musica,&flag_musica);
            }
        }

    }

    UnloadMusicStream(musica);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}

