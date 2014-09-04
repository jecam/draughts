/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2014 Assignment #1
 * Full Name        : EDIT HERE
 * Student Number   : EDIT HERE
 * Course Code      : EDIT HERE
 * Program Code     : EDIT HERE
 * Start up code provided by Paul Miller and Virginia King
 **********************************************************************/
#ifndef DRAUGHTS_H
#define DRAUGHTS_H
#include "string.h"
#include "game.h"

/* Delete this comment and create any type declarations or function
 * prototypes that you might need here.*/

#define CHOICE_MAX 3

enum menu_option {
    ABOUT, PLAY_GAME, DISPLAY_WINNER, RESET_SCOREBOARD, QUIT
};


void get_names_and_play(struct result * outcome);
enum menu_option get_option();
void about_draughts();

#endif
