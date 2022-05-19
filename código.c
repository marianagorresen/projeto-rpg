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

void teste(PERSONAGEM P);

int arma_1();

void criar_personagem();

void pontos_vida();

int main()
{
	int opc, voltar = 1;
	int pontos;
	
	while(voltar == 1){
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
					if(pontos > 15 || pontos < 15)
					{
						printf("Distribua os pontos dos atributos novamente.\n\n");
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
				
			default:
				printf("valor invalido,tente novamente.\n\n");
				system("pause");
				system("cls");	
				voltar = 1;
		}
			
	}
	
}

void pontos_vida(int* consta, int* pv)
{
	srand(time(NULL));
	int dado_1 = rand() % 6 + 1, dado_2 = rand() % 6 + 1 , dado_3 = rand() % 6 + 1;
	
	*pv =  dado_1 + dado_2 + dado_3 + (*consta);
	printf("\nDado 1= %i \nDado 2= %i \nDado 2= %i\n", dado_1, dado_2, dado_3);
	
}

void teste(PERSONAGEM P)
{
	printf("dados atuais de jogador: \n");
	
	printf("nome :%s\n",P.nome);
	printf("vida :%i\n",P.pv);
	printf("forca %i\n",P.atributo.forca);
	printf("destreza %i\n",P.atributo.destreza);
	printf("constituicao %i\n",P.atributo.constituicao);
	printf("agilidade %i\n",P.atributo.agilidade);
	
	
}
