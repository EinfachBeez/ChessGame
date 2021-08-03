#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 2D Array of a 8x8 chess board
char board[8][8] = {
	{ 'R', 'K', 'B', 'K', 'Q', 'B', 'K', 'R'},
	{ 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{ 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
	{ 'R', 'K', 'B', 'K', 'Q', 'B', 'K', 'R'}
};

// Creating the chess board
void init_board(void) {
	int i, j, k;

	printf(" ");

	// Print colom numbers
	for (i = 0; i < 7; i++)
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

int main(void) {
	int input;
	bool check = false;

	init_board();
	
	/*printf("Welcome to Chess\nWhat color would you like to choose ? White (1) Black (2)\n");

	do {
		scanf_s("%d", &input);

		if (input == 1) {
			printf("You are playing white!");
			check = true;
		}
		else if (input == 2) {
			printf("You are playing black!");
			check = true;
		} else {
			printf("\x1b[2K");
			check = false;
		}
	} while (check == false);
	*/
	return 0;
}

