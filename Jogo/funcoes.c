#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include "funcoes.h"

void Iniciar(rank *jogador)
{
    int opcao;

        textColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        system("cls");
            
        printf("Insira um Nick: ");
        gets(jogador->nome);
        printf("Insira sua pontua��o: ");
        scanf("%d", &jogador->pontos);
        getchar();
        system("cls");
        
        do
        {
            printf("Jogo esta em desenvolvimento , volte em breve!");
            printf("\n\nDigite 0 para retornar ao menu de op��es.\n");
            scanf("%d", &opcao);
        if(opcao == 0) //Condi��o para voltar para o menu
        {
            break;
        }
        else
        {
            printf("\nDigite um comando v�lido\n");
            system("pause");
        }
        } while(opcao != 0);
}

void Ranking(rank players[], rank jogador)
{
    int opcao, i;
    
    if(jogador.pontos != 0)
    {
    	for (i = 0; i<num_players; i++)
        	{
           		 rank ref_for;
            	if (jogador.pontos >= players[i].pontos)
        	    {
    	            strcpy(ref_for.nome, players[i].nome);
                	strcpy(players[i].nome, jogador.nome);
            	    strcpy(jogador.nome, ref_for.nome);
        	            
    	            ref_for.pontos = players[i].pontos;
                	players[i].pontos = jogador.pontos;
            	    jogador.pontos = ref_for.pontos;
        	    }
    	    }
	}

    do
    {
        textColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
        system("cls");
        printf("\t\tRanking.");
        if(players[0].pontos == 0)
        {
            printf("\n\n\tSem pontua��o registrada.");
        }
        else
        {
            for(i=0; i<num_players && players[i].pontos != 0; i++)
            {
                printf("\n\n\t%s = %d", players[i].nome, players[i].pontos);
            }
        }
        printf("\n\nDigite 0 para retornar ao menu de op��es.\n");
        scanf("%d", &opcao);
        getchar();
        system("cls");

        if(opcao == 0)
            break;
        else
        {
            printf("\n\t\tDigite um comando v�lido\n");
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
            printf("\tUm Ovni alien�gena tem a miss�o de enfrentar os habitantes de um planeta\n");
            printf("\tque vai se autodestruir para aniquilar com a natureza da via l�ctea, os\n");
            printf("\thabitantes enfurecidos com a iniciativa deste ovni, est�o bloqueando a rota\n");
            printf("\tque d� acesso ao planeta, assim sendo est� tendo uma guerra espacial\n");
            printf("\tentre os nibirus e a espa�onave alien�gena (Ovni).\n");
            printf("\n\nDigite 0 para retornar ao menu de op��es.\n");
            scanf("%d", &opcao);
        if(opcao == 0) //Condi��o para voltar para o menu
        {
            break;
        }
        else
        {
            printf("\nDigite um comando v�lido\n");
            system("pause");
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
            printf("\n\n    Dany, Ahmad, Josu�, Andr�");
            printf("\n\nDigite 0 para retornar ao menu de op��es.\n");
            scanf("%d", &opcao);
        if(opcao == 0) //Condi��o para voltar para o menu
        {
            break;
        }
        else
        {
            printf("\nDigite um comando v�lido\n");
            system("pause");
        }
        } while(opcao != 0);
}

void textColor(int cor)   //Fun��o para mudar a cor da letra
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

