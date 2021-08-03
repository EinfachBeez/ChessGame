// Include needed packages
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

// Enum of all colors which there are in chess
enum Color {
	BLACK, // 0
	WHITE, // 1
};

// Define all variables


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
		break;
	case 2:
		printf("You are playing " ANSI_COLOR_CYAN "black!\n" ANSI_COLOR_RESET);
		break;
	default:
		goto again;
		break;
	}
}


void getCurrentPosition(void) {
	// Get the current position which the player has selected
	char current_position[1][1];

	printf("\nChoose you current figure (ex. 2,0)\n");

	// Get user input to store the current figure
	scanf_s("%d", &current_position);



	return current_position;
}

void isYourColor() {
	// Check's if the current position is you color
}

void getPosition(char position) {
	// Get the position on which field the player wants to have his figure
	return position;
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
	// Changes the Color from White to Black and Black to White via Enum
} 

int main(void) {
	bool end = false; // Boolean for exit

	print_board(); // Print the default chess board from sratch
	
	chooseColor(); // Welcome Screen where you can choose your color
	
	do {
		// Loop to repeat all chess relevant tasks
		
		getCurrentPosition();

		isYourColor();

		/*getPosition();*/

		getType();

		isPossible();

		/*setPosition(); */

		getCurrentColor();
		

	// When end or win
	} while (end == false);
	
	
	return 0;
}
