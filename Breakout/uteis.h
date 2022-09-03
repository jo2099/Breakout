#ifndef UTEIS_H_INCLUDED
#define UTEIS_H_INCLUDED
#define NUM_COLUNAS 8

typedef struct player
{
    char cor;
    float x;
    float y;
    float altura;
    float largura;
    int num_vidas;
}PLAYER;

typedef struct tijolo
{
    char cor;
    float x;
    float y;
    float altura;
    float largura;
    int ativo;
}TIJOLO;

void desenha_player(PLAYER *player);

void move_player(PLAYER *player);
void aumenta_player(PLAYER *player);

void desenha_tijolo(TIJOLO tijolo);

void desenha_matriz(TIJOLO matriz[][NUM_COLUNAS],int num_linhas);


#endif // UTEIS_H_INCLUDED
