/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2014 Assignment #1
 * Full Name        : Josephine Pramudia
 * Student Number   : s3491523
 * Course Code      : EDIT HERE
 * Program Code     : EDIT HERE
 * Start up code provided by Paul Miller and Virginia King
 **********************************************************************/

#include "scoreboard.h"




/* Req 2 -Initialises the scoreboard and sets all the strings to be
 * empty*/
void init_scoreboard(struct result * scoreboard)
{
    int i;

    for(i=0; i<SCOREBOARDSIZE;i++){
        strcpy(scoreboard[i].won,"");
        strcpy(scoreboard[i].lost,"");
    }
}

/* Req 9 -Adds a result to the beginning of the scoreboard*/
void add_to_scoreboard(struct result * scoreboard, struct result * latest_game)
{
    UNUSED(scoreboard);
    UNUSED(latest_game);
    return;
}

/* Req 11 - Initialises the scoreboard and sets all the strings to be
 * empty*/
void reset_scoreboard(struct result * scoreboard)
{
    int i;

    for(i=0; i<SCOREBOARDSIZE ;i++){
        strcpy(scoreboard[i].won,"");
        strcpy(scoreboard[i].lost,"");
    }

    printf("Scoreboard is reset.\n\n");

}

/* Req 10 - Displays a formatted printout of the last 10 winners and
 * losers*/
void display_scoreboard(struct result * scoreboard)
{
    int i;

    printf("APT English Draughts Tournament - History of Games Played.\n");
    printf("==========================================================\n");
    printf("| Winner               | Loser                |\n");
    printf("| ---------------------| ---------------------|\n");
	
	
    for(i=0; i<SCOREBOARDSIZE; i++){

        if(strcmp(scoreboard[i].won,"") != 0){
			printf("| %-21s", scoreboard[i].won);
			printf("| %-21s",scoreboard[i].lost);
			}
		else 
			printf("| %-21s", "");;
			
			printf("|");
				
        printf("\n");
    }
	
		printf("\n name 0 %s, %s\n",scoreboard[0].won,scoreboard[0].lost);

        printf("\n\n\n4. size of score board is %lu\n\n\n",sizeof(scoreboard));


}

