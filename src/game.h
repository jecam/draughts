/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2014 Assignment #1
 * Full Name        : EDIT HERE
 * Student Number   : EDIT HERE
 * Course Code      : EDIT HERE
 * Program Code     : EDIT HERE
 * Start up code provided by Paul Miller and Virginia King
 **********************************************************************/
#ifndef GAME_H
#define GAME_H

#include "gameboard.h"
#include "scoreboard.h"
#include "string.h"
#include <time.h>  /* for use in random function */

#define MOVE_LEN 8

struct location
{
    unsigned x, y;
};

struct move
{
    struct location start;
    struct location end;
};

enum colour
{
    P_RED, P_WHITE
};

struct player
{
    char name[MAX_NAME_LEN+1];
    enum colour col;
};

enum move_type
{
    ATTACK, NORMAL, INVALID
};

enum str_result
{
    FAILURE, SUCCESS, RTM
};

/* Requirement 7 - Controls the flow of play in the game*/
void play_game(char * player_one, char * player_two,
    struct result * outcome);

/* Requirement 4 - Tests to see whether a move is valid or not*/
enum move_type is_valid_move(struct move next_move, struct player *
    current, enum cell_contents board[][BOARDWIDTH]);

/* Requirement  - Tests whether the next player has any valid moves */
BOOLEAN test_for_winner(struct player * next_player,
    enum cell_contents board[][BOARDWIDTH]);

/* Requirement 5 - Handles the logic for the player's turn*/
enum str_result player_turn(struct player * current,
    enum cell_contents board[][BOARDWIDTH]);

 /* int update_board(struct player * current, enum cell_contents board[BOARDWIDTH][BOARDHEIGHT], */
 /*                  struct move new_move , unsigned *previous_x,unsigned *previous_y); */

BOOLEAN get_move(struct player * current, struct move * this_move);
void get_move_2(struct player * player, struct location * next_cell);
BOOLEAN has_attacks(struct location start, enum cell_contents board[][BOARDWIDTH]);
BOOLEAN can_attack(enum cell_contents start, enum cell_contents target);
BOOLEAN can_move(struct location start, enum cell_contents board[][BOARDWIDTH]);


#endif
