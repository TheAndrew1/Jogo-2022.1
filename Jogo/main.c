#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include "funcoes.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int opcao, i;
    rank players[num_players];
    rank jogador;
    for(i=0; i<num_players; i++)
    {
        players[i].pontos = 0;
    }

    do
    {
    system("cls");
    textColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("\n\t\t       NIBIRUS ATTACKS!"); //Mostra na tela o menu do jogo
    printf("\n\n\t\t\t 1.Iniciar");
    printf("\n\t\t\t 2.Ranking");
    printf("\n\t\t\t 3.Sobre");
    printf("\n\t\t\t 4.Créditos");
    printf("\n\n\t\t\t 0.Sair\n\n\n");
    scanf("%d", &opcao);
    getchar();
    system("cls");

    switch(opcao) //Determina o que ira ocorrer de acordo com o comando executado
    {
    case 1:
        Iniciar(&jogador);
        break;
    case 2:
        Ranking(players, jogador);
        jogador.pontos = 0;
        break;

    case 3:
        Historia();
        break;

    case 4:
        Creditos();
        break;

    case 0:     //Case 0 não chama nenhuma função apenas sai do loop
        break;

    default:
        printf("\n\t\tOpção invalida!\n\n");
        Sleep(2000);
    }
	}while (opcao != 0); //Continua no menu enquanto a tecla de saída não for pressionada

	 return 0;
}

