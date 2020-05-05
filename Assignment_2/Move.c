//
// Created by Ben on 25/04/2020.
//

#include "Move.h"
#include "intialzing.h"

void Move(int Player){
    int player_choice = 1 ; // Will be used to ask if the player would like to place a piece from hand or move a stack
    int dom_plyer_bfr, dom_other_bfr, dom_player_aft, dom_other_aft ; // Used to calculate the change in dominated stacks after a move
    int X_Co, Y_Co; // The co-ordinates from which the user will move pieces to
    int right_player = 0 ; // Is used to check if the stack chosen by player is dominated by them
    int no_to_move=1,no_spaces = 1 ; // The number of pieces the user will move from selected stack, and the number os spaces they will move it
    int ok_pos = 0 ; // Will be used as loop condition when getting the direction
    int direction ; // Used for selecting the direction the user will move
    int total_X=0, total_y=0; // X will be distance left/right, y will be up/down
    int new_X, new_Y ; // Will be co-ordinates of the stack the user is moving to
    int i ;

    printf("\nIt is player %d's turn.\n ",Player) ;

    // This is checking if a player has both dominated stacks and pieces in hand, in which case they need to decide what to do
    if(Player==1 && Pl1_piece == 0){
        player_choice = 1 ;
    } else if (Player == 1 && Pl1_stcks==0){
        player_choice= 2 ;
    } else if(Player==2 && Pl2_piece == 0){
        player_choice = 1 ;
    } else if (Player == 2 && Pl2_stcks==0){
        player_choice= 2 ;
    } else{
        printf("Would you like to\n1.Move a stack on the board\n2.Place a piece from your hand on the board?\n") ;
        scanf("%d",&player_choice) ;
    }

    if(player_choice==1) { // Move stack
        // Getting the stack user would like to move
        do {
            get_Co_ordinates(&Y_Co, &X_Co);

            // Checks if there is a pieces on the selected pos, and then if the current player dominates that stack
            if (board[Y_Co][X_Co]->no_Pieces == 0) {
                printf("\nThere are no pieces in this position please Choose another position.\n");
            } else if (board[Y_Co][X_Co]->Top->player_col != Player) {
                printf("\nYou do not dominate this stack, please choose another.\n");
            } else {
                right_player = 1; // To exit loop if an appropriate pos has been selected
            }
        } while (board[Y_Co][X_Co]->no_Pieces == 0 || right_player == 0);

        // Checking how many pieces the user would like to move from stack
        if(board[Y_Co][X_Co]->no_Pieces>1) { // Only asks if there is more than 1 piece in the pos
            do {
                printf("\nHow many pieces would you like to move from stack?\nThere are %d available to move:",
                       board[Y_Co][X_Co]->no_Pieces);
                scanf("%d", &no_to_move);
            } while ((no_to_move < 1) || (no_to_move > board[Y_Co][X_Co]->no_Pieces));
        }

        // Asking how many spaces the user would like to move their stack
        if(no_to_move>1) { // Only asks if the player has chosen to move more than 1 piece
            do {
                printf("\nHow many spaces would you like to move the stack");
                scanf("%d", &no_spaces);
            } while ((no_spaces < 1) || (no_spaces > no_to_move));
        }


        // Getting the direction the user wants to move
        do {
            total_X = 0 ;
            total_y = 0 ;

            for (i = 0; i < no_spaces; i++) {
                printf("\nWhat direction what you like to move?\n1.Up\n2.Down\n3.Left\n4.Right\n");
                scanf("%d", &direction);

                // This calculates the difference along the x and y that the user wants to move the pieces
                switch (direction) {
                    case 1:
                        total_y -= 1;
                        if (Y_Co + total_y < 0) {
                            printf("Cannot Move this way, Please select another way\n");
                            i--;
                            total_y += 1;
                        }
                        break;
                    case 2:
                        total_y += 1;
                        if (Y_Co + total_y > 7) {
                            printf("Cannot Move this way, Please select another way\n");
                            i--;
                            total_y -= 1;
                        }
                        break;
                    case 3:
                        total_X -= 1;
                        if (X_Co + total_X < 0) {
                            printf("Cannot Move this way, Please select another way\n");
                            i--;
                            total_X += 1;
                        }
                        break;
                    case 4:
                        total_X += 1;
                        if (X_Co + total_X > 7) {
                            printf("Cannot Move this way, Please select another way\n");
                            i--;
                            total_X -= 1;
                        }
                        break;
                }
            }

            // Calculating new co-ordinates
            new_X = X_Co + total_X;
            new_Y = Y_Co + total_y;

            // Checking If the user has chosen to move to one of the corner squares they are not supposed to, if they do it starts the loop again
            if((new_Y==0)||(new_Y==7)) {
                if ((new_X == 0) || (new_X == 1) || (new_X == 6) || (new_X == 7)) {
                    printf("Cannot Move this square. Please select drections again\n");
                    continue;
                }
            }
            else if((new_Y==1)||(new_Y==6)) {
                if ((new_X == 0) || (new_X == 0)) {
                    printf("Cannot Move this square\n");
                    continue;
                }
            }

            // If the user has selected an acceptable position it sets ok_pos to 1 to stop the loop
            ok_pos = 1 ;

        }while(ok_pos==0);


        // Updating dominated stacks before move numbers
        if(board[new_Y][new_X]->Top == NULL){
            dom_plyer_bfr = 1 ;
            dom_other_bfr = 0 ;
        } else if (board[new_Y][new_X]->Top->player_col == Player){
            dom_plyer_bfr = 2;
            dom_other_bfr = 0;
        } else{
            dom_plyer_bfr = 1 ;
            dom_other_bfr = 1;
        }


        // Will be used to store the piece that the position being moved from will point to
        struct piece *tmp;
        tmp = malloc(sizeof(struct piece));
        tmp = board[Y_Co][X_Co]->Top;

        for (i = 0; i < no_to_move; i++)
            tmp = tmp->piece_below;

        // Moving the stack
        switch (no_to_move) {
            case 5:
                // Moving the stack ontop of the desired stack
                board[Y_Co][X_Co]->Top->piece_below->piece_below->piece_below->piece_below->piece_below = board[new_Y][new_X]->Top;
                break;

            case 4:
                // Moving the stack ontop of the desired stack
                board[Y_Co][X_Co]->Top->piece_below->piece_below->piece_below->piece_below = board[new_Y][new_X]->Top;
                break;

            case 3:
                // Moving the stack ontop of the desired stack
                board[Y_Co][X_Co]->Top->piece_below->piece_below->piece_below = board[new_Y][new_X]->Top;
                break;
            case 2:
                // Moving the stack ontop of the desired stack
                board[Y_Co][X_Co]->Top->piece_below->piece_below = board[new_Y][new_X]->Top;
                break;
            case 1:
                // Moving the stack ontop of the desired stack
                board[Y_Co][X_Co]->Top->piece_below = board[new_Y][new_X]->Top;
                break;

            default:
                printf("Error in move.c");
                break;
        }

        // Moving stack
        board[new_Y][new_X]->Top = board[Y_Co][X_Co]->Top;
        board[Y_Co][X_Co]->Top = tmp;

        // Changing the number of pieces in the stacks
        board[Y_Co][X_Co]->no_Pieces -= no_to_move;
        board[new_Y][new_X]->no_Pieces += no_to_move;

        // Updating dominated stacks numbers
        if(board[Y_Co][X_Co]->Top== NULL){
            dom_player_aft = 1 ;
            dom_other_aft = 0 ;
        } else if (board[Y_Co][X_Co]->Top->player_col==Player){
            dom_player_aft = 2;
            dom_other_aft = 0;
        } else{
            dom_player_aft = 1 ;
            dom_other_aft = 1;
        }

        // Changing the global variables of stacks dominated after the move has been made
        if(dom_player_aft-dom_plyer_bfr==1){
            add_Dom_stck_player(Player) ;
        }
        if(dom_player_aft-dom_plyer_bfr==-1){
            subtract_Dom_stck_player(Player) ;
        }
        if(dom_other_aft-dom_other_bfr==1){
            add_Dom_stck_other(Player) ;
        }
        if(dom_other_aft-dom_other_bfr==-1){
            subtract_Dom_stck_other(Player) ;
        }

    }
    else if (player_choice == 2){ // New Piece
        get_Co_ordinates(&new_Y, &new_X);

        // Changing the stacks dominated depending on where the new piece is being added
        if(board[new_Y][new_X]->Top==NULL){
            add_Dom_stck_player(Player) ;
        } else if (board[new_Y][new_X]->Top->player_col != Player){
            add_Dom_stck_player(Player) ;
            subtract_Dom_stck_other(Player);
        }

        // declaring the new piece being added
        struct piece *new_piece ;
        new_piece = malloc(sizeof(struct piece)) ;

        // Putting the information into the new piece
        new_piece->player_col = Player ;
        new_piece->piece_below = board[new_Y][new_X]->Top ;

        // Updating the positions info
        board[new_Y][new_X]->Top = new_piece ;
        board[new_Y][new_X]->no_Pieces++;

        if(Player==1) {
            Pl1_piece--;
        }
        else {
            Pl2_piece--;
        }
    }

   // Pop extra Pieces
   if(board[new_Y][new_X]->no_Pieces>5){
       int no_to_pop = board[new_Y][new_X]->no_Pieces-5;

       // Creating a pointer that will be used to filter through extra pieces to see if they belong to the current player
       struct piece *pop;
       pop = malloc(sizeof(struct piece)) ;
       pop = board[new_Y][new_X]->Top;

       // filtering down to the 6th piece in the stack
       for(i=0;i<5;i++)
           pop = pop->piece_below;

       for(i=0;i<no_to_pop;i++){
           // If the current extra piece belongs to the current player it adds one to their pieces in hand
           if(pop->player_col == Player) {
               if (Player == 1)
                   Pl1_piece++;
               else Pl2_piece++;
           }
           pop = pop->piece_below;
       }

       board[new_Y][new_X]->Top->piece_below->piece_below->piece_below->piece_below->piece_below = NULL ;
       board[new_Y][new_X]->no_Pieces = 5 ;
   }


       return ;
}

