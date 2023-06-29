#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

#define SESSIONS_LIMIT 5

struct character_t
{
	char name[15];
	float life;
	float attack;
	float defence;
	float score;
	bool is_dead;
};

int main()
{
	// ----- Declaring and defining variables -----
	char null[15];
	int game_difficulty = 1;
	int turn = 0;
	int stamina = 5;
	int action = 0;
	float damage = 0.0f;

	int i = 0, j = 0, session = 0; // counters

	struct character_t player[5];
	struct character_t goblin;
	struct character_t troll;

	// ----- Main loop -----
	while (session <= SESSIONS_LIMIT)
	{

		// ----- Main menu -----
		action = 0;
		fflush(stdin);
		system("clear");
		printf("\n-----Menu Principal-------\n\n");
		printf("Escolha uma opção: \n\n \033[1;34mNOVO JOGO[1]\n SCOREBOARD[2]\n SAIR[3]\033[0m \n\n");
		printf("--------------------------\n\n");
		scanf("%d", &action);
		// ----- Action 1, play new game -----
		if (action == 1 && session < SESSIONS_LIMIT)
		{

			system("clear");
			printf("\nEscolha a dificuldade do jogo:\n\n \033[1;34mFÁCIL[1]\n MÉDIO[2]\n DIFÍCIL[3]\033[0m \n\n"); // --Session menu --
			fflush(stdin);
			scanf("%i", &game_difficulty);
			while (game_difficulty != 1 && game_difficulty != 2 && game_difficulty != 3)
			{
				system("clear");
				game_difficulty = 0;
				printf("\n\033[1;31mPor favor, escolha uma opção válida\033[0m\n\n");
				printf("\nEscolha a dificuldade do jogo:\n\n \033[1;34mFÁCIL[1]\n MÉDIO[2]\n DIFÍCIL[3]\033[0m \n\n");
				fflush(stdin);
				scanf("%i", &game_difficulty);
			}
			system("clear");
			fflush(stdin);
			printf("\nEscolha o nome do seu personagem: \n\n");
			scanf("%s", &player[session].name);

			// ----- Initialiazing status depending on chosen difficulty -----
			switch (game_difficulty)
			{
			case (1):
				player[session].life = 100.0f;
				player[session].attack = 5.0f;
				player[session].defence = 0.0f;
				player[session].score = 0.0f;

				goblin.attack = 4.0f;
				goblin.life = 75.0f;

				troll.attack = 5.0f;
				troll.life = 85.0f;
				break;
			case (2):
				player[session].life = 100.0f;
				player[session].attack = 5.0f;
				player[session].defence = 0.0f;
				player[session].score = 0.0f;

				goblin.attack = 5.0f;
				goblin.life = 85.0f;

				troll.attack = 6.0f;
				troll.life = 95.0f;
				break;
			case (3):
				player[session].life = 100.0f;
				player[session].attack = 5.0f;
				player[session].defence = 0.0f;
				player[session].score = 0.0f;

				goblin.attack = 6.0f;
				goblin.life = 100.0f;

				troll.attack = 7.0f;
				troll.life = 110.0f;
				break;
			}

			// ----- Gameplay starts -----
			if (player[session].is_dead == false)
			{
				system("clear");
				printf("\nBem vindo\033[1;33m %s \033[0m!\nVocê é um bravo guerreiro(a) que está explorando as abandonadas minas de Kara'zum. \n", player[session].name);
				printf("Você acabou de entrar na mina por uma apertada fenda rochosa, que você encontrou enquanto rodeava a gigantesca montanha cinzenta. \n");
				printf("\nEstá muito escuro dentro da mina... se por acaso tivesse uma maneira de iluminar o ambiente... \n\n \033[1;34mACENDER TOCHA[1]\033[0m\n\n");
				fflush(stdin);
				scanf("%d", &action);
			}
			if (action != 1 && player[session].is_dead == false)
			{

				system("clear");
				printf("...\n");
				system("clear");

				while (action != 1)
				{
					printf("Continua muito escuro aqui dentro... Se por acaso tivesse uma maneira de iluminar esse ambiente... \n\n\033[1;34mACENDER TOCHA[1]\033[0m\n\n");
					fflush(stdin);
					scanf("%d", &action);
					system("clear");
				}
			}
			if (action == 1 && player[session].is_dead == false)
			{
				system("clear");
				printf("A luz da sua tocha revela uma cena aterrorizante: Um\033[1;32m goblin caçador\033[0m está posicionados a sua frente, pronto para atacar!\n\n \033[1;34mINICIAR BATALHA[1]\n TENTAR FUGIR[2]\033[0m\n\n");
				fflush(stdin);
				scanf("%d", &action);
			}
			while (action != 1 && action != 2)
			{
				printf("\n\033[1;31mPor favor, escolha uma opção válida\033[0m\n\n");
				fflush(stdin);
				action = 0;
				scanf("%i", &action);
			}

			if (action == 2 && player[session].is_dead == false)
			{ // Flee
				system("clear");
				printf("Você rapidamente virou as costas e saiu correndo. Você conseguiu fugir, porém esse é o fim de sua aventura! \n\n");
				sleep(3);
				player[session].is_dead = true;
				player[session].score = 0;
			}
			if (action == 1 && player[session].is_dead == false)
			{ // Start battle
				system("clear");
				printf("A batalha começou!\n\n");
				printf("você tem %.2f pontos de vida\n\n", player[session].life);

				while (goblin.life > 0.0f && player[session].is_dead == false)
				{ // Goblin battle loop
					sleep(1);

					printf("\033[1;34mPRESSIONE ENTER PARA ATACAR![]\033[0m \n"); // Player attacks
					fflush(stdin);
					getchar();
					damage = player[session].attack * ((rand() % 2) + 1) * 4.36f;
					printf("Você causou %.2f de dano ao\033[1;32m goblin caçador\033[0m!! \n", damage);
					goblin.life -= damage;

					if (goblin.life > 0.0f)
					{ // Goblin attacks
						printf("Vida do\033[1;32m goblin caçador\033[0m: %.2f\n\n", goblin.life);

						damage = goblin.attack * 3.1f - player[session].defence;
						player[session].life -= damage;
						sleep(1);
						printf("Você recebeu %.2f de dano do\033[1;32m goblin caçador\033[0m!! \n", damage);
						printf("Você tem %.2f pontos de vida\n\n", player[session].life);
						if (player[session].life <= 0.0f)
							player[session].is_dead = true;
					}
					else if (goblin.life <= 0.0f && player[session].is_dead == false)
					{ // Goblin dies
						goblin.life = 0.0f;
						printf("\033[1;32m goblin caçador\033[0m está morto!\n\n");
						player[session].score += 20 + (game_difficulty * 5);
						printf("Você ganhou 20 pontos de experiencia!\n");
						printf("Você tem\033[1;33m %.2f pontos de vida, \033[0me\033[1;33m %.2f pontos de experiencia!\033[0m\n\n", player[session].life, player[session].score);
					}
					if (player[session].is_dead == true)
					{ // Player dies
						printf("Você morreu! \n\n ---GAME OVER--- \n\n");
					}
				}

				printf("\033[1;34mPRESSIONE ENTER PARA CONTINUAR[]\033[0m \n");
				fflush(stdin);
				getchar();

				action = 0;

				system("clear");
				printf("Selecione sua proxima ação:\n\n \033[1;34mPROSSEGUIR[1]\n VASCULHAR GOBLIN[2]\033[0m \n\n");
				scanf("%i", &action);
				while (action != 1 && action != 2)
				{
					printf("\n\n\033[1;31mPor favor, escolha uma opção válida\033[0m\n\n");
					fflush(stdin);
					action = 0;
					scanf("%i", &action);
				}
				if (action == 2 && player[session].is_dead == false)
				{ // Loot goblin
					system("clear");
					printf("\nVocê encontrou uma armadura de malha de aço!\n");
					player[session].defence = 3.0f;
					printf("\033[1;33mBONUS DE + %.1f DE DEFESA ADIQUIRIDO!\033[0m \n\n", player[session].defence);

					printf("\033[1;34m PRESSIONE ENTER PARA SEGUIR EM FRENTE[]\033[0m \n");
					fflush(stdin);
					getchar();
					action = 1;
				}
				if (action == 1 && player[session].is_dead == false)
				{ // Continue exploring

					system("clear");
					printf("Você deixa o corpo do seu adversário para trás e continua a sua jornada caverna adentro...\n\n");
					sleep(1);
					printf("O terreno é irregular e você avança com passos cautelosos, um ar de perigo continua pairando na atmosfera\n\n");
					printf("\033[1;34m PRESSIONE ENTER PARA SEGUIR EM FRENTE[]\033[0m \n");
					fflush(stdin);
					getchar();
					system("clear");

					printf("Você tem uma sensação de que algo está te observando. Você para e vasculha com mais atenção os cantos escuros da caverna...\n\n");
					printf("\033[1;34m PRESSIONE ENTER PARA PROSSEGUIR[]\033[0m \n");
					fflush(stdin);
					getchar();
					system("clear");
					sleep(1);
					printf("\n. . .\n");
					sleep(1);
					system("clear");
				}
				printf("BAAAAM!! UM \033[1;31mTROLL DA MONTANHA\033[0m ACABA SALTAR DA ESCURIDÃO EM SUA DIREÇÃO!\n\n"); // Start troll battle
				printf("\033[1;34m PRESSIONE ENTER PARA LUTAR[]\033[0m \n");
				fflush(stdin);
				getchar();
				system("clear");
				printf("A batalha começou!\n\n");

				printf("você tem %.2f pontos de vida\n\n", player[session].life);
				while (troll.life > 0.0f && player[session].is_dead == false)
				{ // Troll battle loop
					sleep(1);
					printf("\033[1;34mPRESSIONE ENTER PARA ATACAR![]\033[0m \n"); // Player attacks
					fflush(stdin);
					getchar();
					damage = player[session].attack * ((rand() % 2) + 1) * 4.36f;
					printf("Você causou %.2f de dano ao\033[1;31m troll da montanha\033[0m!! \n", damage);
					troll.life -= damage;

					if (troll.life > 0.0f)
					{ // Troll attacks
						printf("Vida do\033[1;31m troll da montanha\033[0m: %.2f\n\n", troll.life);

						damage = troll.attack * 2.0f - player[session].defence;
						player[session].life -= damage;
						sleep(1);
						printf("Você recebeu %.2f de dano do\033[1;31m troll da montanha\033[0m!! \n", damage);
						printf("Você tem %.2f pontos de vida\n\n", player[session].life);
						if (player[session].life <= 0.0f)
							player[session].is_dead = true;
					}
					else if (troll.life <= 0.0f && player[session].is_dead == false)
					{ // Troll dies
						troll.life = 0.0f;
						printf("\033[1;31m troll da montanha\033[0m está morto!\n\n");
						player[session].score += 40 + (game_difficulty * 5);
						printf("Você ganhou 40 pontos de experiencia!\n");
						printf("Você tem\033[1;33m %.2f pontos de vida, \033[0me\033[1;33m %.2f pontos de experiencia!\033[0m\n\n", player[session].life, player[session].score);
						printf("\033[1;34mPRESSIONE ENTER PARA CONTINUAR[]\033[0m \n");
						fflush(stdin);
						getchar();

						system("clear");
						printf("\n\nParabéns nobre guerreiro, graças a sua bravura esta caverna se tornou um lugar mais seguro e livre de monstros. Esse é o fim de nossa aventura, muito obrigado por jogar!\n\n");
					}
					if (player[session].is_dead == true)
					{ // Player dies
						printf("\n\nVocê morreu! \n\n ------GAME OVER------ \n\n");
					}
				}
			}
			printf("\033[1;34mPRESSIONE ENTER PARA CONTINUAR[]\033[0m \n");
			fflush(stdin);
			getchar();

			// ----- Bubble sort scoreboard -----
			for (i = 0; i < session; i++)
			{
				for (j = 0; j < (session - i); j++)
				{
					if (player[j + 1].score > player[j].score)
					{
						struct character_t player_swap[5];
						player_swap[j] = player[j + 1];
						player[j + 1] = player[j];
						player[j] = player_swap[j];
					}
				}
			}

			session++;
			action = 2;
		}
		// ----- Action 1 but session limit was reached -----
		if (action == 1 && session >= SESSIONS_LIMIT)
		{
			printf("\n\n\033[1;31mVocê excedeu o limite de jogadas possiveis.\033[0m\n\n");
			sleep(1);
		}
		// ----- Action 2, scoreboard -----
		if (action == 2 && session > 0)
		{
			system("clear");
			printf("\n-----------------ScoreBoard-------------------\n"); //-- Print game-over scoreboard --
			for (i = 0; i < session; i++)
			{
				printf("JOGADOR: %-15s      PONTUAÇÃO: %3.2f\n", player[i].name, player[i].score);
			}
			printf("----------------------------------------------\n\n");
			printf("\033[1;34mPRESSIONE ENTER PARA CONTINUAR[]\033[0m \n");
			fflush(stdin);
			getchar();
		}
		// ----- Action 2 but player haven't played yet -----
		else if (action == 2 && session == 0)
		{
			system("clear");
			printf("\nPor favor, jogue uma partida primeiro para poder visualizar o scoreboard\n");
			sleep(1);
		}
		// ----- Action 3, exit game -----
		if (action == 3)
		{
			exit(0);
		}
		// ----- Invalid action -----
		if (action != 1 && action != 2 && action != 3)
		{
			printf("\n\n\033[1;31mPor favor, escolha uma opção válida\033[0m\n\n");
			sleep(1);
		}
	} // End main loop
	return 0;
}