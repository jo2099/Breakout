#include<stdio.h>
#include<stdlib.h>
#include"raylib.h"


typedef struct player
{
    char cor;
    float x;
    float y;
    float altura;
    float largura;
}player;

void move_player(player *player)
{
        if (IsKeyDown(KEY_RIGHT))
            player->x += 5;
        if (IsKeyDown(KEY_LEFT))
            player->x -= 5;
       // if (IsKeyDown(KEY_UP))
            player->y -= 2.0;
       // if (IsKeyDown(KEY_DOWN))
            player->y += 2.0;
}

void aumenta_player(player *player)
{
    player->largura=player->largura+5;
}

int main(void)
{

 const int screenWidth = 1200;
 const int screenHeight = 800;
 InitWindow(screenWidth, screenHeight, "Breakout");
 SetTargetFPS(60);

 player player;

 player.y=685;
 player.x=550;
 player.largura=120;
 player.altura=25;


 while (!WindowShouldClose())
 {
    move_player(&player);
    if(IsKeyPressed(KEY_A))
        aumenta_player(&player);
 BeginDrawing();
 ClearBackground(RAYWHITE);
 DrawText("Congrats! You created your first window!", 400, 300, 20, LIGHTGRAY);
 DrawRectangle(player.x,player.y,player.largura,player.altura,RED);
 EndDrawing();
 }
 CloseWindow();
 return 0;
}
