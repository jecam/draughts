/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2014 Assignment #1
 * Start up code provided by Paul Miller and Virginia King
 **********************************************************************/
#include "game.h"


/* Requirement 7 - Controls the flow of play in the game*/
void play_game(char * player_one, char * player_two,
               struct result * outcome)

{
    struct player player1, player2;
    struct player *current, *other, *temp;

    enum cell_contents gameboard[BOARDWIDTH][BOARDHEIGHT];
    init_gameboard(gameboard);

    UNUSED(outcome);
    
    strcpy(player1.name, player_one);
    strcpy(player2.name, player_two);

    printf("\n");
    srand(time(NULL)); /* seed random number generator */
    if(rand() % 2 == 0) {
        player1.col = P_WHITE;
        player2.col = P_RED;
        current = &player1;
        other = &player2;
    } else {
        player1.col = P_RED;
        player2.col = P_WHITE;
        current = &player2;
        other = &player1;
    }
    
    printf("%s will be playing first as white.\n\n", current->name);

    do
    {
        enum str_result turn;
        display_gameboard(gameboard);

        turn = player_turn(current, gameboard);

        if(turn == RTM)
            break;
        

        /*  if(turn == SUCCESS) {
            printf("Nice jump! You have more potential jumps, continue? [Y/n]");
            } else {*/
        temp = &(*current);
        current = &(*other);
        other = &(*temp);
        /* } */
        
    } while(!test_for_winner(current, gameboard));

    printf("Congratulations! %s has won this game!\n", other->name);

    /* If player_turn was a success, could represent the possibility of a continuing jump?
       else if player_turn was a failure, idk
       else if player_turn returned RTM, return to menu.
    */


    return;
}


/* Requirement 5 - Handles the logic for the player's turn*/
enum str_result player_turn(struct player * current,
                            enum cell_contents board[BOARDWIDTH][BOARDHEIGHT])
{
    enum str_result result;
    struct move next_move;
    BOOLEAN playing = FALSE;
    enum move_type mtype;

    do {
        playing = get_move(current, &next_move);
        
        if(!playing)
            return RTM;
        
        mtype = is_valid_move(next_move, current, board);

        /* Not only does the following method for moving pieces save the hassle of
           checking the current player's colour, it's also a nice analogy for picking
           up a piece and putting it down where it needs to go.
        */       
        if(mtype == NORMAL) { 
            enum cell_contents moving_piece = board[next_move.start.x][next_move.start.y];
            board[next_move.start.x][next_move.start.y] = EMPTY;
            if(moving_piece == WHITE && next_move.end.x == 0) 
                board[next_move.end.x][next_move.end.y] = K_WHITE;
            else if(moving_piece == RED && next_move.end.x == 7)
                board[next_move.end.x][next_move.end.y] = K_RED;
            else
                board[next_move.end.x][next_move.end.y] = moving_piece;
           
        } else if(mtype == ATTACK) {
            int target_x, target_y, start_x, start_y, end_x, end_y;
            enum cell_contents attacker;
            struct location new_start;

            start_x = (int)next_move.start.x;
            start_y = (int)next_move.start.y;
            end_x = (int)next_move.end.x;
            end_y = (int)next_move.end.y;

            target_x = (start_x + end_x) / 2; /* This is super reliable and it took me an  */
            target_y = (start_y + end_y) / 2; /* embarrassingly long time to figure it out */

            attacker = board[next_move.start.x][next_move.start.y];
        
            board[next_move.start.x][next_move.start.y] = EMPTY;
            board[target_x][target_y] = EMPTY;
            if(attacker == WHITE && next_move.end.x == 0) 
                board[next_move.end.x][next_move.end.y] = K_WHITE;
            else if(attacker == RED && next_move.end.x == 7)
                board[next_move.end.x][next_move.end.y] = K_RED;
            else
                board[next_move.end.x][next_move.end.y] = attacker;

            /* TODO: check if there are more possible attacks and execute in a while loop if so */
            new_start.x = next_move.end.x;
            new_start.y = next_move.end.y;

            if(has_attacks(new_start, board)) {
                printf("You have more attacks available. Keep attacking? [Y/n] : ");
                printf("\n");
            }

        
        } else {
            printf("Invalid move. Try again.\n ");
            result = FAILURE;
        }
    }while(mtype == INVALID);      
              
    return result;
}

/* Requirement 4-Tests to see whether a move is valid or not */
enum move_type is_valid_move(struct move next_move,
                             struct player * current, enum cell_contents board[][BOARDWIDTH])
{
    enum move_type validity;
    int dist_x, dist_y, start_x, start_y, end_x, end_y;
    enum cell_contents start_cell;
    
    validity = INVALID;
    /* the math goes out of whack if we don't cast em back */
    start_x = (int)next_move.start.x;
    start_y = (int)next_move.start.y;
    end_x = (int)next_move.end.x;
    end_y = (int)next_move.end.y;
    
    dist_x = end_x - start_x;
    dist_y = end_y - start_y;

    /* try to get as many invalid cases out of the way as possible to begin 
       with since there are many universally bad rules to throw out        */
    
    /* check we're working within the bounds of the board */
    if(next_move.start.x > BOARDWIDTH || next_move.start.y > BOARDHEIGHT ||
       next_move.end.x > BOARDWIDTH || next_move.end.y > BOARDHEIGHT)
        return validity;
    
    if(abs(dist_x) != abs(dist_y)) /* move was not diagonal */
        return validity;

    if(dist_x > 2 || dist_x == 0) /* travelling the right distance */
        return validity;

