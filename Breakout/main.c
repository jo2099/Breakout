#include<stdio.h>
#include<stdlib.h>
#include"raylib.h"
#define screenWidth 1200
#define screenHeight 800
#define TRUE 1
#define FALSE 0
#define NUM_LINHAS 4
#define NUM_COLUNAS 6

typedef struct player
{
    char cor;
    float x;
    float y;
    float altura;
    float largura;
    int num_vidas;

} PLAYER;

typedef struct tijolo
{
    char cor;
    float x;
    float y;
    float altura;
    float largura;
    int ativo;
}TIJOLO;


int main(void)
{

    PLAYER player;
    TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS];
    TIJOLO teste;




    InitWindow(screenWidth, screenHeight, "Breakout");
    SetTargetFPS(60);




    set_player(&player);

    while (!WindowShouldClose())
    {
        move_player(&player);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 400, 300, 20, LIGHTGRAY);
        desenha_player(&player);
        desenha_tijolo(teste);
        desenha_matriz(matriz,NUM_LINHAS);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
