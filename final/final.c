#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//moveable chart : x[0] for minion, x[1] for us
//Rabbit index : 1
const int Rabbit[2][5][5] = { 
	0,0,0,0,0,
	0,0,0,1,0,
	0,1,0,0,0,
	0,0,0,1,0,
	0,0,0,0,0,-1 };
//Rooster index : 2
const int Rooster[2][5][5] = {
	0,0,0,0,0,
	0,1,1,0,0,
	0,0,0,0,0,
	0,0,1,1,0,
	0,0,0,0,0,-1
};
//Sheep index : 3
const int Sheep[2][5][5] = {
	0,0,0,0,0,
	0,1,0,1,0,
	0,0,0,0,0,
	0,1,0,1,0,
	0,0,0,0,0,-1
};
//Snake index : 4
const int Snake[2][5][5] = {
	0,0,0,0,0,
	0,1,0,0,0,
	0,0,0,1,0,
	0,1,0,0,0,
	0,0,0,0,0,-1
};
//Tiger index : 5
const int Tiger[2][5][5] = {
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,1,
	0,0,0,0,0,
	0,0,0,0,0,-1
};
//Ox index : 6
const int Ox[2][5][5] = {
	0,0,0,0,0,
	0,0,1,0,0,
	0,0,0,1,0,
	0,0,1,0,0,
	0,0,0,0,0,-1
};
//Boar index : 7
const int Boar[2][5][5] = {
	0,0,0,0,0,
	0,0,0,0,0,
	0,1,0,1,0,
	0,0,0,0,0,
	0,0,0,0,0,-1
};
//Dog index : 8
const int Dog[2][5][5] = {
	0,0,0,0,0,
	0,1,1,1,0,
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,0,-1
};
//Dragon index : 9
const int Dragon[2][5][5] = {
	0,0,0,0,0,
	0,0,1,1,0,
	0,0,0,0,0,
	0,0,1,1,0,
	0,0,0,0,0,-1
};
//Horse index : 10
const int Horse[2][5][5] = {
	0,0,0,0,0,
	0,0,0,1,0,
	0,0,0,1,0,
	0,0,0,1,0,
	0,0,0,0,0,-1
};
//Monkey index : 11
const int Monkey[2][5][5] = {
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,0,
	0,1,1,1,0,
	0,0,0,0,0,-1
};
//Mouse index : 12
const int Mouse[2][5][5] = {
	0,0,1,0,0,
	0,0,0,0,0,
	0,0,0,1,0,
	0,0,0,0,0,
	0,0,1,0,0,-1
};
//Ostrich index : 13
const int Ostrich[2][5][5] = {
	0,0,0,0,1,
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,1,

	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,1,0,
	0,0,0,0,0,
	0,0,0,0,0,
};
//Frog index : 14
const int Frog[2][5][5] = {
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,1,0,
	0,0,0,0,0,
	0,0,0,0,0,

	0,0,0,0,1,
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,1
};
//Turtle index : 15
const int Turtle[2][5][5] = {
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,1,0,
	0,0,0,0,0,
	0,0,0,0,0,

	0,0,0,0,0,
	0,0,0,0,0,
	0,1,0,0,0,
	0,0,0,0,0,
	0,0,0,0,0
};

typedef struct Game 
{
	int board[5][5];//1 = us minion, 2 = us, -1 = enemy minion, -2 = enemy
	int current_player;//1 = us, -1 = enemy
	int our_card[2];
	int wild_card;
	int enemy_card[2];
}game_body;

char* readRepository(char *filename)
{
	/*
	* Input: absolute file path (file name if it is in the same directory with the file)
	* Ouput: contents of the file
	* Read the whole content of a specified file with its name and return the content
	* as a string pointer
	*
	*
	*/
	FILE *fp;
	char temp[1000];
	char *return_string = "";
	fp = fopen(filename, "r");

	if (fp == NULL) {
		printf("Can't open file\n");
	}

	char *temp3 = "";
	while (fgets(temp, 1000, fp) != NULL)
	{
		return_string = malloc((strlen(temp) + strlen(return_string)) * sizeof(char));
		strcpy(return_string, temp3);
		temp3 = malloc((strlen(temp) + strlen(temp3)) * sizeof(char));
		strcat(return_string, temp);
		strcpy(temp3, return_string);
	}

	fclose(fp);
	return return_string;
}

