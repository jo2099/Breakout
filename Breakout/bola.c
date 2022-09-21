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

void funcao_bola (BOLA *bola){ //matriz

        bola->centro.x += bola->vel.x;
        bola->centro.y += bola->vel.y;

        if ((bola->centro.x >= (GetScreenWidth() - bola->raio)) || (bola->centro.x <= bola->raio)) bola->vel.x *= -1.0f;
        if ((bola->centro.y >= (GetScreenHeight() - bola->raio)) || (bola->centro.y <= bola->raio)) bola->vel.y *= -1.0f;



}
