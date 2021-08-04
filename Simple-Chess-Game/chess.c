// Include needed packages
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Define Color Codes for better understanding
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
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

// Enum of all figure types
enum Type {
	PAWN, // 0
	ROOK, // 1
	BISHOP, // 2
	NIGHT, // 3
	QUEEN, // 4
	KING, // 5
};


// Define all variables
bool current_player_white = false;

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

void pawn(void) {

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


void getCurrentPosition(int* current_position, int current_position_length) {
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
		printf("Chosen figure %c doesn't exist\n", chosen_figure);
		return false;
	}
	// Check if the current player is white
	if (current_player_white == true) {
		if (charIsUpperCase(chosen_figure)) {
			//I am white and the figure is also white
			printf("Chosen figure %c is your color white.\n", chosen_figure);
			return true;
		}
		else {
			//I am white but chosen figure is black..
			printf("Chosen figure %c is NOT your color white.\n", chosen_figure);
			return false;
		}
	} else {
		if (!charIsUpperCase(chosen_figure)) {
			//I am black and the figure is also black
			printf("Chosen figure %c is your color black.\n", chosen_figure);
			return true;
		} else {
			//I am black but chosen figure is white..
			printf("Chosen figure %c is NOT your color black.\n", chosen_figure);
			return false;
		}
	}

}

void getPosition(int* position, int position_length, char choosen_figure) {
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

}

void getType() {
	// Get the type of this figure from getCurrentPosition() (King, Queen, ...)
}

void isPossible() {
	// Checks if this move is possible
}

void setPosition(char position) {
	// Set the position from the figure the player choose
}

void getCurrentColor() {
	// Changes the Color from White to Black and Black to White via flag flip
	current_player_white = !current_player_white;

	if (current_player_white)
		printf("\nIt's whites turn!\n");
	else
		printf("\nIt's blacks turn!\n");
} 

int main(void) {
	bool end = false; // Boolean for exit
	int current_position[2] = { 0 };
	int current_position_length = sizeof(current_position) / sizeof(current_position[0]);

	int position[2] = { 0 };
	int position_length = sizeof(position) / sizeof(position[0]);

	int index_x = -1;
	int index_y = -1;
	char chosen_figure = ' ';

	print_board(); // Print the default chess board from sratch
	
	chooseColor(); // Welcome Screen where you can choose your color
	
	do {
		// Loop to repeat all chess relevant tasks

		getCurrentPosition(current_position, current_position_length);

		index_x = current_position[1];
		index_y = current_position[0];
		chosen_figure = board[index_x][index_y];

		isYourColor(chosen_figure);

		getPosition(position, position_length, chosen_figure);

		getType();

		isPossible();

		/*setPosition(); */

		getCurrentColor();

		print_board(); // Print the default chess board from sratch
		
	// When end or win
	} while (end == false);
	
	
	return 0;
}