int name_to_index(char* name) {
	if (!strcmp(name, "Rabbit")) return 1;
	else if(!strcmp(name, "Rooster")) return 2;
	else if (!strcmp(name, "Sheep")) return 3;
	else if (!strcmp(name, "Snake")) return 4;
	else if (!strcmp(name, "Tiger")) return 5;
	else if (!strcmp(name, "Ox")) return 6;
	else if (!strcmp(name, "Boar")) return 7;
	else if (!strcmp(name, "Dog")) return 8;
	else if (!strcmp(name, "Dragon")) return 9;
	else if (!strcmp(name, "Horse")) return 10;
	else if (!strcmp(name, "Monkey")) return 11;
	else if (!strcmp(name, "Mouse")) return 12;
	else if (!strcmp(name, "Ostrich")) return 13;
	else if (!strcmp(name, "Frog")) return 14;
	else if (!strcmp(name, "Turtle")) return 15;
	else return 0;
}

char* index_to_name(int index, char* name) {
	switch (index)
	{
	case(1):
		strcpy(name, "Rabbit");
		break;
	case(2):
		strcpy(name, "Rooster");
		break;
	case(3):
		strcpy(name, "Sheep");
		break;
	case(4):
		strcpy(name, "Snake");
		break;
	case(5):
		strcpy(name, "Tiger");
		break;
	case(6):
		strcpy(name, "Ox");
		break;
	case(7):
		strcpy(name, "Boar");
		break;
	case(8):
		strcpy(name, "Dog");
		break;
	case(9):
		strcpy(name, "Dragon");
		break;
	case(10):
		strcpy(name, "Horse");
		break;
	case(11):
		strcpy(name, "Monkey");
		break;
	case(12):
		strcpy(name, "Mouse");
		break;
	case(13):
		strcpy(name, "Ostrich");
		break;
	case(14):
		strcpy(name, "Frog");
		break;
	case(15):
		strcpy(name, "Turtle");
		break;
	default:
		strcpy(name, "");
		break;
	}
	return name;
}

int* index_to_area(int index, int area[2][5][5]) {
	int temp[2][5][5] = { 0 };
	int *destiantion = temp;
	switch (index)
	{
	case(1):
		destiantion = Rabbit;
		break;
	case(2):
		destiantion = Rooster;
		break;
	case(3):
		destiantion = Sheep;
		break;
	case(4):
		destiantion = Snake;
		break;
	case(5):
		destiantion = Tiger;
		break;
	case(6):
		destiantion = Ox;
		break;
	case(7):
		destiantion = Boar;
		break;
	case(8):
		destiantion = Dog;
		break;
	case(9):
		destiantion = Dragon;
		break;
	case(10):
		destiantion = Horse;
		break;
	case(11):
		destiantion = Monkey;
		break;
	case(12):
		destiantion = Mouse;
		break;
	case(13):
		destiantion = Ostrich;
		break;
	case(14):
		destiantion = Frog;
		break;
	case(15):
		destiantion = Turtle;
		break;
	default:
		break;
	}
	for (int i = 0; i < 50; i++) {
		area[i / 50][i / 5][i % 5] = *(destiantion + i);
		/*area[i / 50][i / 5][i % 5] = *(
			destiantion + sizeof(*destiantion) * 50 * (i / 50) +
			sizeof(*destiantion)*(i / 5) +
			sizeof(*destiantion)*(i % 5));*/
	}
	return area;
}

