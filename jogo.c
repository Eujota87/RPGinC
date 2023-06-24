#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

struct character_t {
	char name[15];
	float life;
	float attack;
	float defence;
	float score;
	bool is_dead;
};

int main() {
	// ----- Declaring and defining variables -----
	char null[15];
	int game_difficulty = 1;
	int turn = 0;
	int stamina = 5;
	int action = 0;

	int i = 0, j = 0, session = 0; //counters

	struct character_t player[5];
	struct character_t goblin;
	
	// ----- Main loop -----
	while (session <= 5) { 
		
		// ----- Main menu -----
		action = 0;
		fflush(stdin);
		system("clear");
		printf("\n-----Menu Principal-------\n\n"); 
		printf("Escolha uma opção: \n\n \033[1;34mNOVO JOGO[1]\n SCOREBOARD[2]\n SAIR[3]\033[0m \n\n");
		printf("--------------------------\n\n");
		scanf("%d", &action);
		// ----- Action 1, play new game -----
		if (action == 1 && session < 5) { 
			
			system("clear");
			printf("\nEscolha a dificuldade do jogo:\n\n \033[1;34mFÁCIL[1]\n MÉDIO[2]\n DIFÍCIL[3]\033[0m \n\n"); // --Session menu --
			scanf("%i", &game_difficulty);
			while (game_difficulty != 1 && game_difficulty != 2 && game_difficulty != 3) {
				sleep(1);
				system("clear");
				printf("\nPor favor, escolha uma opção válida!\n");
				sleep(1);
			    printf("\nEscolha a dificuldade do jogo:\n\n \033[1;34mFÁCIL[1]\n MÉDIO[2]\n DIFÍCIL[3]\033[0m \n\n");
			    scanf("%i", &game_difficulty);
			}
			sleep(1);
			system("clear");
			printf("\nEscolha o nome do seu personagem: \n\n");
			scanf("%s", &player[session].name);

			// ----- Initialiazing status depending on chosen difficulty -----
			switch (game_difficulty) { 
			case (1):
				player[session].life = 100.0f;
				player[session].attack = 5.0f;
				player[session].defence = 10.0f;
				player[session].score = 0.0f;

				goblin.attack = 4.0f;
				goblin.defence = 7.0f;
				goblin.life = 75.0f;
				goblin.is_dead = false;
				break;
			case (2):
				player[session].life = 100.0f;
				player[session].attack = 5.0f;
				player[session].defence = 10.0f;
				player[session].score = 0.0f;				

				goblin.attack = 5.0f;
				goblin.defence = 8.0f;
				goblin.life = 85.0f;
				goblin.is_dead = false;
				break;
			case (3):
				player[session].life = 100.0f;
				player[session].attack = 5.0f;
				player[session].defence = 10.0f;
				player[session].score = 0.0f;

				goblin.attack = 6.0f;
				goblin.defence = 9.0f;
				goblin.life = 100.0f;
				goblin.is_dead = false;
				break;
			}
			
			sleep(1);

			// ----- Gameplay starts -----
			if (player[session].is_dead == false) { 
				system("clear");
				printf("\nBem vindo\033[1;33m %s \033[0m!\nVocê é um bravo guerreiro(a) que está explorando as abandonadas minas de Kara'zum. \n", player[session].name);
				sleep(1);
				printf("Você acabou de entrar na mina por uma apertada fenda rochosa, que você encontrou enquanto rodeava a gigantesca montanha cinzenta. \n");
				sleep(1);
				printf("\nEstá muito escuro dentro da mina... se por acaso tivesse uma maneira de iluminar o ambiente... \n\n \033[1;34mACENDER TOCHA[1]\033[0m\n\n");
				fflush(stdin);
				scanf("%d", &action);
			}
			if (action != 1 && player[session].is_dead == false) {
				
				system("clear");
				printf("...\n");
				sleep(2);
				system("clear");
				
				while(action != 1) {
					printf("Continua muito escuro aqui dentro... Se por acaso tivesse uma maneira de iluminar esse ambiente... \n\n\033[1;34mACENDER TOCHA[1]\033[0m\n\n");
					fflush(stdin);
					scanf("%d", &action);
					sleep(1);
					system("clear");
				}
			}
			if (action == 1 && player[session].is_dead == false) {
				system("clear");
				printf("A luz da sua tocha revela uma cena aterrorizante: Dois\033[1;32m goblins caçadores\033[0m estão posicionados a sua frente, prontos para atacar!\n\n \033[1;34mINICIAR BATALHA[1]\n TENTAR FUGIR[2]\033[0m\n\n");
				fflush(stdin);
				scanf("%d", &action);
				sleep(1);			
			}
			if (action == 2 && player[session].is_dead == false) {
				system("clear");
				sleep(1);
				printf("Você rapidamente virou as costas e saiu correndo. Você conseguiu fugir, porém esse é o fim de seu aventura! \n");
				player[session].is_dead = true;
				player[session].score = 0;
			}
			if (action == 1 && player[session].is_dead == false) {
				system("clear");
				printf("\nataque\n");
				sleep(1);
				player[session].score = session + 20;
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

			session++;
			action = 2;
		}

		// ----- Action 2, scoreboard -----
		if (action == 2 && session > 0) { 
			system("clear");
			printf("\n-----------------ScoreBoard-------------------\n"); //-- Print game-over scoreboard --
			for (i = 0; i < session; i++) {
				printf("JOGADOR: %-15s      PONTUAÇÃO: %3.2f\n", player[i].name, player[i].score);
			}
			printf("----------------------------------------------\n\n");
			printf("\033[1;34mPRESSIONE ENTER PARA CONTINUAR[]\033[0m \n");
			fflush(stdin);
			getchar();
		}
		else if (action == 2 && session == 0) {
			system("clear");
			printf("\nPor favor, jogue uma partida primeiro para poder visualizar o scoreboard\n");
			sleep(2);
		}

		// ----- Action 3, exit game -----
		if (action == 3) {
			exit(0);
		}
		if (action != 1 && action != 2 && action != 3) {
			printf("\n\n\033[1;31mPor favor, escolha uma opção válida\033[0m\n\n");
			sleep(2);		
		}
	}//End main loop
	
	return 0;
}