#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct atributos
{
	float forca;
	float constituicao;
	float agilidade;
	float destreza;
} ATRIBUTO;

typedef struct armadura
{
	char nome[20];
	float defesa;
} ARMADURA;

typedef struct arma
{
	char nome[20];
	float dano;
	int categoria;
} ARMA;

typedef struct equipamentos
{
	ARMA arma;
	ARMADURA armadura;
} EQUIPAMENTO;

typedef struct personagem
{
	char nome[50];
	float pv;
	EQUIPAMENTO equipamento;
	ATRIBUTO atributo;
} PERSONAGEM;

typedef struct adversario
{
	char nome[20];
	float pv;
	float dano;
	float defesa;
	float agilidade;
} AD;

AD adv_1 = {"um", 7, 5, 10, 3};
AD adv_2 = {"dois", 10, 7, 15, 5};
AD adv_3 = {"tres", 12, 10, 15, 7};
AD adv_4 = {"quatro", 15, 12, 15, 5};
AD adv_5 = {"cinco", 17, 15, 15, 7};
AD adv_6 = {"seis", 17, 17, 17, 10};

AD adversario;
ARMA arma;
PERSONAGEM personagem;

void dano_arma();
void ataque();
void defender();
void pocao();
void pontos_vida();

int main()
{
	int opc, voltar = 1;
	int adv_aleatorio, i = 0, j = 0, escolha;
	float pontos;
	int escolha_primeira_arma, escolha_armadura;

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
				scanf("%f", &personagem.atributo.forca);
				printf("CONSTITUICAO: ");
				scanf("%f", &personagem.atributo.constituicao);
				printf("AGILIDADE: ");
				scanf("%f", &personagem.atributo.agilidade);
				printf("DESTREZA: ");
				scanf("%f", &personagem.atributo.destreza);
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
			printf("Pontos de vida: %.f\n", personagem.pv);

			printf("\na hr de escolher a sua arma e comecar a sua jornada chegou...\n");
			printf("vc tem tres opcoes de armas: \n1.katana : arma leve\n2.espada : arma leve\n3.machado : arma pesada\n\ndigite respectivamente 1,2 ou 3: ");
			scanf("%i",&escolha_primeira_arma);

			if(escolha_primeira_arma == 1)
			{
				strcpy(personagem.equipamento.arma.nome, "katana");
				personagem.equipamento.arma.categoria = 1;
				arma = personagem.equipamento.arma;
			}
			else if(escolha_primeira_arma == 2)
			{
				strcpy(personagem.equipamento.arma.nome, "espada");
				personagem.equipamento.arma.categoria = 1;
				arma = personagem.equipamento.arma;
			}
			else if(escolha_primeira_arma == 3)
			{
				strcpy(personagem.equipamento.arma.nome, "machado");
				personagem.equipamento.arma.categoria = 2;
				arma = personagem.equipamento.arma;
			}
			else
			{
				printf("resposta invalida,tente novamente.\n\n");
				system("pause");
				system("cls");
			}

			printf("\nMomento de escolher a armadura\n");
			printf("Escolha uma das 3 opcoes:\n1- armadura1\n2- armadura2\n3- armadura 3\n\ndigite respectivamente 1,2 ou 3: ");
			scanf("%d", &escolha_armadura);

			if(escolha_armadura == 1)
			{
				strcpy(personagem.equipamento.armadura.nome, "armadura1");
				personagem.equipamento.armadura.defesa = 5 + 1.5*personagem.atributo.constituicao;
			}
			else if(escolha_armadura == 2)
			{
				strcpy(personagem.equipamento.armadura.nome, "armadura2");
				personagem.equipamento.armadura.defesa = 7 + 1.5*personagem.atributo.constituicao;
			}
			else if(escolha_armadura == 3)
			{
				strcpy(personagem.equipamento.armadura.nome, "armadura3");
				personagem.equipamento.armadura.defesa = 10 + 1.5*personagem.atributo.constituicao;
			} 

			//printf("\n\n%s, %.1f\n\n", personagem.equipamento.armadura.nome, personagem.equipamento.armadura.defesa);
			
			//combate
			system("pause");
			system("cls");
			printf("PRIMEIRO COMBATE\n");
			adv_aleatorio = rand() % 3 + 1;
			switch(adv_aleatorio){
				case 1:
					adversario = adv_1;
					break;
				case 2:
					adversario = adv_2;
					break;
				case 3:
					adversario = adv_3;
					break;
			}
			while(personagem.pv > 0 && adversario.pv > 0){
				if(personagem.atributo.agilidade > adversario.agilidade){
					//turno personagem
					printf("\nEscolha a sua acao:\n1- ATACAR\n2- DEFENDER\n3- USAR POCAO\n");
					scanf("%d", &escolha);
					if(i == 1)
					{
						personagem.equipamento.armadura.defesa = personagem.equipamento.armadura.defesa / 2;
						i = 0;
					}
					switch(escolha)
					{
						case 1:
							ataque(&personagem.equipamento.arma.dano, &adversario.defesa, &adversario.pv);
							break;
						case 2:
							//printf("antes: %d\n", personagem.equipamento.armadura.defesa);
							defender(&personagem.equipamento.armadura.defesa);
							//printf("depois: %d\n", personagem.equipamento.armadura.defesa);
							i++;
							break;
						case 3:
							pocao(&personagem.pv);
							break;	
					}					
					//turno oponente
					escolha = rand() % 3 + 1;
					if(j == 1)
					{
						adversario.defesa = adversario.defesa / 2;
						j = 0;
					}
					switch(escolha)
					{
						case 1:
							ataque(&adversario.dano, &personagem.equipamento.armadura.defesa, &personagem.pv);
							break;
						case 2:
							defender(&adversario.defesa);
							j++;
							break;
						case 3:
							pocao(&adversario.pv);
							break;	
					}
				}
				else
				{
					//turno oponente
					escolha = rand() % 3 + 1;
					if(j == 1)
					{
						adversario.defesa = adversario.defesa / 2;
						j = 0;
					}
					switch(escolha)
					{
						case 1:
							ataque(&adversario.dano, &personagem.equipamento.armadura.defesa, &personagem.pv);
							break;
						case 2:
							defender(&adversario.defesa);
							j++;
							break;
						case 3:
							pocao(&adversario.pv);
							break;	
					}
					//turno personagem
					printf("\nEscolha a sua acao:\n1- ATACAR\n2- DEFENDER\n3- USAR POCAO\n");
					scanf("%d", &escolha);
					if(i == 1)
					{
						personagem.equipamento.armadura.defesa = personagem.equipamento.armadura.defesa / 2;
						i = 0;
					}
					switch(escolha)
					{
						case 1:
							ataque(&arma.dano, &adversario.defesa, &adversario.pv);
							break;   
						case 2:							
							defender(&personagem.equipamento.armadura.defesa);
							i++;
							break;
						case 3:
							pocao(&personagem.pv);
							break;	
					}										
				}
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

void dano_arma(int *categoria, float *dano, float *forca, float *destre)
{
	srand(time(NULL));
	float dado_4 = rand() % 4 + 1, dado1_6 = rand() % 6 + 1, dado2_6 = rand() % 6 + 1, dado_12 = rand() % 12 + 1;
	if(*categoria == 1)
	{
		*dano = dado_12 + 1.5 * *forca + 6;
	}
	else if(*categoria == 2)
	{
		*dano = dado1_6 + dado2_6 + dado_4 + *destre + 3;
	}
}

void pontos_vida(float* consta, float* pv)
{
	srand(time(NULL));
	float dado_1 = rand() % 6 + 1, dado_2 = rand() % 6 + 1 , dado_3 = rand() % 6 + 1;
	
	*pv =  dado_1 + dado_2 + dado_3 + (*consta);
	//printf("\nDado 1= %i \nDado 2= %i \nDado 2= %i\n", dado_1, dado_2, dado_3);
}

void ataque(float *arma_jogador, float *armadura_oponente, float *pv_oponente)
{                                                          
	float dano;
	dano = *arma_jogador - *armadura_oponente;
	
	*pv_oponente = *pv_oponente - dano;	
	
}

void defender(float *defesa)
{
	*defesa = 2 * *defesa;
}

void pocao(float *pv)
{
	srand(time(NULL));
	int dado_1 = rand() % 6 + 1, dado_2 = rand() % 6 + 1 , dado_3 = rand() % 6 + 1;
	*pv = *pv + dado_1 + dado_2 + dado_3;
}