void initial(struct Game* game, char* file_name) {
	if (file_name == NULL) {//UI, training mode
		int temp_board[5][5] = {
			1,0,0,0,-1,
			1,0,0,0,-1,
			2,0,0,0,-2,
			1,0,0,0,-1,
			1,0,0,0,-1
		};
		for (int i = 0; i < 25; i++) {
			game->board[i / 5][i % 5] = temp_board[i / 5][i % 5];
		}
		int All_card[] = {
			1,2,3,4,5,
			6,7,8,9,10,
			11,12,13,14,15
		};
		srand(time(NULL));//random five card
		//our card
		for (int i = 0; i < 2; i++) {
			int temp_card = rand() % 15;//random card
			if (All_card[temp_card] > 0) {//if the card is not used
				game->our_card[i] = temp_card + 1;//*(game).our_card[i]
				All_card[temp_card] = -1;
			}
			else {
				i--;
			}
		}
		//wild card
		for (int i = 0; i < 1; i++) {
			int temp_card = rand() % 15;//random card
			if (All_card[temp_card] > 0) {//if the card is not used
				game->wild_card = temp_card + 1;
				All_card[temp_card] = -1;
			}
			else {
				i--;
			}
		}
		//enemy card
		for (int i = 0; i < 2; i++) {
			int temp_card = rand() % 15;//random card
			if (All_card[temp_card] > 0) {//if the card is not used
				game->enemy_card[i] = temp_card + 1;
				All_card[temp_card] = -1;
			}
			else {
				i--;
			}
		}
		game->current_player = 1;//our first
	}
	else {//battle mode
		int temp_board[5][5] = { 0 };
		for (int i = 0; i < 25; i++) {
			game->board[i / 5][i % 5] = temp_board[i / 5][i % 5];
		}
		//start prasing file
		char* original;

		original = readRepository(file_name);
		char file_content[100][100];
		int file_index = 0;
		int each_char = 0;
		file_index = 0;
		int line = 0;
		for (;; each_char++) {
			if (*(original + sizeof(*original)*file_index) == '\n') {
				file_content[line][each_char] = '\0';
				each_char = -1;
				file_index++;
				line++;
				continue;
			}
			else if (*(original + sizeof(*original)*file_index) == '\0') {
				file_content[line][each_char] = '\0';
				break;
			}
			else if (*(original + sizeof(*original)*file_index) == '\r') {
				file_index++;
				continue;
			}
			else {
				file_content[line][each_char] = *(original + sizeof(*original)*file_index);
				file_index++;
				continue;
			}
		}
		//end of prasing file
		int player = 0;
		if (strcmp(file_content[0] + sizeof(file_content[0][0])*7, "Red")==0) {
			player = 1;
		}
		else {
			player = -1;
		}
		//prasing RedCard
		int original_card[3][2] = { 0 };//[0] for red, [1] for black, [2] for wild
		char temp[2][20] = { 0 };
		int char_index = 0;
		int card_index = 0;
		for (int index = 8;; index++) {//red card
			if (*(file_content[2] + index) == ',') {
				temp[card_index][char_index] = '\0';
				card_index++;
				char_index = 0;
				continue;
			}
			if (*(file_content[2] + index) == '\0') {
				temp[card_index][char_index] = '\0';
				break;
			}
			else {
				temp[card_index][char_index] = *(file_content[2] + index);
				char_index++;
			}
		}
		original_card[0][0] = name_to_index(temp[0]);
		original_card[0][1] = name_to_index(temp[1]);
		//end of red card

		char_index = 0;
		card_index = 0;
		for (int index = 10;; index++) {//black card
			if (*(file_content[3] + index) == ',') {
				temp[card_index][char_index] = '\0';
				card_index++;
				char_index = 0;
				continue;
			}
			if (*(file_content[3] + index) == '\0') {
				temp[card_index][char_index] = '\0';
				break;
			}
			else {
				temp[card_index][char_index] = *(file_content[3] + index);
				char_index++;
			}
		}
		original_card[1][0] = name_to_index(temp[0]);
		original_card[1][1] = name_to_index(temp[1]);
		//end of black card

		original_card[2][0] = name_to_index(file_content[4] + 11);//public card

		//putting card
		if (player == 1) {
			game->our_card[0] = original_card[0][0];
			game->our_card[1] = original_card[0][1];
			game->enemy_card[0] = original_card[1][0];
			game->enemy_card[1] = original_card[1][1];
			game->wild_card = original_card[2][0];
		}
		else {
			game->our_card[0] = original_card[1][0];
			game->our_card[1] = original_card[1][1];
			game->enemy_card[0] = original_card[0][0];
			game->enemy_card[1] = original_card[0][1];
			game->wild_card = original_card[2][0];
		}
		//end of putting card

		//[0] for red, [n][0] for main_pawn , [n][n][0] for x
		int temp_place[2][6][2];
		for (int i = 0; i < 12; i++) {
			temp_place[0][i / 2][i % 2] = -1;
			temp_place[1][i / 2][i % 2] = -1;
		}
		temp_place[0][0][0] = *(file_content[5] + 12) - '1';
		temp_place[0][0][1] = *(file_content[5] + 14) - '1';
		temp_place[1][0][0] = *(file_content[7] + 14) - '1';
		temp_place[1][0][1] = *(file_content[7] + 16) - '1';
		char_index = 0;
		for (int index = 1; index < 6;) {
			if (*(file_content[6] + char_index) == '(') {
				temp_place[0][index][0] = *(file_content[6] + char_index + 1) - '1';
				temp_place[0][index][1] = *(file_content[6] + char_index + 3) - '1';
				char_index++;
				index++;
			}
			else if (*(file_content[6] + char_index) == '\0') break;
			char_index++;
		}
		char_index = 0;
		for (int index = 1; index < 6;) {
			if (*(file_content[8] + char_index) == '(') {
				temp_place[1][index][0] = *(file_content[8] + char_index + 1) - '1';
				temp_place[1][index][1] = *(file_content[8] + char_index + 3) - '1';
				char_index++;
				index++;
			}
			else if (*(file_content[8] + char_index) == '\0') break;
			char_index++;
		}
		game->board[temp_place[0][0][0]][temp_place[0][0][1]] = 2*player;
		for (int i = 1; i < 6; i++) {
			if (temp_place[0][i][0] == -1)break;
			game->board[temp_place[0][i][0]][temp_place[0][i][1]] = 1*player;
		}
		game->board[temp_place[1][0][0]][temp_place[1][0][1]] = -2*player;
		for (int i = 1; i < 6; i++) {
			if (temp_place[1][i][0] == -1)break;
			game->board[temp_place[1][i][0]][temp_place[1][i][1]] = -1*player;
		}
		game->current_player = 1;
	}
}


