#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#define num_players 10

typedef struct
{
    char nome[20];
    int pontos;
} rank;

void Iniciar(rank *jogador);

void Ranking(rank players[], rank jogador);

void Historia();

void Creditos();

void textColor(int cor);

#endif // FUNCOES_H_INCLUDED
