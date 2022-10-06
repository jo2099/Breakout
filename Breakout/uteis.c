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
          if (IsKeyDown(KEY_RIGHT)||IsKeyDown(KEY_D))
            player->corpo.x += player->vel.x;
      }

      if (player->corpo.x >=0)
      {
          if (IsKeyDown(KEY_LEFT)|| IsKeyDown(KEY_A))
            player->corpo.x -= player->vel.x;
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
    player->vel.x=8;
    player->vel.y=0;
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

int acabou_matriz(TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS])
{
    int acabou=1;
    for(int i=0;i<NUM_LINHAS;i++)
    {

        for(int j=0;j<NUM_COLUNAS;j++)
        {
            if(matriz[i][j].ativo==1)
            {
                acabou=0;
            }
        }
    }

    return acabou;
}
void game_over(PLAYER *player,int *flag_jogo,int *flag_enter,TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS],BOLA *bola,FILE *arq_nivel,int *nivel)
{
    JOGADOR last;


    char nome[30];
    if(player->num_vidas==0 || *nivel >0)
    {
        last=pega_ultimo();
        char score[20];
        itoa(player->score,score,10);
        while(!IsKeyPressed(KEY_ENTER))
        {
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("game over",100,100,75,RED);
            DrawText("press enter to return",100,200,100,RED);
            EndDrawing();
        }

        if(player->score>last.pontuacao)
        {
            tela_pede_nome(nome);
            novo_jogador(player,nome);
            *flag_jogo=0;
        }
        player->num_vidas=player->num_vidas+1;


    *nivel=0;
    set_game(player,matriz,bola,arq_nivel,nivel);
    *flag_jogo=0;
    }


}

char le_cor(FILE *arq)
{
    char generico=' ';
   do
   {
       generico=fgetc(arq);
       printf("caractere lido eh %c\n",generico);
   }
   while(generico == ' ' || generico=='\n');
    printf("retornei %c\n",generico);
    return generico;

}


Color gera_cor(char cor)
{

    switch(cor)
    {

    case 'r':
        return RED;
        break;
    case 'y':
        return YELLOW;
        break;
    case 'g':
        return GREEN;
        break;
    case 'o':
        return ORANGE;
        break;
    case 'b':
        return BLUE;
        break;
    case 'x':
        return ORANGE;
        break;
    default:
        return WHITE;
        break;
    }


}

char power_up()
{
    int numero;
    numero=rand()%3;

    if(numero==0)
    {
        return 'a';
    }
    else if(numero==1)
    {
        return 'b';
    }
    else if(numero==2)
    {
        return 'c';
    }
}

void set_matriz(TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS],FILE *arq_nivel,int *nivel_c)
{
    char Lcor;
    int x=30;
    int y=35;

    switch(*nivel_c)                        //seleciona qual arquivo nivel abrir
    {
    case 0:
        arq_nivel=fopen("nivel1.txt","r");
        printf("abri nivel1\n");
        break;
    case 1:
        printf("abri nivel2\n");
        arq_nivel=fopen("nivel2.txt","r");
        break;
    case 2:
        arq_nivel=fopen("nivel3.txt","r");
        break;

    default:
        arq_nivel=fopen("nivel1.txt","r");
        break;
    }



    for(int i=0;i<NUM_LINHAS;i++)
    {
        for(int j=0;j<NUM_COLUNAS;j++)
        {
            Lcor=le_cor(arq_nivel);
            matriz[i][j].corpo.height=12;
            matriz[i][j].corpo.width=65;
            matriz[i][j].corpo.x=x;
            matriz[i][j].corpo.y=y;
            matriz[i][j].especial='-';
            if(Lcor=='-')
            {
                matriz[i][j].ativo=0;
            }
            else
                matriz[i][j].ativo=1;

            matriz[i][j].cor=gera_cor(Lcor);


            x=x+75;

        }
        x=30;
        y=y+30;

    }
    for(int i=0;i<3;i++)
    {

        matriz[rand()%6][rand()%11].especial=power_up();
    }
    fclose(arq_nivel);

}

