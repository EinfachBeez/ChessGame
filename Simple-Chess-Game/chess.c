// Include needed packages
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Define Color Codes for better understanding
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

// 2D Array of a 8x8 chess board
char board[8][8] = {
	{ 'r', 'n', 'b', 'k', 'q', 'b', 'n', 'r'},
	{ 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{ 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
	{ 'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R'}
};

// Define all variables
bool current_player_white = false;
int pawnvalue[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
int pawnblackvalue[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

void clearInputQueue()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

// Creating the chess board
void print_board(void) {
	int i, j, k;

	printf(" ");

	// Print colom numbers
	for (i = 0; i < 8; i++)
	printf("    %d", i);
	printf("\n");
	
	// Print all 8 Rows
	for (k = 0; k < 8; k++) {
		printf("  ");

		// Print all 8 rows
		for (i = 0; i < 41; i++) {
			printf("-");
		}

		// Print row numbers
		printf("\n");
		printf("%d", k);

		// Print the 2D Array
		for (j = 0; j < 8; j++) {
			printf(" || %c", board[k][j]);
		}
		printf("||\n");
	}

	printf("  ");

	// Print last row
	for (i = 0; i < 41; i++) {
		printf("-");
	}
	printf("\n");
}

/**
* Checks whether given character is upper or lower case.
* Upper case represents white, lower black.
*/
bool charIsUpperCase(char ch) {
	if (ch >= 'A' && ch <= 'Z') return true;
	else return false;
}

bool pawn(int* target_position, int* start_position, char chosen_figure) {
	// Only can move one square forward
	bool isLegal = false;

	//start position axis
	int start_index_x = start_position[1];
	int start_index_y = start_position[0];
	//target position axis
	int target_index_x = target_position[1];
	int target_index_y = target_position[0];

	if (current_player_white == true) {
		// Counts up the pawnvalue to check if this move is the first pawn move 
		pawnvalue[start_index_x]++;
		// Checks if the pawnvalue is 1. When the value is 1 it's the first pawn move
		if (pawnvalue[start_index_x] == 1) {
			if ((target_index_y - 1 == start_index_y || (target_index_y - 2 == start_index_y))) {
				isLegal = true;
			}
		} else {
			if (target_index_y - 1 == start_index_y) {
				isLegal = true;
			}
		}
	} else {
		// Counts up the pawnblackvalue to check if this move is the first pawn move
		pawnblackvalue[start_index_x]++;
		// Checks if the pawnblackvalue is 1. When the value is 1 it's the first pawn move
		if (pawnblackvalue[start_index_x] == 1) {
			if ((target_index_y + 1 == start_index_y) || (target_index_y + 2 == start_index_y)) {
				isLegal = true;
			}
		} else {
			if (target_index_y + 1 == start_index_y) {
				isLegal = true;
			}
		}
	}

	return isLegal;
}

void rook(void) {

}

void night(void) {

}

void bishop(void) {

}

void king(void) {

}

void queen(void) {

}

void chooseColor(void) {
	int input;

	printf("Welcome to Chess\nWhat color would you like to choose ? " ANSI_COLOR_MAGENTA "White (1) " ANSI_COLOR_CYAN "Black (2)\n" ANSI_COLOR_RESET);

again:

	// Get user input to store the current color
	scanf_s("%d", &input);

	switch (input) {
	case 1:
		printf("You are playing " ANSI_COLOR_MAGENTA "white!\n" ANSI_COLOR_RESET);
		current_player_white = true;
		break;
	case 2:
		printf("You are playing " ANSI_COLOR_CYAN "black!\n" ANSI_COLOR_RESET);
		current_player_white = false;
		break;
	default:
		goto again;
		break;
	}

	clearInputQueue();
}


void chooseCurrentPosition(int* current_position, int current_position_length) {
	// Get the current position which the player has selected
	int i, k = 0;
	char current_position_input[4];

	//int current_position[2];

	printf("\nChoose your current figure (ex. 2,0)\n");

	// Get user input to store the current figure
	fgets(current_position_input, sizeof(current_position_input), stdin);

	//get length of read in string
	int len = strlen(current_position_input);

	//check if user input has digits (ints) and move them to integer array
	while (len > 0 && isspace(current_position_input[len - 1]))
		len--;     // strip trailing newline or other white space
	if (len > 0) {
		for (i = 0; i < len; i++) {
			if (isdigit(current_position_input[i])) {
				//convert char-number into real int by calculating distance between ascii-characters
				//and then move number to array
				current_position[k] = current_position_input[i] - '0';
				//increase index if still allowed
				if (k < current_position_length -1)
					k++;
			}
		}
	}

	clearInputQueue();
	return;
}

/**
* Checks whether given character has epmty space
*/
bool isEmptySpace(char ch) {
	if (ch == ' ') return true;
	else return false;
}

bool isYourColor(char chosen_figure) {
	// Check's if the current position is you color
	printf("Checking whether chosen figure %c is your color...\n", chosen_figure);

	// Check's if the chosen position exist. When not return
	if (isEmptySpace(chosen_figure)) {
		printf("Chosen figure " ANSI_COLOR_RED "doesn't exist\n" ANSI_COLOR_RESET);
		return false;
	}
	// Check if the current player is white
	if (current_player_white == true) {
		if (charIsUpperCase(chosen_figure)) {
			//I am white and the figure is also white
			printf("Chosen figure " ANSI_COLOR_MAGENTA "%c " ANSI_COLOR_GREEN "is " ANSI_COLOR_RESET "your color white.\n", chosen_figure);
			return true;
		}
		else {
			//I am white but chosen figure is black..
			printf("Chosen figure " ANSI_COLOR_MAGENTA "%c " ANSI_COLOR_RED "is NOT " ANSI_COLOR_RESET "your color white.\n" ANSI_COLOR_RESET, chosen_figure);
			return false;
		}
	} else {
		if (!charIsUpperCase(chosen_figure)) {
			//I am black and the figure is also black
			printf("Chosen figure " ANSI_COLOR_CYAN "%c " ANSI_COLOR_GREEN "is " ANSI_COLOR_RESET "your color black.\n", chosen_figure);
			return true;
		} else {
			//I am black but chosen figure is white..
			printf("Chosen figure " ANSI_COLOR_CYAN "%c " ANSI_COLOR_RED "is NOT " ANSI_COLOR_RESET "your color black.\n", chosen_figure);
			return false;
		}
	}

}

void chooseMovePosition(int* position, int position_length, char choosen_figure) {
	// Get the position on which field the player wants to have his figure
	//return position;
	int i, k = 0;
	char position_input[4];

	printf("One which field do you want to have your %c figure? (ex. 2,2)\n", choosen_figure);

	// Get user input to store the position where the player wants to have his figure
	fgets(position_input, sizeof(position_input), stdin);

	//get length of read in string
	int len = strlen(position_input);

	//check if user input has digits (ints) and move them to integer array
	while (len > 0 && isspace(position_input[len - 1]))
		len--;

	if (len > 0) {
		for (i = 0; i < len; i++) {
			if (isdigit(position_input[i])) {
				//convert char-number into real int by calculating distance between ascii-characters
				//and then move number to array
				position[k] = position_input[i] - '0';
				//increase index if still allowed
				if (k < position_length - 1)
					k++;
			}
		}
	}
	printf("\n");
}

bool checkType(int* target_position, int* start_position, char chosen_figure) {
	// Get the type of this figure from getCurrentPosition() (King, Queen, ...)
	// and check whether it is allowed to move to target position
	
	bool isPossible = false;

	// Switch to x and y values from input
	switch (chosen_figure) {
	// Pawn White
	case 'P':
	// Pawn Black
	case 'p':
		isPossible = pawn(target_position, start_position, chosen_figure);
		break;
	// Rook White
	case 'R':
		break;
	// Night White
	case 'N':
		break;
	// Bishop White
	case 'B':
		break;
	// King White
	case 'K':
		break;
	// Queen White
	case 'Q':
		break;
	// Rook Black
	case 'r':
		break;
	// Night Black
	case 'n':
		break;
	// Bishop Black
	case 'b':
		break;
	// King Black
	case 'k':
		break;
	// Queen Black
	case 'q':
		break;
	default:
		break;
	}

	return isPossible;
}

void setPosition(int* target_position, int* start_position, char chosen_figure) {
	// Set the position from the figure the player choose

	//start position axis
	int start_index_x = start_position[1];
	int start_index_y = start_position[0];
	//target position axis
	int target_index_x = target_position[1];
	int target_index_y = target_position[0];

	board[start_index_x][start_index_y] = ' ';
	board[target_index_x][target_index_y] = chosen_figure;
}

void getCurrentColor() {
	// Changes the Color from White to Black and Black to White via flag flip
	current_player_white = !current_player_white;

	if (current_player_white)
		printf("\nIt's " ANSI_COLOR_MAGENTA "whites " ANSI_COLOR_RESET "turn!\n");
	else
		printf("\nIt's " ANSI_COLOR_CYAN "blacks " ANSI_COLOR_RESET "turn!\n");
} 

int main(void) {
	bool end = false; // Boolean for exit
	int current_position[2] = { 0 };
	int current_position_length = sizeof(current_position) / sizeof(current_position[0]);

	int target_position[2] = { 0 };
	int position_length = sizeof(target_position) / sizeof(target_position[0]);

	int index_x = -1;
	int index_y = -1;
	char chosen_figure = ' ';
	bool isPossible = false;

	print_board(); // Print the default chess board from sratch
	
	chooseColor(); // Welcome Screen where you can choose your color
	
	do {
		// Loop to repeat all chess relevant tasks

			//todo pack in do while bis player die richtige Figur ausgewählt hat
			
		do {

			chooseCurrentPosition(current_position, current_position_length);

			index_x = current_position[1];
			index_y = current_position[0];
			chosen_figure = board[index_x][index_y];

		} while (isYourColor(chosen_figure) == false);

		do {

			chooseMovePosition(target_position, position_length, chosen_figure);

			isPossible = checkType(target_position, current_position, chosen_figure);

		} while (isPossible == true);

		setPosition(target_position, current_position, chosen_figure);

		print_board(); // Print the default chess board from sratch

		getCurrentColor();

		clearInputQueue();
		
	// When end or win
	} while (end == false);
	
	
	return 0;
}
