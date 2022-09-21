#include "uteis.h"
#include "raylib.h"
#include "top5_funcoes.h"
#include "bola.h"
#define screenWidth 800
#define screenHeight 450



void move_player(PLAYER *player)

{

      if(player->corpo.x <=screenWidth-player->corpo.width)
      {
          if (IsKeyDown(KEY_RIGHT))
            player->corpo.x += 8;
      }

      if (player->corpo.x >=0)
      {
          if (IsKeyDown(KEY_LEFT))
            player->corpo.x -= 8;
      }

}
void set_player(PLAYER *player) //determina a posição inicial do player
{

    player->corpo.width=85;
    player->corpo.height=15;
    player->corpo.y=screenHeight-50;
    player->corpo.x=(screenWidth/2-player->corpo.width/2);
    player->num_vidas=5;
    player->score=0;
}

void desenha_player(PLAYER *player)
{
    char numero_vidas[10];
    char score[100];
    itoa(player->num_vidas,numero_vidas,10);
    itoa(player->score,score,10);

    DrawRectangle(player->corpo.x,player->corpo.y,player->corpo.width,player->corpo.height,RED);
    DrawText("vidas: ",screenWidth-150,screenHeight-25,15,RED);
    DrawText(numero_vidas,screenWidth-50,screenHeight-25,15,RED);
    DrawText("score:",100,screenHeight-25,15,RED);
    DrawText(score,50,screenHeight-25,15,RED);
};

void aumenta_player(PLAYER *player)
{
    player->corpo.width=player->corpo.width+5;
}

void damage_player(PLAYER *player)
{
    if(IsKeyPressed(KEY_B))
    {
        player->num_vidas--;
    }

}

void game_over(PLAYER *player,int *flag_jogo,int *flag_enter)
{
    JOGADOR last;


    char nome[30];
    if(IsKeyPressed(KEY_L)|| player->num_vidas==0)
    {
        last=pega_ultimo();
        char score[20];
        itoa(player->score,score,10);
        while(!IsKeyDown(KEY_ENTER))
        {
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("game over",100,100,100,RED);
            DrawText("press esc to return",100,200,100,RED);
            EndDrawing();
        }

        if(player->score>last.pontuacao)
        {
            tela_pede_nome(nome);
            novo_jogador(player,nome);
            *flag_jogo=0;
        }
        player->num_vidas=player->num_vidas+1;




    }


}

void aumenta_score(PLAYER *player)
{
    if(IsKeyPressed(KEY_D))
    {
        player->score=player->score +50;
    }
}

void tela_gameOver(int *flag_jogo,PLAYER *player)     //funcao que desenha a tela de game over
{
    JOGADOR last;

    while(*flag_jogo==1)                           //enquanto a flag jogo for 1 //logica provisoria de game over
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("game over",100,100,100,RED);          //desenha a tela de game over
        DrawText("press enter to return",100,200,50,RED);
        EndDrawing();

    }
}

void set_matriz(TIJOLO matriz[][NUM_COLUNAS],int num_linhas)
{
    int x=5;
    int y=35;
    for(int i=0;i<num_linhas;i++)
    {
        for(int j=0;j<NUM_COLUNAS;j++)
        {
            matriz[i][j].corpo.height=15;
            matriz[i][j].corpo.width=75;
            matriz[i][j].corpo.x=x;
            matriz[i][j].corpo.y=y;
            matriz[i][j].cor=RED;
            matriz[i][j].ativo=1;

            x=x+102;

        }
        x=5;
        y=y+30;

    }
}

void desenha_tijolo(TIJOLO tijolo)
{
    DrawRectangle(tijolo.corpo.x,tijolo.corpo.y,tijolo.corpo.width,tijolo.corpo.height,RED);
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
void set_bola(BOLA *bola)
{
    bola->centro.x=screenWidth/2;
    bola->centro.y=380;
    bola->raio=10;
    bola->cor=RED;
    bola->vel.x=0;
    bola->vel.y=0;
    bola->ativo=0;
}

void desenha_bola(BOLA *bola)
{
    DrawCircle(bola->centro.x,bola->centro.y,bola->raio,bola->cor);
}

void set_game(PLAYER *player,TIJOLO matriz[][NUM_COLUNAS],int num_linhas,BOLA *bola)//inicia a matriz e o jogador
{
    set_player(player);
    set_bola(bola);
    set_matriz(matriz,num_linhas);

}

void lanca_bola(BOLA *bola)
{
    if(IsKeyPressed(KEY_SPACE))
    {
        bola->ativo=1;
        bola->vel.y=-3;
    }
}



void calcula_game(PLAYER *player, int *flag_jogo,BOLA *bola,int *flag_enter)
{
    int flag_pause;

   if(IsKeyPressed(KEY_P))          //funcao pause
   {
       flag_pause=!flag_pause;
   }


    if(WindowShouldClose()) //função que sai do jogo
    {
        *flag_jogo=0;
    }

    if(flag_pause)    //funcionamento normal do jogo //se falg_pause for 1 e flag_over for 0
    {
         move_player(player);           //move o jogador
         if(bola->ativo==0)             //se a bola n estiver ative
         {
             lanca_bola(bola);          //lanca a bola e poe velocidade nela
             bola->centro.x=player->corpo.x+40;
         }
         funcao_bola(bola);              // a bola com o tempo
         aumenta_score(player);         //
         damage_player(player);
         game_over(player,flag_jogo,flag_enter);             //funcao que causa game over
    }

    if(!flag_pause)
    {
        DrawText("PAUSE",150,150,100,RED);
    }





}

void jogo(PLAYER *player,int *flag_jogo,int *flag_over,TIJOLO matriz[][NUM_COLUNAS],int num_linhas,BOLA *bola,int *flag_enter,int *conta_letras,int *flag_maior,Music musica)
{

        calcula_game(player,flag_jogo,bola,flag_enter);
        desenha_game(player,matriz,num_linhas,bola,musica);


}



void desenha_game(PLAYER *player,TIJOLO matriz[][NUM_COLUNAS],int num_linhas,BOLA *bola,Music musica)
{
    BeginDrawing();
    UpdateMusicStream(musica);
        ClearBackground(BLACK);
        DrawText("Congrats! You created your first window!", 400, 300, 20, LIGHTGRAY);

    desenha_player(player);
    desenha_bola(bola);
    desenha_matriz(matriz,num_linhas);

    EndDrawing();
}

void diminui_vidas(PLAYER *player)
{
    player->num_vidas -= 1;
}