void desenha_tijolo(TIJOLO tijolo)
{
    DrawRectangle(tijolo.corpo.x,tijolo.corpo.y,tijolo.corpo.width,tijolo.corpo.height,tijolo.cor);
}

void desenha_matriz(TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS])
{
    for(int i=0; i<NUM_LINHAS; i++)
    {
        for(int j=0; j<NUM_COLUNAS; j++)
        {
            if(matriz[i][j].ativo)
            {
                desenha_tijolo(matriz[i][j]);
            }

        }
    }
}
void set_bola(BOLA *bola)
{
    bola->centro.x=screenWidth/2;
    bola->centro.y=380;
    bola->raio=8;
    bola->cor=RED;
    bola->vel.x=0;
    bola->vel.y=0;
    bola->ativo=0;
}

void desenha_bola(BOLA *bola)
{
    DrawCircle(bola->centro.x,bola->centro.y,bola->raio,bola->cor);
}

void set_game(PLAYER *player,TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS],BOLA *bola,FILE *arq_nivel,int *nivel)//inicia a matriz e o jogador
{
    set_player(player);
    set_bola(bola);
    set_matriz(matriz,arq_nivel,nivel);

}

void lanca_bola(BOLA *bola)
{
    if(IsKeyPressed(KEY_SPACE))
    {
        bola->ativo=1;
        bola->vel.y=-3;
        bola->vel.x=-3;
    }
}

void win(PLAYER *player,TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS],BOLA *bola,FILE *arq_nivel,int *nivel)
{

    if(acabou_matriz(matriz))
    {
        *nivel=*nivel+1;
        set_matriz(matriz,arq_nivel,nivel);
        set_bola(bola);
    }

}

void calcula_game(PLAYER *player, int *flag_jogo,BOLA *bola,int *flag_enter,TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS],FILE *arq_nivel,int *nivel)
{
    int flag_pause;

   if(IsKeyPressed(KEY_P))          //funcao pause
   {
       flag_pause=!flag_pause;
   }


    if(WindowShouldClose()) //função que sai do jogo
    {
        *flag_jogo=0;
        set_game(player,matriz,bola,arq_nivel,nivel);
    }

    if(flag_pause)    //funcionamento normal do jogo //se falg_pause for 1 e flag_over for 0
    {
         move_player(player);           //move o jogador
         if(bola->ativo==0)             //se a bola n estiver ative
         {
             lanca_bola(bola);          //lanca a bola e poe velocidade nela
             bola->centro.x=player->corpo.x+40;
         }
         funcao_bola(bola,player,matriz);              // a bola com o tempo
         damage_player(player);
         game_over(player,flag_jogo,flag_enter,matriz,bola,arq_nivel,nivel);             //funcao que causa game over
         win(player,matriz,bola,arq_nivel,nivel);
    }

    if(!flag_pause)
    {
        DrawText("PAUSE",150,150,100,RED);
    }





}

void jogo(PLAYER *player,int *flag_jogo,int *flag_over,TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS],BOLA *bola,int *flag_enter,int *conta_letras,int *flag_maior,Music musica,int *flag_musica,FILE *arq_nivel,int *nivel)
{

        calcula_game(player,flag_jogo,bola,flag_enter,matriz,arq_nivel,nivel);
        desenha_game(player,matriz,bola,musica,flag_musica);


}

void pause_musica(Music musica,int *flag_musica)
{
    if(IsKeyPressed(KEY_M))
    {
        *flag_musica=!*flag_musica;
    }
    if(*flag_musica)
        UpdateMusicStream(musica);
}



void desenha_game(PLAYER *player,TIJOLO matriz[NUM_LINHAS][NUM_COLUNAS],BOLA *bola,Music musica,int *flag_musica)
{

    pause_musica(musica,flag_musica);
    BeginDrawing();

    ClearBackground(BLACK);
    desenha_player(player);
    desenha_bola(bola);
    desenha_matriz(matriz);

    EndDrawing();
}



