#include <stdio.h>
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

AD adv_1 = {"GOBLIN", 10, 10, 3, 5};
AD adv_2 = {"BRUXA", 20, 10, 5, 2};
AD adv_3 = {"DUENDE", 10, 12, 2, 4};
AD adv_4 = {"GIGANTE", 20, 16, 15, 1};
AD adv_5 = {"QUIMERA",15, 7, 15, 7};
AD adv_6 = {"REI POSSUIDO", 25, 25, 10, 9};

AD adversario;
ARMA arma;
PERSONAGEM personagem;

void dano_arma();
void ataque();
void defender();
void pocao();
void pontos_vida();
void premiacao_nivel_1();
void premiacao_arma_1();

int main()
{
	int opc, voltar = 1;
	int adv_aleatorio, i = 0, j = 0, escolha;
	int escolha_premiacao_1, escolha_premiacao_2;
	float pontos;
	int escolha_primeira_arma, escolha_armadura, pa = 0, p = 0;

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
			printf("Escolha uma das 3 opcoes:\n1- capacete\n2- manopla\n3- colete\n\ndigite respectivamente 1,2 ou 3: ");
			scanf("%i", &escolha_armadura);

			if(escolha_armadura == 1)
			{
				strcpy(personagem.equipamento.armadura.nome, "capacete");
				personagem.equipamento.armadura.defesa = 5 + 1.5*personagem.atributo.constituicao;
			}
			else if(escolha_armadura == 2)
			{
				strcpy(personagem.equipamento.armadura.nome, "manopla");
				personagem.equipamento.armadura.defesa = 5 + 1.5*personagem.atributo.constituicao;
			}
			else if(escolha_armadura == 3)
			{
				strcpy(personagem.equipamento.armadura.nome, "colete");
				personagem.equipamento.armadura.defesa = 5 + 1.5*personagem.atributo.constituicao;
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
			while(personagem.pv > 0 && adversario.pv > 0)
			{
				dano_arma(&arma.categoria, &arma.dano, &personagem.atributo.forca, &personagem.atributo.destreza);
				
				if(personagem.atributo.agilidade > adversario.agilidade)
				{
					//turno personagem
					voltar = 1;
					while(voltar == 1)
					{
						voltar = 0;
						if(i == 1)
						{
							personagem.equipamento.armadura.defesa = personagem.equipamento.armadura.defesa / 2;
							i = 0;
						}
						printf("\nEscolha a sua acao:\n1- ATACAR\n2- DEFENDER\n3- USAR POCAO\n");
						scanf("%d", &escolha);
						switch(escolha)
						{
							case 1:
								ataque(&arma.dano, &adversario.defesa, &adversario.pv);
								printf("%s escolheu ataque\n", personagem.nome);
								printf("Ponto de vida de %s: %f\nPonto de vida do adversario %s: %f\n\n", personagem.nome, personagem.pv, adversario.nome, adversario.pv);	
								break;
							case 2:
								//printf("antes: %d\n", personagem.equipamento.armadura.defesa);
								defender(&personagem.equipamento.armadura.defesa);
								printf("%s escolheu defender\n", personagem.nome);
								printf("Valor da defesa por um round: %f\n", personagem.equipamento.armadura.defesa);
								i++;
								break;
							case 3:
								if(pa < 3){
									pocao(&personagem.pv);
									printf("%s escolheu usar pocao\n", personagem.nome);
									pa++;
								}else{
									printf("\nPocao ja foi usada 3 vezes, escolha outra acao\n");
									voltar = 1;
								}
								break;	
						}
					}					
					//turno oponente
					if(p < 3){
						escolha = rand() % 3 + 1;
					}else{
						escolha = rand() % 2 + 1;
					}
			
					if(j == 1)
					{
						adversario.defesa = adversario.defesa / 2;
						j = 0;
					}
					switch(escolha)
					{
						case 1:
							ataque(&adversario.dano, &personagem.equipamento.armadura.defesa, &personagem.pv);
							printf("%s escolheu ataque\n", adversario.nome);
							break;
						case 2:
							defender(&adversario.defesa);
							printf("%s escolheu defender\n", adversario.nome);
							j++;
							break;
						case 3:
							pocao(&adversario.pv);
							printf("%s escolheu usar pocao\n", adversario.nome);
							p++;
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
							printf("%s escolheu ataque\n", adversario.nome);
							break;
						case 2:
							defender(&adversario.defesa);
							printf("%s escolheu defender\n", adversario.nome);
							j++;
							break;
						case 3:
							pocao(&adversario.pv);
							printf("%s escolheu usar pocao\n", adversario.nome);
							break;	
					}
				//turno personagem
				voltar = 1;
				while(voltar == 1)
				{
					voltar = 0;
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
							printf("%s escolheu ataque\n", personagem.nome);
							printf("Ponto de vida de %s: %f\nPonto de vida do adversario %s: %f\n\n", personagem.nome, personagem.pv, adversario.nome, adversario.pv);							
							break;   
						case 2:							
							defender(&personagem.equipamento.armadura.defesa);
							printf("%s escolheu defender\n", personagem.nome);
							printf("Valor da defesa por um round: %f\n", personagem.equipamento.armadura.defesa);
							i++;
							break;
						case 3:
							if(pa < 3){
								pocao(&personagem.pv);
								printf("%s escolheu usar pocao\n", personagem.nome);
								pa++;
							}else{
								printf("\nPocao ja foi usada 3 vezes, escolha outra acao\n");
								voltar = 1;
							}
							break;	
					}
				}
			}
		}
	
			if(personagem.pv == 0)
			{
				printf("GAME OVER");
				break;
			}
		
			printf("vc conseguiu vencer ao primeiro combate,agora eh a hora de escolher a recompensa:\n\n1.SUBIR 1 NIVEL,vc ganha mais 5 pontos de atributos.\n2.mais vida.\n3.arma nova.");
			scanf("%i",&escolha_premiacao_1);
			
			if(escolha_premiacao_1 == 1)
			{
				premiacao_nivel_1(&personagem.atributo.forca, &personagem.atributo.constituicao, &personagem.atributo.agilidade, &personagem.atributo.destreza);
			}
			else if(escolha_premiacao_1 == 2)
			{
				personagem.pv = personagem.pv + personagem.atributo.constituicao;	
			}
			else if(escolha_premiacao_1 == 3)
			{
				premiacao_arma_1(&arma.nome, &arma.categoria);	
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
	return 0;
}



void premiacao_arma_1(char* arma_nome[20], int* cat_arma)
{
	int escolha;
	
	printf("\nvc tem 3 aopcoes de armas melhores para escolher:\n");
	printf("vc tem tres opcoes de armas: \n1.katana amaldicoada : arma leve\n2.espada do rei : arma leve\n3.machado de guerra : arma pesada\n\ndigite respectivamente 1,2 ou 3: ");
	scanf("%i",&escolha);

	if(escolha == 1)
	{
		strcpy(*arma_nome, "katana amaldicoada");
		*cat_arma = 1;
		arma = personagem.equipamento.arma;
	}
	else if(escolha == 2)
	{
		strcpy(*arma_nome, "espada do rei");
		*cat_arma = 1;
		arma = personagem.equipamento.arma;
	}
	else if(escolha == 3)
	{
		strcpy(*arma_nome, "machado de guerra");
		*cat_arma = 2;
		arma = personagem.equipamento.arma;
	}
	else
	{
	printf("resposta invalida,tente novamente.\n\n");
	system("pause");
	system("cls");
	}
}
void premiacao_nivel_1(float* forca, float* consti, float* agilit, float* destre)
{
	float f,c,a,d,pontos;
	
	printf("vc tem 5 pontos de atributos para serem distribuidos.\n");
	printf("FORCA: ");
	scanf("%f", &f);
	printf("CONSTITUICAO: ");
	scanf("%f", &c);
	printf("AGILIDADE: ");
	scanf("%f", &a);
	printf("DESTREZA: ");
	scanf("%f", &d);
	pontos = f + c + a + d;
				
	if(pontos > 5 || pontos < 5)
	{
		printf("Distribua os pontos dos atributos novamente.\n\n");
		system("pause");
		system("cls");
	}
	*forca = *forca + f;
	*consti = *consti + c;
	*agilit = *agilit + a;
	*destre = *destre  + d;
}

void dano_arma(int *categoria, float *dano, float *forca, float *destre)
{
	srand(time(NULL));
	float dado_4 = rand() % 4 + 1, dado1_6 = rand() % 6 + 1, dado2_6 = rand() % 6 + 1, dado_12 = rand() % 12 + 1;
	if(*categoria == 2)
	{
		*dano = dado_12 + *forca * 1.5 + 6;
	}
	else if(*categoria == 1)
	{
		*dano = dado1_6 + dado2_6 + dado_4 + *destre + 3;
		
	}
}

void pontos_vida(float* consta, float* pv)
{
	srand(time(NULL));
	float dado_1 = rand() % 6 + 1, dado_2 = rand() % 6 + 1 , dado_3 = rand() % 6 + 1;
	
	*pv =  dado_1 + dado_2 + dado_3 + (*consta);
}

void ataque(float *arma_jogador, float *armadura_oponente, float *pv_oponente)
{                                                          
	float dano;
	dano = *arma_jogador - *armadura_oponente;
	//printf("\n%f = %f - %f\n", dano, *arma_jogador, *armadura_oponente);
	//printf("\n%f = %f - %f\n", *pv_oponente, *pv_oponente, dano);
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
