#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "top5_funcoes.h"
#include"bola.h"
#include"menu_principal.h"
#include "raylib.h"
#include "uteis.h"


void desenha_menu5(FILE *pt_arq,Music musica,int*flag_musica) //recebe um arquivo e desenha os jogadores do arquivo
{
  JOGADOR lista_jogador[5];
  char score[100];
  int y=100;

  pause_musica(musica,flag_musica);
  pt_arq=fopen("top_five.bin","rb");
  for(int i=0;i<5;i++)
  {
      fread(&lista_jogador[i],sizeof(JOGADOR),1,pt_arq);
      itoa(lista_jogador[i].pontuacao,score,10);


      BeginDrawing();
        ClearBackground(BLACK);
        DrawText(lista_jogador[i].nome,100,y,50,RED);
        DrawText(score,600,y,50,RED);
        y+=50;                                              //espacamento entre jogadores

  }
  EndDrawing();
  fclose(pt_arq);

}

void set_lista(JOGADOR vet[5],FILE *pt_arq)//recebe uma lista de jogadores e um arquivo, poem a lista no arquivo
{
    ordena_jogador(vet,5);
    pt_arq=fopen("top_five.bin","wb");
    fwrite(vet,sizeof(JOGADOR),5,pt_arq);
    fclose(pt_arq);
}

JOGADOR pega_ultimo()           //retorna ultimo jogador da lista armazenada no arquivo top 5
{

    FILE *pt_arq;
    JOGADOR vet_jogadores[5];
    JOGADOR ultimo;

    pt_arq=fopen("top_five.bin","rb");

    for(int i=0;i<5;i++)
     {
         fread(&vet_jogadores[i],sizeof(JOGADOR),1,pt_arq);
     }                                                               //insere os jogadores do arquivo num vetor
    fclose(pt_arq);

    ultimo= vet_jogadores[4];
                                                    //seleciona o ultimo jogador e retorna
    return ultimo;
}

void tela_pede_nome(char nome[30])  //funcao com nenhuma entrada e uma saida por referencia,desenha na tela oque o usuario digitar e retorna isso na string nome
{
    int tecla;
    int conta_letras=0;
    tecla=GetCharPressed();


    while(!IsKeyPressed(KEY_BACKSPACE))
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("insira seu nome",100,100,100,RED);

        tecla=GetCharPressed();
        while(tecla>0 && conta_letras<20)
        {
            nome[conta_letras]=tecla;
            nome[conta_letras+1]='\0';
            tecla=0;
            conta_letras++;
        }
        tecla=GetCharPressed();
        DrawText(nome,150,200,75,RED);
        EndDrawing();


    }


}

void novo_jogador(PLAYER *player,char nome[30]) //funaco que recebe o endereco de um player, e insere ele na lista top_five no arq bin
{
    FILE *pt_arq;
    JOGADOR inserir;
    JOGADOR vet_jogadores[5];

    printf("%d\n",player->score);
    strcpy(inserir.nome,nome);
    inserir.pontuacao=player->score;
    printf("%d\n",player->score);


    pt_arq=fopen("top_five.bin","rb");
    fread(vet_jogadores,sizeof(JOGADOR),5,pt_arq);
    fclose(pt_arq);

    vet_jogadores[4]=inserir;           //subsititui ultimo pelo jogador inserir
    set_lista(vet_jogadores,pt_arq);



}
void lista_default(JOGADOR vet[5]) //recebe uma lista de jogadores , preenche com valores determinados.
{
    char nome1[50]="joao";
    char nome2[50]="ana";
    char nome3[50]="lucas";
    char nome4[50]="pedro";
    char nome5[50]="laura";

    strcpy(vet[0].nome,nome1);
    vet[0].pontuacao=10;
    strcpy(vet[1].nome,nome2);
    vet[1].pontuacao=20;
    strcpy(vet[2].nome,nome3);
    vet[2].pontuacao=50;
    strcpy(vet[3].nome,nome4);
    vet[3].pontuacao=25;
    strcpy(vet[4].nome,nome5);
    vet[4].pontuacao=20;


}

void ordena_jogador(JOGADOR vetor[],int num_elementos)//ordena pontos de jogadores
{

    int i, j;
    for (i = 0; i < num_elementos -1; i++)

        for (j = 0; j < num_elementos -1 - i ; j++)
            if (vetor[j+1].pontuacao > vetor[j].pontuacao)
                troca(&vetor[j+1], &vetor[j]);

}

void troca(JOGADOR *player1,JOGADOR *player2)
{
    JOGADOR temp= *player2;
    *player2=*player1;
    *player1=temp;
}