void print_board(const struct Game game) {
	for (int i = 0; i < 25; i++) {
		if (game.board[i % 5][4 - (i / 5)] < 0)
			printf("%d ", game.board[i % 5][4 - (i / 5)]);
		else
			printf(" %d ", game.board[i % 5][4 - (i / 5)]);
		if (i % 5 == 4) printf("\n");
	}
	char card_name[5][20] = { '\0' };//0 & 1 for us, 2 for wlid, 3 & 4 for enemy
	int all_card[5];
	all_card[0] = game.our_card[0];
	all_card[1] = game.our_card[1];
	all_card[2] = game.wild_card;
	all_card[3] = game.enemy_card[0];
	all_card[4] = game.enemy_card[1];
	for (int i = 0; i < 5; i++) {
		char temp_name[20];
		index_to_name(all_card[i], temp_name);
		strcpy(card_name[i], temp_name);
	}
	printf("Our card : %s , %s\n", card_name[0], card_name[1]);
	printf("Wild card : %s\n", card_name[2]);
	printf("Enemy card : %s , %s\n", card_name[3], card_name[4]);
	for (int i = 0; i < 5; i++) {
		char temp_name[20];
		index_to_name(all_card[i], temp_name);
		strcpy(card_name[i], temp_name);
		printf("%s\n", temp_name);
		int area[2][5][5] = { 0 };
		index_to_area(all_card[i], area);
		if (area[1][0][0] == -1) {
			for (int j = 0; j < 25; j++) {
				printf("%d ", area[0][j % 5][4 - (j / 5)]);
				if (j % 5 == 4) printf("\n");
			}
		}
		else
		{
			printf("For minion :\n");
			for (int j = 0; j < 25; j++) {//minion
				printf("%d ", area[0][j % 5][4 - (j / 5)]);
				if (j % 5 == 4) printf("\n");
			}
			printf("For main pawn :\n");
			for (int j = 0; j < 25; j++) {//main pawn
				printf("%d ", area[1][j % 5][4 - (j / 5)]);
				if (j % 5 == 4) printf("\n");
			}
		}
		printf("\n");
	}
}

