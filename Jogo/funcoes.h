#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#define num_players 3
typedef struct
{
 char nome[20];
 int pontos;
} rank;

void Jogar(rank *jogador, rank players[]);

void Ranking(rank players[]);

void Creditos();

void textColor(int cor);

void Atualizar_rank(rank players[], rank jogador);

void Inserir(rank players[], rank jogador);

void Organizar(rank players[]);
#endif // FUNCOES_H_INCLUDED
