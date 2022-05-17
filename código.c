#include <stdio.h>
#include <stdlib.h>
#include<time.h>

typedef struct atributos
{
	int forca;
	int constituicao;
	int agilidade;
	int destreza;
} ATRIBUTO;

typedef struct equipamentos
{
	int arma;
	int armadura;
} EQUIPAMENTO;

typedef struct personagem
{
	char nome[50];
	int pv;
	EQUIPAMENTO equipamento;
	ATRIBUTO atributo;
} PERSONAGEM;

PERSONAGEM personagem;


void criar_personagem();

void pontos_vida(int* consta, int* pv)
{
	srand(time(NULL));
	int dado_1 = rand() % 6 + 1, dado_2 = rand() % 6 + 1 , dado_3 = rand() % 6 + 1;
	
	*pv =  dado_1 + dado_2 + dado_3 + (*consta);
	printf("\nDado 1= %i \nDado 2= %i \nDado 2= %i\n", dado_1, dado_2, dado_3);
	
}

int main()
{
	int opc;
	int pontos;
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
				scanf("%d", &personagem.atributo.forca);
				printf("CONSTITUICAO: ");
				scanf("%d", &personagem.atributo.constituicao);
				printf("AGILIDADE: ");
				scanf("%d", &personagem.atributo.agilidade);
				printf("DESTREZA: ");
				scanf("%d", &personagem.atributo.destreza);
				pontos = personagem.atributo.agilidade + personagem.atributo.constituicao + personagem.atributo.destreza + personagem.atributo.forca;
				if(pontos > 15)
				{
					printf("Voce passou o limite de 15 pontos. Distribua os pontos dos atributos novamente.\n\n");
					system("pause");
					system("cls");
				}
			}
			while(pontos != 15);
			personagem.pv = 0;
			pontos_vida(&personagem.atributo.constituicao, &personagem.pv);
			printf("Pontos de vida: %.d", personagem.pv);
			
			break;
			
		case 2:
			
			break;
			
		case 3:
			printf("Fechando...");
			break;
			
	}
	
}
