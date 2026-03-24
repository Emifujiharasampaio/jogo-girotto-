
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void perguntas();
void cobraNaCaixa();
void gousmasWar();


int main() {
    int opcao;
    srand(time(NULL));

    do {
        printf("\n   MENU PRINCIPAL  \n");
        printf("1 - Pergunta e Resposta\n");
        printf("2 - Cobra na Caixa\n");
        printf("3 - Gousmas War\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
       
        if (scanf("%d", &opcao) != 1) {
            while(getchar() != '\n');
            continue;
        }

        if (opcao == 1) perguntas();
        else if (opcao == 2) cobraNaCaixa();
        else if (opcao == 3) gousmasWar();

    } while (opcao != 4);

    printf("\nPrograma encerrado\n");
    return 0;
}


void perguntas() {
    int resposta;
    int repetir = 1;
    while (repetir == 1) {
    	system ("cls");
        printf("\n   JOGO DE PERGUNTAS  \n");
        printf("Se hoje e segunda-feira, que dia sera depois de amanha?\n");
        printf("1) domingo | 2) terca | 3) quarta | 4) quinta\n> ");
        scanf("%d", &resposta);
        if (resposta == 3) printf("PARABENS!\n"); else printf("Errou!\n");

        printf("AAB - CCB - DDB - ?\n");
        printf("1) EEB | 2) EBD | 3) FFB | 4) EBC\n> ");
        scanf("%d", &resposta);
        if (resposta == 1) printf("PARABENS!\n"); else printf("Errou!\n");
        
        printf ("estao em uma fila: pedro, lucas e marcos\n quem esta no meio?\n");
       printf ("1)pedro\n 2) lucas\n 3) marcos\n 4)nao sei\n>");
       scanf("%d", &resposta);
       
       if (resposta ==2) printf ("ACERTOOOOU\n");
       else printf ("errou vei, besta demaais\n");
       
       printf ("qual o melhor anime do mundo?\n");
      printf ("1) one piece\n 2)boku no hero\n 3) one punch man\n 4) naruto\n>");
      scanf ("%d", &resposta);
      
      if (resposta==4) printf ("BOAA obv que e o naruto ne pae\n");
      else printf ("nao vei, obv que naruto e o melhor do mundo\n");
      
      printf ("1- 4 - 9 -16 ... qual e o proximo\n");
      printf ("1) 20\n 2) 21\n 3) 25\n 4) 24\n>");
      scanf ("%d", &resposta);
      
      if (resposta==3) printf ("TOOOOP, ta manjando da matematica\n>");
      else printf ("ohhh vei pensa mais um pouco\n");

        printf("\n1 - Jogar novamente\n2 - Menu\n> ");
        scanf("%d", &repetir);
        
       
        
    }
}


void cobraNaCaixa() {
    int repetir = 1;
    char nomes[7][30] = {"Batman", "Superman", "Spider", "IronMan", "Cap", "Thor", "Hulk"};
    while (repetir == 1) {
    		system ("cls");
    	printf ("\n   COBRA NA CAIXA   \n");
        int palpite, caixa_escolhida = 0, caixas[5] = {0}, abertas[5] = {0};
        int jogador1, jogador2, turno, botao, cobra;
         printf ("jogador 1: escola seu nome: 1.Batman\n 2.Superman\n 3.Spider\n 4.IronMan\n 5.Cap\n 6.Thor\n 7.Hulk\n");
        printf("\nEscolha Jogador 1 (1-7): "); scanf("%d", &jogador1);
        printf ("jogador 1: escola seu nome: 1.Batman\n 2.Superman\n 3.Spider\n 4.IronMan\n 5.Cap\n 6.Thor\n 7.Hulk\n");
        printf("Escolha Jogador 2 (1-7): "); scanf("%d", &jogador2);
        turno = rand() % 2;
        botao = rand() % 5; caixas[botao] = 1;
        cobra = rand() % 5;
        while (botao == cobra) cobra = rand() % 5;
        caixas[cobra] = 2;

        while (caixa_escolhida == 0) {
            printf("\nTurno de %s. Caixa (1-5): ", nomes[((turno == 0) ? jogador1 : jogador2) - 1]);
            scanf("%d", &palpite);
            if (palpite < 1 || palpite > 5 || abertas[palpite - 1]) {
                printf("Invalido!\n"); continue;
            }
            abertas[palpite - 1] = 1;
            caixa_escolhida = caixas[palpite - 1];
            if (caixa_escolhida == 0) { printf("Vazia!\n"); turno = 1 - turno; }
            else if (caixa_escolhida == 1) printf("VENCEU!\n");
            else printf("COBRA! PERDEU!\n");
        }
       printf("\n1 - Jogar novamente\n2 - Menu\n> ");
	    scanf("%d", &repetir);
    }
}


void gousmasWar() {
    int repetir = 1;
    while (repetir == 1) {
    	printf ("\n   GOUSMAS WAR   \n");
    		system ("cls");
        int j1[2] = {1, 1}, j2[2] = {1, 1};
        int ativo1[2] = {1, 1}, ativo2[2] = {1, 1};
        int turno = 0;

        while (1) {
            int acao, a, t, valor;
            printf("\n     GOUSMAS WAR  \n");
            printf("J1: G1[%d]%s | G2[%d]%s\n", j1[0], ativo1[0]?"VIVA":"MORTE", j1[1], ativo1[1]?"VIVA":"MORTE");
            printf("J2: G1[%d]%s | G2[%d]%s\n", j2[0], ativo2[0]?"VIVA":"MORTE", j2[1], ativo2[1]?"VIVA":"MORTE");
            printf("Turno J%d. 1-Atacar 2-Dividir: ", turno + 1);
            scanf("%d", &acao);

            if (acao == 1) {
                printf("Sua Gousma (1-2) e Alvo (1-2): ");
                scanf("%d %d", &a, &t); a--; t--;
                if (turno == 0 && ativo1[a] && ativo2[t]) {
                    j2[t] += j1[a];
                    if (j2[t] > 5) { ativo2[t] = 0; j2[t] = 0; }
                    turno = 1;
                } else if (turno == 1 && ativo2[a] && ativo1[t]) {
                    j1[t] += j2[a];
                    if (j1[t] > 5) { ativo1[t] = 0; j1[t] = 0; }
                    turno = 0;
                } else printf("Invalido!\n");
            }
            else if (acao == 2) {
                printf("Doadora(1-2), Receptora(1-2) e Valor: ");
                scanf("%d %d %d", &a, &t, &valor); a--; t--;
                if (turno == 0 && ativo1[a] && valor >= 1 && valor < j1[a]) {
                    j1[a] -= valor; j1[t] += valor;
                    ativo1[t] = (j1[t] <= 5);
                    turno = 1;
                } else if (turno == 1 && ativo2[a] && valor >= 1 && valor < j2[a]) {
                    j2[a] -= valor; j2[t] += valor;
                    ativo2[t] = (j2[t] <= 5);
                    turno = 0;
                } else printf("Invalido!\n");
            }

            if (!ativo1[0] && !ativo1[1]) { printf("J2 VENCEU!\n"); break; }
            if (!ativo2[0] && !ativo2[1]) { printf("J1 VENCEU!\n"); break; }
        }
       printf("\n1 - Jogar novamente\n2 - Menu\n> ");
	    scanf("%d", &repetir);
    }
}
