#ifndef MENU_PRINCIPAL_H_INCLUDED
#define MENU_PRINCIPAL_H_INCLUDED
#include "raylib.h"
#define screenWidth 800
#define screenHeight 450


typedef struct botao
{
    float largura;
    float altura;
    float pos_x;
    float pos_y;
    int ativo;
    Color cor;
}BOTAO;







void calcula_menuP(BOTAO *jogar,BOTAO *opcoes,BOTAO *top5);
void desenha_menuOP();
void desenha_botao(BOTAO *botao,char text[15]);
int pos_cursor_botao(int pos_x_mouse,int pos_y_mouse,BOTAO *botao);//verifica se o mouse esta em cima do botao




#endif // MENU_PRINCIPAL_H_INCLUDED
