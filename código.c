#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct atributos
{
	int forca;
	int constituicao;
	int agilidade;
	int destreza;
} ATRIBUTO;

typedef struct arma
{
	char nome[20];
	int categoria;
} ARMA;

typedef struct equipamentos
{
	ARMA arma;
	int armadura;
} EQUIPAMENTO;

typedef struct personagem
{
	char nome[50];
	int pv;
	EQUIPAMENTO equipamento;
	ATRIBUTO atributo;
} PERSONAGEM;

ARMA arma;
PERSONAGEM personagem;

void teste(PERSONAGEM P);

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
	int escolha_primeira_arma;
	
	printf("-------------------\n------- MENU ------\n-------------------\n");
	printf("Digite opcao 1, 2 ou 3:\n");
	printf("1- Comecar o jogo.\n2- Contar a historia.\n3- Fechar o jogo.\n");
	scanf("%d", &opc);
	
	switch(opc)
    {
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
			printf("Pontos de vida: %.d\n", personagem.pv);
			
			printf("\na hr de escolher a sua arma e comecar a sua jornada chegou...\n");
			printf("vc tem tres opcoes de armas: \n1.katana : arma leve\n2.espada : arma leve\n3.machado : arma pesada\n\ndigite respectivamente 1,2 ou 3: ");
			scanf("%i",&escolha_primeira_arma);
			
			if(escolha_primeira_arma == 1)
			{
				strcpy(personagem.equipamento.arma.nome, "katana");
				personagem.equipamento.arma.categoria = 1;
				personagem.equipamento.arma = arma;
			}
			else if(escolha_primeira_arma == 2)
			{
				strcpy(personagem.equipamento.arma.nome, "espada");
				personagem.equipamento.arma.categoria = 1;
				personagem.equipamento.arma = arma;
			}
			else if(escolha_primeira_arma == 3)
			{
				strcpy(personagem.equipamento.arma.nome, "machado");
				personagem.equipamento.arma.categoria = 2;
				personagem.equipamento.arma = arma;
			}
			else
			{
				printf("resposta invalida,tente novamente.\n\n");
				system("pause");
				system("cls");
			}
			
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
	}

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