    start_cell = board[start_x][start_y];

    if(start_cell == EMPTY)
        return validity;

    if(board[next_move.end.x][next_move.end.y] != EMPTY)
        return validity;

    /* no moving the other players piece! */
    if(current->col == P_WHITE && (start_cell == RED ||
                                   start_cell == K_RED))
        return validity;

    if(current->col == P_RED && (start_cell == WHITE ||
                                 start_cell == K_WHITE))
        return validity;

    /* pawns move in the correct direction */
    if(start_cell == WHITE && dist_x > 0)
        return validity;

    if(start_cell == RED && dist_x < 0)
        return validity;

    if(abs(dist_x) == 1) /* turns out this is the only normal condition left to check */
        validity = NORMAL;

    if(abs(dist_x) == 2) {
        int target_x, target_y;
        enum cell_contents target_cell;
        
        target_x = (start_x + end_x) / 2;
        target_y = (start_y + end_y) / 2;

        target_cell = board[target_x][target_y];

        if(can_attack(start_cell, target_cell))
            validity = ATTACK;

    }    
    return validity;
    /* look at that! got away with it with only one level of nested if statements. lovely */
    
}

BOOLEAN can_attack(enum cell_contents attacker, enum cell_contents target) {
    BOOLEAN can_attack = FALSE;
        
        if((attacker == WHITE || attacker == K_WHITE) &&
           (target == RED || target == K_RED))
            can_attack = TRUE;

        if((attacker == RED || attacker == K_RED) &&
           (target == WHITE || target == K_WHITE))
            can_attack = TRUE;
        
        return can_attack;
}


/* Requirement  - Tests whether the next player has any valid moves*/
BOOLEAN test_for_winner(struct player * next_player,
                        enum cell_contents board[][BOARDWIDTH])
{
    BOOLEAN has_won;
    int i, j;
 
    has_won = TRUE;

    for(i = 0; i < BOARDHEIGHT; i++) {
        for(j = 0; j < BOARDWIDTH; j++) {
            enum cell_contents this_cell = board[i][j];
            struct location start;
            start.x = i;
            start.y = j;
            
            if(this_cell != EMPTY) {
                if((next_player->col == P_RED && (this_cell == RED ||
                                                  this_cell == K_RED)) ||
                   (next_player->col == P_WHITE && (this_cell == WHITE ||
                                                    this_cell == K_WHITE)))
                    has_won = !(has_attacks(start, board) || can_move(start, board));
            }

            if(!has_won)
                return has_won;
        }
    }
    
    return has_won;
}


BOOLEAN get_move(struct player * player, struct move * this_move) {
    /* TODO: validate move input. This only works as long as input is in perfect format */
    BOOLEAN playing = FALSE;
    char colour[5];
    char input[MOVE_LEN];
    char *token;
    
    if(player->col == P_WHITE)
        strcpy(colour, "white");
    else
        strcpy(colour, "red");
    printf("It is %s's turn, playing as %s.\n Input move coordinates: ", player->name, colour);

    if(!fgets(input, MOVE_LEN, stdin))
        return playing;

    if(input[0] == '\0')
        return playing;
        
    
    token = strtok(input, ",");
    this_move->start.y = atol(token);
    token = strtok(NULL, "-");
    this_move->start.x = atol(token);
    token = strtok(NULL, ",");
    this_move->end.y = atol(token);
    token = strtok(NULL, "\n");
    this_move->end.x = atol(token);

    read_rest_of_line();
    playing = TRUE;
    
    return playing;
}

/* For additional jumps in situations that warrant it */
void get_move_2(struct player * player, struct location * next_cell) {
    UNUSED(player);
    UNUSED(next_cell);
    return;
}

/* finds out if the piece is able to attack at all */
BOOLEAN has_attacks(struct location start, enum cell_contents board[][BOARDWIDTH]){
    BOOLEAN has_attacks = FALSE;
    int i, j, start_x, start_y;
    enum cell_contents start_piece;
    
    start_piece = board[start.x][start.y];
    start_x = (int)start.x;
    start_y = (int)start.y;

    for(i = -2; i < 5; i += 4) {
        for(j = -2; j < 5; j += 4) {
            int end_x, end_y, target_x, target_y;
            enum cell_contents target;
            end_x = start_x + i;
            end_y = start_y + j;

            if(end_x < 0 || end_x > BOARDHEIGHT)
                continue;
            if(end_y < 0 || end_y > BOARDHEIGHT)
                continue;

            target_x = (start_x + end_x) / 2;
            target_y = (start_y + end_y) / 2;
            target = board[target_x][target_y];

            if(board[end_x][end_y] != EMPTY)
                continue;

            if(start_piece == WHITE && (end_x - start_x) > 0)
                continue;
            
            if(start_piece == RED && (end_x - start_x) < 0)
                continue;

            if(can_attack(start_piece, target))
                has_attacks = TRUE;
            
        }
    } 
  
    return has_attacks;
}

BOOLEAN can_move(struct location start, enum cell_contents board[][BOARDWIDTH]){
    int i, j, start_x, start_y;
    start_x = (int)start.x;
    start_y = (int)start.y;
    
    for (i = -1; i < 2; i += 2) {
        for(j = -1; j < 2; j += 2) {
            int end_x, end_y;
            end_x = start_x + i;
            end_y = start_y + j;

            if((end_x >= BOARDWIDTH || end_y >= BOARDWIDTH) ||
               (end_x < 0 || end_y < 0))
                continue;

            if(board[end_x][end_y] == EMPTY)
                return TRUE;
        }
    }
    
    return FALSE;
}