void change_player(struct Game *original) {
	game_body temp_game = *original;
	int temp[5][5];
	for (int i = 0; i < 25; i++) {
		temp[i / 5][i % 5] = original->board[4 - (i / 5)][4 - (i % 5)];
	}
	for (int i = 0; i < 25; i++) {
		original->board[i / 5][i % 5] = temp[i / 5][i % 5];
	}
	original->current_player = -temp_game.current_player;
	original->enemy_card[0] = temp_game.our_card[0];
	original->enemy_card[1] = temp_game.our_card[1];
	original->our_card[0] = temp_game.enemy_card[0];
	original->our_card[1] = temp_game.enemy_card[1];
	original->wild_card = temp_game.wild_card;
}

int* all_move(const game_body game, int able[40][2][2], int card) {//[n][0] for x, [n][1] for y, [0] for initial, [1] for final
	int index = 0;
	int area[2][5][5] = { 0 };
	index_to_area(card, area);
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			if (game.board[x][y] * game.current_player == 1 && card != 15) {
				for (int cardx = 0; cardx < 5; cardx++) {
					for (int cardy = 0; cardy < 5; cardy++) {
						if (area[0][cardx][cardy]) {
							if (x + (cardx - 2) < 0 || x + (cardx - 2) > 4 || y + (cardy - 2) < 0 || y + (cardy - 2) > 4) {
								continue;
							}
							if (game.board[x + (cardx - 2)][y + (cardy - 2)] * game.current_player > 0) continue;
							able[index][0][0] = x;
							able[index][0][1] = y;
							able[index][1][0] = x + (cardx - 2);
							able[index][1][1] = y + (cardy - 2);
							index++;
						}
					}
				}

			}
			else if (game.board[x][y] * game.current_player == 2 && card != 15) {
				for (int cardx = 0; cardx < 5; cardx++) {
					for (int cardy = 0; cardy < 5; cardy++) {
						if (area[1][0][0] == -1) {
							//general condition
							if (area[0][cardx][cardy]) {
								if (x + (cardx - 2) < 0 || x + (cardx - 2) > 4 || y + (cardy - 2) < 0 || y + (cardy - 2) > 4) {
									continue;
								}
								if (game.board[x + (cardx - 2)][y + (cardy - 2)] * game.current_player > 0) continue;
								able[index][0][0] = x;
								able[index][0][1] = y;
								able[index][1][0] = x + (cardx - 2);
								able[index][1][1] = y + (cardy - 2);
								index++;
							}
						}
						else if (area[1][0][0] != -1) {
							//special card
							if (area[1][cardx][cardy]) {
								if (x + (cardx - 2) < 0 || x + (cardx - 2) > 4 || y + (cardy - 2) < 0 || y + (cardy - 2) > 4) {
									continue;
								}
								if (game.board[x + (cardx - 2)][y + (cardy - 2)] * game.current_player > 0) continue;
								able[index][0][0] = x;
								able[index][0][1] = y;
								able[index][1][0] = x + (cardx - 2);
								able[index][1][1] = y + (cardy - 2);
								index++;
							}
						}
					}
				}
			}
			else if (card == 15) {
				for (int cardx = 0; cardx < 5; cardx++) {
					for (int cardy = 0; cardy < 5; cardy++) {
						if (game.board[x][y] * game.current_player > 0) {
							if (area[0][cardx][cardy]) {
								if (x + (cardx - 2) < 0 || x + (cardx - 2) > 4 || y + (cardy - 2) < 0 || y + (cardy - 2) > 4) {
									continue;
								}
								if (game.board[x + (cardx - 2)][y + (cardy - 2)] * game.board[x][y] > 0) continue;
								able[index][0][0] = x;
								able[index][0][1] = y;
								able[index][1][0] = x + (cardx - 2);
								able[index][1][1] = y + (cardy - 2);
								index++;
							}
						}
						if (game.board[x][y] * game.current_player == -2) {
							if (area[1][cardx][cardy]) {
								if (x + (cardx - 2) < 0 || x + (cardx - 2) > 4 || y + (cardy - 2) < 0 || y + (cardy - 2) > 4) {
									continue;
								}
								if (game.board[x + (cardx - 2)][y + (cardy - 2)] * game.current_player < 0) continue;
								able[index][0][0] = x;
								able[index][0][1] = y;
								able[index][1][0] = x + (cardx - 2);
								able[index][1][1] = y + (cardy - 2);
								index++;
							}
						}
					}
				}
			}
		}
	}
	return area;
}

