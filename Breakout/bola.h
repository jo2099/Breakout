#ifndef BOLA_H_INCLUDED
#define BOLA_H_INCLUDED
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


void funcao_bola (BOLA *bola,PLAYER *player,TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS]);


#endif // BOLA_H_INCLUDED
