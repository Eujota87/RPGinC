#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

struct character_t {
	char name[30];
	float exp;
	float lvl;
	float life;
	float attack;
	float defence;
	float score;
	int victory;
	int defeat;
	bool is_dead;
};

int main() {
	// ----- Declaring and defining variables -----
	char null[30];
	int game_difficulty = 1;
	int turn = 0;
	int stamina = 5;
	int action = 0;

	int i = 0, j = 0, session = 0; //counters

	struct character_t player[5];
	struct character_t goblin;
	player[session].victory = 0;
	player[session].defeat = 0;
	
	// ----- Main loop -----
	while (session <= 5) { 
		
		// ----- Main menu -----
		action = 0;
		fflush(stdin);
		printf("-----Menu Principal-------\n\n"); 
		printf("Escolha uma opção: \n\nNOVO JOGO[1]\nSCOREBOARD[2]\nSAIR[3]\n\n");
		scanf("%d", &action);
		// ----- Action 1, play new game -----
		if (action == 1 && session < 5) { 
			
			printf("\nEscolha a dificuldade do jogo:\n\nFÁCIL[1]\nMÉDIO[2]\nDIFÍCIL[3]\n\n"); // --Session menu --
			scanf("%i", &game_difficulty);
			printf("\nEscolha o nome do seu personagem: \n\n");
			scanf("%s", &player[session].name);

			// ----- Initialiazing status depending on chosen difficulty -----
			switch (game_difficulty) { 
			case (1):
				player[session].exp = 0.0f;
				player[session].lvl = 0.0f;
				player[session].life = 100.0f;
				player[session].attack = 5.0f;
				player[session].defence = 10.0f;

				goblin.attack = 4.0f;
				goblin.defence = 7.0f;
				goblin.life = 75.0f;
				goblin.is_dead = false;
				break;
			case (2):
				player[session].exp = 0.0f;
				player[session].lvl = 0.0f;
				player[session].life = 100.0f;
				player[session].attack = 5.0f;
				player[session].defence = 10.0f;

				goblin.attack = 5.0f;
				goblin.defence = 8.0f;
				goblin.life = 85.0f;
				goblin.is_dead = false;
				break;
			case (3):
				player[session].exp = 0.0f;
				player[session].lvl = 0.0f;
				player[session].life = 100.0f;
				player[session].attack = 5.0f;
				player[session].defence = 10.0f;

				goblin.attack = 6.0f;
				goblin.defence = 9.0f;
				goblin.life = 100.0f;
				goblin.is_dead = false;
				break;
			}
			
			printf("\nDificuldade escolhida: %i\n", game_difficulty);
			sleep(1);

			// ----- Gameplay starts -----
			if (player[session].is_dead == false) { 
				turn = 1;
				system("clear");
				printf("\nBem vindo %s!\nVocê é um bravo gurreiro(a) que está explorando as abandonadas minas de Kara'zum. \n", player[session].name);
				sleep(1);
				printf("Você acabou de entrar na mina por uma apertada fenda rochosa, que você encontrou enquanto rodeava a gigantesca montanha cinzenta. \n");
				sleep(1);
				printf("\nEstá muito escuro dentro da mina... se por acaso tivesse uma maneira de iluminar o ambiente... \n\n \033[1;31mACENDER TOCHA[1]\033[0m\n\n");
				fflush(stdin);
				scanf("%d", &action);
			}

			if (action != 1) {
				
				system("clear");
				printf("...\n");
				sleep(2);
				system("clear");
				
				while(action != 1) {
				printf("Continua muito escuro aqui dentro... Se por acaso tivesse uma maneira de iluminar esse ambiente... \n\nACENDER TOCHA[1]");
				fflush(stdin);
				scanf("%d", &action);
				sleep(1);
				system("clear");
				}
			}

			// ----- Bubble sort scoreboard -----
			for (i = 0; i < session; i++) { 
				for (j = 0; j < (session - i); j++) {
					if (player[j + 1].score > player[j].score) {
						struct character_t player_swap[5];
						player_swap[j] = player[j + 1];
						player[j + 1] = player[j];
						player[j] = player_swap[j];
					}
				}
			}


			// ----- Print game-over scoreboard -----
			printf("---ScoreBoard---\n"); 
			for (i = 0; i <= session; i++) {
				printf("JOGADOR: %s ---- PONTUAÇÃO: %.2f\n", player[i].name, player[i].score);
			}
			printf("----------------\n\n");

			session++;
		}

		// ----- Action 2, scoreboard -----
		else if (action == 2 && session > 0) { 
			printf("---ScoreBoard---\n"); //-- Print game-over scoreboard --
			for (i = 0; i < session; i++) {
				printf("JOGADOR: %s ---- PONTUAÇÃO: %.2f\n", player[i].name, player[i].score);
			}
			printf("----------------\n\n");
		}

		// ----- Action 3, exit game -----
		else if (action == 3) {
			exit(0);
		}
	}//End main loop
	
	return 0;
}