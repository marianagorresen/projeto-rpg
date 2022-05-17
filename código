#include <stdio.h>
#include <stdlib.h>
#include<time.h>

typedef struct atributos
{
	double forca;
	double constituicao;
	double agilidade;
	double destreza;
} ATRIBUTO;

typedef struct equipamentos
{
	double arma;
	double armadura;
} EQUIPAMENTO;

typedef struct personagem
{
	char nome[50];
	double pv;
	EQUIPAMENTO equipamento;
	ATRIBUTO atributo;
} PERSONAGEM;

PERSONAGEM personagem;


void criar_personagem();

void pontos_vida(double* consta, double* pv)
{
	srand(time(NULL));
	double dado_1 = rand() % 6 + 1, dado_2 = rand() % 6 + 1 , dado_3 = rand() % 6 + 1;
	
	*pv =  dado_1 + dado_2 + dado_3 + (*consta);
	printf("\nDado 1= %.lf\nDado 2= %.lf\nDado 2= %.lf\n", dado_1, dado_2, dado_3);
}

int main()
{
	int opc;
	double pontos;
	printf("-------------------\n------- MENU ------\n-------------------\n");
	printf("Digite opcao 1, 2 ou 3:\n");
	printf("1- Comecar o jogo.\n2- Contar a historia.\n3- Fechar o jogo.\n");
	scanf("%d", &opc);
	switch(opc){
		case 1:
			system("cls");
			printf("Digite o nome do seu personagem: ");
			fflush(stdin);
			gets(personagem.nome);
			
			do
			{
			printf("Voce tem 15 pontos para distribuir entre os atributos:\nFORCA\tCONSTITUICAO\tAGILIDADE\tDESTREZA\n\n");
			
				printf("FORCA: ");
				scanf("%lf", &personagem.atributo.forca);
				printf("CONSTITUICAO: ");
				scanf("%lf", &personagem.atributo.constituicao);
				printf("AGILIDADE: ");
				scanf("%lf", &personagem.atributo.agilidade);
				printf("DESTREZA: ");
				scanf("%lf", &personagem.atributo.destreza);
				pontos = personagem.atributo.agilidade + personagem.atributo.constituicao + personagem.atributo.destreza + personagem.atributo.forca;
				if(pontos > 15)
				{
					printf("Voce passou o limite de 15 pontos. Distribua os pontos dos atributos novamente.\n\n");
					system("pause");
					system("cls");
				}
			}
			while(pontos > 15);
			personagem.pv = 0;
			pontos_vida(&personagem.atributo.constituicao, &personagem.pv);
			printf("Pontos de vida: %.lf", personagem.pv);
			
			break;
			
		case 2:
			
			break;
			
		case 3:
			printf("Fechando...");
			break;
			
	}
	
}

