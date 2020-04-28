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
    int direction ; // Used for selecting the direction the user will move
    int total_X=0, total_y=0; // X will be distance left/right, y will be up/down
    int new_X, new_Y ; // Will be co-ordinates of the stack the user is moving to
    int i ;

    printf("\nIt is player %d's turn.\n ",Player) ;

    if(Player==1 &&  Pl1_piece>0){
        printf("Would you like to\n1.Move a stack on the board\n2.Place a piece from your hand on the board?") ;
        scanf("%d",&player_choice) ;
    }
    if(Player==2 &&  Pl2_piece>0){
        printf("Would you like to\n1.Move a stack on the board\n2.Place a piece from your hand on the board?\n") ;
        scanf("%d",&player_choice) ;
    }

    if(player_choice==1) { // Move stack
        // Getting the stack user would like to move
        do {
            get_Co_ordinates(Player,&Y_Co, &X_Co);

            if (board[Y_Co][X_Co]->no_Pieces == 0) {
                printf("\nThere are no pieces in this position please Choose another position.\n");
            } else if (board[Y_Co][X_Co]->Top->player_col != Player) {
                printf("\nYou do not dominate this stack, please choose another.\n");
            } else {
                right_player = 1;
            }
        } while (board[Y_Co][X_Co]->no_Pieces == 0 || right_player == 0);

        // Checking how many pieces the user would like to move from stack
        if(board[Y_Co][X_Co]->no_Pieces>1) {
            do {
                printf("\nHow many pieces would you like to move from stack?\nThere are %d available to move:",
                       board[Y_Co][X_Co]->no_Pieces);
                scanf("%d", &no_to_move);
            } while ((no_to_move < 1) || (no_to_move > board[Y_Co][X_Co]->no_Pieces));
        }

        // Asking how many spaces the user would like to move their stack
        if(no_to_move>1) {
            do {
                printf("\nHow many spaces would you like to move the stack");
                scanf("%d", &no_spaces);
            } while ((no_spaces < 1) || (no_spaces > no_to_move));
        }


        // Getting the direction the user wants to move
        for (i = 0; i < no_spaces; i++) {
            printf("\nWhat direction what you like to move?\n1.Up\n2.Down\n3.Left\n4.Right\n");
            scanf("%d", &direction);

            // This calculates the difference along the x and y that the user wants to move the pieces
            switch (direction) {
                case 1:
                    total_y -= 1;
                    break;
                case 2:
                    total_y += 1;
                    break;
                case 3:
                    total_X -= 1;
                    break;
                case 4:
                    total_X += 1;
                    break;
            }
        }

        // Calculating new co-ordinates
        new_X = X_Co + total_X;
        new_Y = Y_Co + total_y;

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

        switch (no_to_move) {
            case 5:
                // Finding the Piece that the bottom of the stack was pointing to
                for (i = 0; i < no_to_move; i++)
                    tmp = tmp->piece_below;

                // Moving the stack ontop of the desired stack
                board[Y_Co][X_Co]->Top->piece_below->piece_below->piece_below->piece_below->piece_below = board[new_Y][new_X]->Top;
                break;

            case 4:
                // Finding the Piece that the bottom of the stack was pointing to
                for (i = 0; i < no_to_move; i++)
                    tmp = tmp->piece_below;

                // Moving the stack ontop of the desired stack
                board[Y_Co][X_Co]->Top->piece_below->piece_below->piece_below->piece_below = board[new_Y][new_X]->Top;
                break;

            case 3:
                // Finding the Piece that the bottom of the stack was pointing to
                for (i = 0; i < no_to_move; i++)
                    tmp = tmp->piece_below;

                // Moving the stack ontop of the desired stack
                board[Y_Co][X_Co]->Top->piece_below->piece_below->piece_below = board[new_Y][new_X]->Top;
                break;
            case 2:
                // Finding the Piece that the bottom of the stack was pointing to
                for (i = 0; i < no_to_move; i++)
                    tmp = tmp->piece_below;

                // Moving the stack ontop of the desired stack
                board[Y_Co][X_Co]->Top->piece_below->piece_below = board[new_Y][new_X]->Top;
                break;
            case 1:
                // Finding the Piece that the bottom of the stack was pointing to
                tmp = tmp->piece_below;

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
        get_Co_ordinates(Player,&new_Y, &new_X);

        if(board[new_Y][new_X]->Top==NULL){
            add_Dom_stck_player(Player) ;
        } else if (board[new_Y][new_X]->Top->player_col != Player){
            add_Dom_stck_player(Player) ;
            subtract_Dom_stck_other(Player);
        }else{ printf("Error"); }

        struct piece *new_piece ;
        new_piece = malloc(sizeof(struct piece)) ;

        new_piece->player_col = Player ;
        new_piece->piece_below = board[new_Y][new_X]->Top ;
        board[new_Y][new_X]->Top = new_piece ;
        board[new_Y][new_X]->no_Pieces++;

        if(Player==1) {
            Pl1_piece--;
        }
        else {
            Pl2_piece--;
        }
    }
    else{
        printf("Error") ;
    }


   printf("\nThere are %d pieces in column %d,row %d\n",board[new_Y][new_X]->no_Pieces,new_Y,new_X) ;

   // Pop extras function
   if(board[new_Y][new_X]->no_Pieces>5){
       int no_to_pop = board[new_Y][new_X]->no_Pieces-5;
       struct piece *pop;
       pop = malloc(sizeof(struct piece)) ;
       pop = board[new_Y][new_X]->Top;

       for(i=0;i<5;i++)
           pop = pop->piece_below;

       for(i=0;i<no_to_pop;i++){
           printf("\nspare piece colour = %d\n", pop->player_col);
           if(pop->player_col == Player)
               if(Player==1)
                   Pl1_piece++;
               else Pl2_piece++;
           pop = pop->piece_below;
       }

        //printf("\nPlayer one has %d pieces in hand",Player_1.no_Pieces_hand) ;
       // printf("\nPlayer two has %d pieces in hand\n",Player_2.no_Pieces_hand) ;
       board[new_Y][new_X]->Top->piece_below->piece_below->piece_below->piece_below->piece_below = NULL ;
       board[new_Y][new_X]->no_Pieces = 5 ;
   }


       return ;
}

void get_Co_ordinates(int player, int *row, int *column ){
    int transfer_row,transfer_column ;

    printf("What position would you like to move from\n");

    do {
        printf("\nPlease select a Row:");
        scanf("%d", &transfer_row);

        if(transfer_row<1 || transfer_row>6)
            printf("Invalid selection.\n");

    }while(transfer_row<1 || transfer_row>6);

    do {
        printf("\nPlease select a column:");
        scanf("%d", &transfer_column);

        if(transfer_column<1 || transfer_column>6)
            printf("Invalid selection.\n");

    }while(transfer_column<1 || transfer_column>6);

    *row = transfer_row ;
    *column = transfer_column ;
}

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