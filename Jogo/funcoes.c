#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include "funcoes.h"
void Atualizar_rank(rank players[], rank jogador)
{
 int i, subs = 0;
 for (i = 0; i<num_players; i++)
 {
 if(players[i].pontos == 0)
 {
 break;
 }
 else if(!strcmp(jogador.nome, players[i].nome)) //Compara o nome do jogador com os nomes do ranking
 {
 if(jogador.pontos > players[i].pontos) //Se a nova pontuação for maior do que a registrada ele alterna
 {
 players[i].pontos = jogador.pontos;
 Organizar(players); //Reorganiza o ranking com a nova pontuação
 }
 subs = 1;
 break;
 }
 }
 if(subs == 0 && jogador.pontos != 0) //Se a variavel subs nao foi alterada e a pontuação do jogador não for 0 ele inclui no ranking
 {
 Inserir(players, jogador);
 }
}

void Inserir(rank players[], rank jogador)
{
	int i;
 	for (i = 0; i<num_players; i++)
 	{
 		rank aux;
 		if (jogador.pontos > players[i].pontos) //Compara pontuação do jogador com as do ranking
 		{
 			aux = players[i];
 			players[i] = jogador;
 			jogador = aux;
 		}
 	}
}

void Organizar(rank players[])
{
	int i;
 	for (i = 0; i<num_players && players[i+1].pontos != 0; i++)
 	{
 		rank aux;
 		if (players[i].pontos < players[i+1].pontos) //Compara as pontuações do ranking
 		{
 			aux = players[i+1];
 			players[i+1] = players[i];
 			players[i] = aux;
 		}
 	}
}

void Jogar(rank *jogador, rank players[])
{
 int opcao, i;
 textColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
 system("cls");
 for(i = 0; i<num_players && players[i].pontos != 0; i++)
 {
 printf("Jogador %d: %s\tPontuação: %d\n", i+1, players[i].nome, players[i].pontos);
 }

 printf("Digite o numero do jogador com qual deseja jogar\n");
 printf("Digite 0 caso queira criar um novo\n\n");
 scanf("%d", &opcao);
 getchar();

 if(opcao != 0)
 {
 strcpy(jogador->nome, players[opcao-1].nome);
 jogador->pontos = players[opcao-1].pontos;
 }
 else
 {
 system("cls");
 printf("Insira um Nick: ");
 gets(jogador->nome);
 printf("Insira sua pontuação: ");
 scanf("%d", &jogador->pontos);
 getchar();

 system("cls");
 printf("Jogador adicionado!\nNome: %s\tPontuação: %d", jogador->nome, jogador->pontos);
 Sleep(1500);
 }
 system("cls");
 do
 {
 system("cls");
 printf("Em construção!");
 printf("\n\nDigite 0 para retornar ao menu de opções.\n");
 scanf("%d", &opcao);
 if(opcao == 0) //Condição para voltar para o menu
 {
 break;
 }
 else
 {
 printf("\nDigite um comando válido\n");
 Sleep(2000);
 }
 } while(opcao != 0);
}
void Ranking(rank players[])
{
 int opcao, i;
 do
 {
 textColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
 system("cls");
 printf("\t\tRanking.");
 if(players[0].pontos == 0)
 {
 printf("\n\n\tSem pontuação registrada.");
 }
 else
 {
 for(i=0; i<num_players && players[i].pontos != 0; i++)
 {
 printf("\n\n\t%s = %d", players[i].nome, players[i].pontos);
 }
 }
 printf("\n\nDigite 0 para retornar ao menu de opções.\n");
 scanf("%d", &opcao);
 getchar();
 system("cls");
 if(opcao == 0)
 break;
 else
 {
 printf("\n\t\tDigite um comando válido\n");
 Sleep(2000);
 }
 } while(opcao != 0);
}
void Creditos()
{
 int opcao;
 do
 {
 textColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
 system("cls");
 printf("Desenvolvedores do jogo:");
 printf("\n\n Dany, Ahmad, Josué, André");
 printf("\n\nDigite 0 para retornar ao menu de opções.\n");
 scanf("%d", &opcao);
 if(opcao == 0) //Condição para voltar para o menu
 {
 break;
 }
 else
 {
 printf("\nDigite um comando válido\n");
 Sleep(2000);
 }
 } while(opcao != 0);
}
void textColor(int cor) //Função para mudar a cor da letra
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}