int* valid_move(const struct Game game, int *current, int *destination, int card) {
	int result[5][5] = { 0 };
	return NULL;
}

int win_game(const game_body game) {
	if (game.board[2][4] == 2) {
		return 1;
	}
	else if (game.board[2][0] == -2)
	{
		return -1;
	}
	int our_main = 0, enemy_main = 0;
	for (int i = 0; i < 25; i++) {
		if (game.board[i / 5][i % 5] == 2) our_main = 1;
		else if (game.board[i / 5][i % 5] == -2)
		{
			enemy_main = 1;
		}
	}
	if (!our_main) return -1;
	else if (!enemy_main) return 1;
	return 0;
}

void player_move(struct Game* game) {
	char command[3][20];
	while (1) {
		//command initial
		for (int i = 0; i < 60; i++) {
			command[i / 20][i % 20] = '\0';
		}
		gets(command[0]);
		gets(command[1]);
		gets(command[2]);
		//check illegal, prasing command
		if (command[0][0] != 'U'|| command[1][0] != 'S'|| command[2][0] != 'E') {
			printf("Input again!\n");
			continue;
		}
		int selected_card = -1;
		//printf(command[0] + 4);
		if (name_to_index(command[0] + 4) == game->our_card[0]) selected_card = 0;
		else if (name_to_index(command[0] + 4) == game->our_card[1]) selected_card = 1;
		else {
			printf("Input again!\n");
			continue;
		}
		int start_end[2][2] = { 0 };//[n][0] for x, [n][1] for y, [0] for initial, [1] for final
		if (command[1][7] - '0' < 1 || command[1][7] - '0' > 5 || command[1][9] - '0' < 1 || command[1][9] - '0' > 5) {
			printf("Input again!\n");
			continue;
		}
		start_end[0][0] = command[1][7] - '0'-1;
		start_end[0][1] = command[1][9] - '0'-1;
		if (command[2][5] - '0' < 1 || command[2][5] - '0' > 5 || command[2][7] - '0' < 1 || command[2][7] - '0' > 5) {
			printf("Input again!\n");
			continue;
		}
		start_end[1][0] = command[2][5] - '0'-1;
		start_end[1][1] = command[2][7] - '0'-1;
		//end of parsing & checking

		//game_body* temp = game;
		int able[2][40][2][2];//[0] for first card, [1] for second card
		for (int i = 0; i < 40; i++) {
			for (int j = 0; j < 4; j++) {
				able[0][i][j / 2][j % 2] = -1;
				able[1][i][j / 2][j % 2] = -1;
			}
			
		}
		for (int card = 0; card < 2; card++) {
			all_move(*game, able[card], game->our_card[card]);
		}
		int possible=0;
		for (int i = 0; i < 40; i++) {
			//if end of possible
			if (able[selected_card][i][0][0] == -1) break;
			int all_possible = 0;
			for (int j = 0; j < 4; j++) {//check start & end
				if (able[selected_card][i][j / 2][j % 2] == start_end[j / 2][j % 2]) all_possible++;
			}
			if (all_possible == 4) {
				possible = 1;
				break;
			}
		}
		if (possible) {
			int role = game->board[start_end[0][0]][start_end[0][1]];
			game->board[start_end[0][0]][start_end[0][1]] = 0;
			game->board[start_end[1][0]][start_end[1][1]] = role;
			return;
		}
		else {
			printf("Can't move! Input again!\n");
			continue;
		}
	}
}

