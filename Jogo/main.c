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
 FILE *placar;
 rank players[num_players]; //Define o rank de jogadores
 rank jogador; //Define o jogador q esta jogando

 placar = fopen("jogadores.txt", "r");
 if(placar == NULL) //Verifica se tem algo no arquivo
 {
 for(i=0; i<num_players; i++)//Zera a pontuação do rank
 {
 players[i].pontos = 0;
 }
 }
 else
 {
 i = 0;

 while(!feof(placar)) //Le as pontuacoes ja salvas
 {
 fscanf(placar,"%s %d\n", players[i].nome, &players[i].pontos);
 i++;
 }

 for(i=i; i<num_players; i++) //Zera a pontuação do restante rank
 {
 players[i].pontos = 0;
 }
 }
 fclose(placar);
 do
 {
 system("cls");
 textColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
 printf("\n\t\t NIBIRUS ATTACKS!"); //Mostra na tela o menu do jogo
 printf("\n\n\t\t\t 1.Jogar");
 printf("\n\t\t\t 2.Ranking");
 printf("\n\t\t\t 3.Créditos");
 printf("\n\n\t\t\t 0.Sair\n\n\n");
 scanf("%d", &opcao);
 getchar();
 system("cls");
 switch(opcao) //Determina o que ira ocorrer de acordo com o comando executado
 {
 case 1:
 Jogar(&jogador, players); //Chama a função Iniciar e passa o endereço da struct do jogador como parametro
 Atualizar_rank(players, jogador); //Atualiza o ranking com o novo jogador
 break;
 case 2:
 Ranking(players); //Mostra o ranking
 break;
 case 3:
 Creditos();
 break;
 case 0: //Salva o novo ranking no arquivo e encerra o loop
 placar = fopen("jogadores.txt", "w");
 for(i=0; i<num_players && players[i].pontos!=0; i++)
 {
 fprintf(placar, "%s %d\n", players[i].nome, players[i].pontos);
 }
 fclose(placar);

 printf("\n\t\tNibirus estará esperando!\n\n");
 Sleep(2000);
 break;
 default:
 printf("\n\t\tOpção invalida!\n\n");
 Sleep(2000);
 }
 }while (opcao != 0); //Continua no menu enquanto a tecla de saída não for pressionada
 return 0;
}