// Funtion for getting co-ordinates
void get_Co_ordinates(int *row, int *column) {
    int rw,col ;
    int ok_Pos = 0 ;  // Will be used to exit loop

    do {
        printf("What position would you like to move from\n");

        // Getting the row
        do {
            printf("\nPlease select a Row:");
            scanf("%d", &rw);

            if (rw < 0 || rw > 7)
                printf("Invalid selection.\n");

        } while (rw < 0 || rw > 7);

        // Getting a column
        do {
            printf("\nPlease select a column:");
            scanf("%d", &col);

            if (col < 0 || col > 7)
                printf("Invalid selection.\n");

        } while (col < 0 || col > 7);

        // Checking if the selected position is one of the corner squares that are not able to be used
        if((rw==0)||(rw==7))
            if( (col==0) || (col==1) ||(col==6) || (col==7) ){
                printf("Cannot use this square\n") ;
                continue ;
            }

        if((rw==1)||(rw==6))
            if((col == 0) || (col == 7)){
                printf("Cannot use this square\n") ;
                continue ;
            }

        ok_Pos = 1 ;

    }while(ok_Pos == 0);

    *row = rw ;
    *column = col ;
}

// The following Functions are used to update the dominated stacks variables
void add_Dom_stck_player(int plyer){
    if(plyer==1){
        Pl1_stcks++ ;
    }
    if(plyer==2){
        Pl2_stcks++ ;
    }
}

void add_Dom_stck_other(int plyer){
    if(plyer==1){
        Pl2_stcks++ ;
    }
    if(plyer==2){
        Pl1_stcks++ ;
    }
}

void subtract_Dom_stck_player(int plyer){
    if(plyer==1){
        Pl1_stcks-- ;
    }
    if(plyer==2){
        Pl2_stcks-- ;
    }
}

void subtract_Dom_stck_other(int plyer){
    if(plyer==2){
        Pl1_stcks-- ;
    }
    if(plyer==1){
        Pl2_stcks-- ;
    }
}