/*
01 function alphabeta(node, depth, alpha, beta, maximizingPlayer) is
02     if depth = 0 or node is a terminal node then
03         return the heuristic value of node
04     if maximizingPlayer then
05         v := -INF
06         for each child of node do
07             v := max(v, alphabeta(child, depth - 1, alpha, beta, FALSE))
08             alpha := max(alpha, v)
09             if beta ? alpha then
10                 break (* beta cut-off *)
11         return v
12     else
13         v := +INF
14         for each child of node do
15             v := min(v, alphabeta(child, depth - 1, alpha, beta, TRUE))
16             beta := min(beta, v)
17             if beta ? alpha then
18                 break (* alpha cut-off *)
19         return v
*/

void computer_move(struct Game* game) {
	
}

void UI();
void AI(int argc, char* args[]);
void test();

int main(int argc, char *argv[]) {
	
	//test();
	//UI();
	//argc = 4;
	AI(argc, argv);
	return 0;
}

void UI() {
	printf(
		"Onitama start!\n"
		"Select mode : 1 for PvP, 2 for PvC, 3 for CvC\n");
	int mode=0;//1 for PvP, 2 for PvC, 3 for CvC
	scanf("%d", &mode);
	getchar();
	struct Game main_game;
	initial(&main_game,NULL);
	char input[20] = { 0 };
	if (mode == 1) {//PvP
		while (1) {
			print_board(main_game);
			for (int i = 0; i < 20; i++) {//input renew
				input[i] = 0;
			}
			player_move(&main_game);//first player
			change_player(&main_game);//change board
			int win = win_game(main_game);
			if (win) {
				printf("Player %d win!\n", win);
				return;
			}
		}
	}
	else if (mode == 2) {//PvC

	}
}

void AI(int argc, char* args[]) {
	game_body main_game;
	initial(&main_game, args[1]);
	print_board(main_game);
	system("PAUSE");
}

void test() {
	game_body game;
	initial(&game, NULL);
	game.our_card[0] = 15;
	print_board(game);
	int able[2][40][2][2] = { 0 };
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 4; j++) {
			able[0][i][j / 2][j % 2] = -1;
			able[1][i][j / 2][j % 2] = -1;
		}
	}
	all_move(game, able[0], game.our_card[0]);
	all_move(game, able[1], game.our_card[1]);
	char name[40];
	printf("Use card %s\n", index_to_name(game.our_card[0], name));
	for (int i = 0; i < 40; i++) {
		if (able[0][i][0][0] == -1) break;
		printf("Start (%d,%d), End (%d,%d)\n", able[0][i][0][0], able[0][i][0][1], able[0][i][1][0], able[0][i][1][1]);
	}
	printf("Use card %s\n", index_to_name(game.our_card[1], name));
	for (int i = 0; i < 40; i++) {
		if (able[1][i][0][0] == -1) break;
		printf("Start (%d,%d), End (%d,%d)\n", able[1][i][0][0], able[1][i][0][1], able[1][i][1][0], able[1][i][1][1]);
	}
	printf("\n");
	change_player(&game);
	print_board(game);
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 4; j++) {
			able[0][i][j / 2][j % 2] = -1;
			able[1][i][j / 2][j % 2] = -1;
		}
	}
	all_move(game, able[0], game.our_card[0]);
	all_move(game, able[1], game.our_card[1]);
	//char name[40];
	printf("Use card %s\n", index_to_name(game.our_card[0], name));
	for (int i = 0; i < 40; i++) {
		if (able[0][i][0][0] == -1) break;
		printf("Start (%d,%d), End (%d,%d)\n", able[0][i][0][0], able[0][i][0][1], able[0][i][1][0], able[0][i][1][1]);
	}
	printf("Use card %s\n", index_to_name(game.our_card[1], name));
	for (int i = 0; i < 40; i++) {
		if (able[1][i][0][0] == -1) break;
		printf("Start (%d,%d), End (%d,%d)\n", able[1][i][0][0], able[1][i][0][1], able[1][i][1][0], able[1][i][1][1]);
	}
	printf("\n");
	system("PAUSE");
}