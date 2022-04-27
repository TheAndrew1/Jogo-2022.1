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
    if(subs == 0 && jogador.pontos != 0)    //Se a variavel subs nao foi alterada e a pontuação do jogador não for 0 ele inclui no ranking
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
        if (jogador.pontos >= players[i].pontos)    //Compara pontuação do jogador com as do ranking
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
        if (players[i].pontos <= players[i+1].pontos)   //Compara as pontuações do ranking
        {
    	    aux = players[i+1];
            players[i+1] = players[i];
            players[i] = aux;
       	}
    }
}

void Iniciar(rank *jogador)
{
    int opcao;

        textColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        system("cls");
            
        printf("Insira um Nick: ");
        gets(jogador->nome);
        printf("Insira sua pontuação: ");
        scanf("%d", &jogador->pontos);
        getchar();
        system("cls");
        
        do
        {
        	system("cls");
            printf("Jogo esta em desenvolvimento , volte em breve!");
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

void Historia()
{
    int opcao;

    do
        {
            textColor(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            system("cls");
            printf("\t\t\t\t\tHistoria do jogo\n\n");
            printf("\tUm Ovni alienígena tem a missão de enfrentar os habitantes de um planeta\n");
            printf("\tque vai se autodestruir para aniquilar com a natureza da via láctea, os\n");
            printf("\thabitantes enfurecidos com a iniciativa deste ovni, estão bloqueando a rota\n");
            printf("\tque dá acesso ao planeta, assim sendo está tendo uma guerra espacial\n");
            printf("\tentre os nibirus e a espaçonave alienígena (Ovni).\n");
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

void Creditos()
{
    int opcao;

    do
        {
            textColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            system("cls");
            printf("Desenvolvedores do jogo:");
            printf("\n\n    Dany, Ahmad, Josué, André");
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

void textColor(int cor)   //Função para mudar a cor da letra
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

