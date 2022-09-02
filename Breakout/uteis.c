#include "uteis.h"
#include "raylib.h"

#define screenWidth 1200



void move_player(PLAYER *player)

{

      if(player->x <=screenWidth-player->largura)
      {
          if (IsKeyDown(KEY_RIGHT))
            player->x += 8;
      }

      if (player->x >=0)
      {
          if (IsKeyDown(KEY_LEFT))
            player->x -= 8;
      }

}

void desenha_player(PLAYER *player)
{
    DrawRectangle(player->x,player->y,player->largura,player->altura,RED);
};

void aumenta_player(PLAYER *player)
{
    player->largura=player->largura+5;
}

void set_player(PLAYER *player) //determina a posição inicial do player
{
    player->y=685;
    player->x=550;
    player->largura=120;
    player->altura=25;
    player->num_vidas=5;
}

void desenha_tijolo(TIJOLO tijolo)
{
    DrawRectangle(tijolo.x,tijolo.y,tijolo.largura,tijolo.altura,RED);
}

void desenha_matriz(TIJOLO matriz[][NUM_COLUNAS],int num_linhas)
{
    for(int i=0;i<num_linhas;i++)
    {
        for(int j=0;j<NUM_COLUNAS;j++)
        {
            desenha_tijolo(matriz[i][j]);
        }
    }
}
