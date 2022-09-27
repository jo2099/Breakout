#include "uteis.h"
#include "raylib.h"
#include "top5_funcoes.h"
#include"menu_principal.h"
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



int calc_faixa_y(BOLA *bola,Rectangle retangulo)
{
    int faixa_y=0;

    if(((bola->centro.y+bola->raio)>retangulo.y) && (bola->centro.y-bola->raio) < retangulo.y + retangulo.height)
        faixa_y=1;

    if(faixa_y)
    {
        return 1;
    }
    else
        return 0;

}

void funcao_bola (BOLA *bola,PLAYER *player,TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS])
{

    bola->centro.x += bola->vel.x;
    bola->centro.y += bola->vel.y;

    if((bola->centro.x >= (screenWidth - bola->raio)) || (bola->centro.x <= bola->raio)) bola->vel.x *= -1.0f;
    if((bola->centro.y >= (screenHeight - bola->raio)) || (bola->centro.y <= bola->raio)) bola->vel.y *= -1.0f;

//colisao com o player
    /*if(CheckCollisionCircleRec(bola->centro,bola->raio,player->corpo))
    {
        if(calc_faixa_y(bola,player->corpo))
        {
            bola->vel.x=player->vel.x;
            bola->vel.x *=-1;
        }
        else
            bola->vel.y *=-1;
    }
*/

if(CheckCollisionCircleRec(bola->centro,bola->raio,player->corpo))
{

    if(bola->vel.y>0)
    {

        bola->vel.y*=-1;
        //bola->vel.x=(bola->centro.x - player->corpo.x)/((player->corpo.width/2)*5);

    }
}

for(int i=0;i<NUM_LINHAS;i++)
{
    for(int j=0;j<NUM_COLUNAS;j++)
    {
        if(CheckCollisionCircleRec(bola->centro,bola->raio,matriz[i][j].corpo) && matriz[i][j].ativo)
        {
            bola->vel.y *=-1;
            matriz[i][j].ativo=0;
            player->score+=20;

        }
    }
}







}
