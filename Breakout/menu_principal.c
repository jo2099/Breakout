#include<stdio.h>
#include "raylib.h"
#include "menu_principal.h"
#include "bola.h"
#include"top5_funcoes.h"


void desenha_botao(BOTAO *botao,char text1[15])
{

    DrawRectangle(botao->pos_x,botao->pos_y,botao->largura,botao->altura,botao->cor);
    DrawText(text1,botao->pos_x+25,botao->pos_y+10,25,BLACK);
}

int pos_cursor_botao(int pos_x_mouse,int pos_y_mouse,BOTAO *botao)
{
    if(pos_x_mouse >= botao->pos_x && pos_x_mouse <=botao->pos_x+botao->largura && pos_y_mouse >=botao->pos_y && pos_y_mouse <= botao->pos_y+botao->altura )
    {

        return 1;
    }
    else
        return 0;
}

void desenha_menuP(BOTAO jogar,BOTAO top5)
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("BREAKOUT",screenWidth/4.5,screenHeight-screenHeight/1.4,75,RED);
    DrawText("M-mute",screenWidth-120,25,30,RED);
    desenha_botao(&top5,"top5");
    desenha_botao(&jogar,"jogar");

    EndDrawing();
}

void muda_cor_botao(BOTAO *botao,Color cor)
{
    if(pos_cursor_botao(GetMouseX(),GetMouseY(),botao)==1)
    {
        botao->cor=BLUE;

    }
    else
    {
        botao->cor=cor;
    }
}

int clica_botao(BOTAO *botao)
{
    if(pos_cursor_botao(GetMouseX(),GetMouseY(),botao)==1 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)==1)
       {
           return 1;
       }
       else
        return 0;
}

void calcula_menuP(BOTAO *jogar,BOTAO *top5)
{
    clica_botao(jogar);
    muda_cor_botao(jogar,RED);
    muda_cor_botao(top5,PURPLE);


}
