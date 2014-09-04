/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2014 Assignment #1
 * Full Name        : EDIT HERE
 * Student Number   : EDIT HERE
 * Course Code      : EDIT HERE
 * Program Code     : EDIT HERE
 * Start up code provided by Paul Miller and Virginia King
 **********************************************************************/
#include "gameboard.h"

/* Copies the master board to a local copy for each game */
void init_gameboard(enum cell_contents board[BOARDWIDTH][BOARDHEIGHT])
{
	int i;
	int j;

    for(i = 0; i < BOARDWIDTH; i++){
		for(j = 0; j < BOARDHEIGHT; j++){
		    board[i][j] = master_board[i][j];
		}
	}
}

/* Prints the game board to the screen */
void display_gameboard(enum cell_contents board[BOARDWIDTH][BOARDHEIGHT])
{
	int i, j;
    char * lines = "---+---+---+---+---+---+---+---+---|\n";
    printf("   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n");
    printf("%s", lines);

    for(i = 0 ; i < BOARDWIDTH; i++ ){

        printf(" %d | ", i); /*y-axis number*/

        for(j = 0; j < BOARDHEIGHT; j++){
            switch(board[i][j])
            {
            case RED:
                printf("%s%s", RED_DISPLAY, WHITE_RESET);
                break;
            case K_RED:
                printf("%s%s", RED_KING_DISPLAY, WHITE_RESET);
                break;
            case WHITE:
                printf("%s", WHITE_DISPLAY);
                break;
            case K_WHITE:
                printf("%s", WHITE_KING_DISPLAY);
                break;
            case EMPTY:
                printf(" ");
                break;
            }
            printf(" | ");
        }
        printf("\n%s", lines);
    }

    printf("\n");
}
