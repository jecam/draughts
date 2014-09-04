
/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2014 Assignment #1
 * Start up code provided by Paul Miller and Virginia King
 **********************************************************************/
#include "draughts.h"

int main (int argc, char *argv[])
{
    struct result scoreboard[SCOREBOARDSIZE];
    enum menu_option option;
    UNUSED(argc);
    UNUSED(argv);
    
    
    init_scoreboard(scoreboard);
    do {
        option = get_option();

        switch(option)
        {
        case PLAY_GAME: {
            get_names_and_play(scoreboard);
            continue;
        }
        case DISPLAY_WINNER: {
            display_scoreboard(scoreboard);
            continue;
        }
        case RESET_SCOREBOARD: {
            reset_scoreboard(scoreboard);
            continue;
        }	
        case QUIT:{
            return EXIT_SUCCESS;            
            break;
        }
        case ABOUT:{
            about_draughts();
            continue;
        }
        default:
            printf("Invalid option.\n");
            continue;
        }
    }while(1);
            
  
    return EXIT_SUCCESS;
}

void get_names_and_play(struct result * outcome){
    int i;
    char players[2][MAX_NAME_LEN];

    strcpy(players[0], "");
    
    for (i = 0; i < 2; i++) {
    
        printf("Enter player name: ");

        do
        {
            if(fgets(players[i], MAX_NAME_LEN+1, stdin)){
                if(strchr(players[i], '\n') == NULL){
                    read_rest_of_line();
                    printf("Name is too long, re-enter: ");
                    continue;
                }
            }
        }while(players[i][strlen(players[i])-1] != '\n');
        
        players[i][strlen(players[i])-1]='\0';
        
    }

    play_game( players[0], players[1], outcome );

}


enum menu_option get_option() {

    char choice_char[CHOICE_MAX];
                
    printf("English Draughts - Main Menu\n");
    printf("1) Play Game\n");
    printf("2) Display Winner\n");
    printf("3) Reset scoreboard\n");
    printf("4) Quit\n");
    
    printf("Enter your choice:");
    fgets(choice_char, CHOICE_MAX, stdin);
    
    if(choice_char[strlen(choice_char)-1]!='\n')
        read_rest_of_line();
    
    choice_char[strlen(choice_char)-1]='\0';
    return atoi(choice_char);
      
}


void about_draughts() {
    printf("\n");
    printf("+==============================================================================+\n");
    printf("|                                                                              |\n");
    printf("| This implementation of the APT draughts assignment by Julian Camara (c) 2014 |\n");
    printf("|\ts3369995@student.rmit.edu.au                                           |\n");
    printf("|                                                                              |\n");
    printf("+==============================================================================+\n\n");
    return;
}
