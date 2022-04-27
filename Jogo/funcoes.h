#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#define num_players 10

typedef struct
{
    char nome[20];
    int pontos;
} rank;

void Iniciar(rank *jogador);

void Ranking(rank players[]);

void Historia();

void Creditos();

void textColor(int cor);

void Atualizar_rank(rank players[], rank jogador);

void Inserir(rank players[], rank jogador);

void Organizar(rank players[]);

#endif // FUNCOES_H_INCLUDED
