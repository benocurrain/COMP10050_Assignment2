//
// Created by Ben on 13/04/2020.
//
#include "intialzing.h"



int intialize_board(){
    int i, j, k=1;

    // Initializing the 36 inner positions with pieces
    for(i=1;i<7;i++) {
        for (j = 1; j < 7; j++) {
            board[i][j] = malloc(sizeof(struct board_Pos));
            board[i][j]->no_Pieces = 1;

            struct piece *new_Top = malloc(sizeof(struct piece));

            if (k % 4 == 1 || k % 4 == 2) {
                new_Top->player_col = 1;
            } else {
                new_Top->player_col = 2;
            }
            k++;

            new_Top->piece_below = NULL;
            board[i][j]->Top = new_Top;
        }
        //k+=2;
    }

    for(i=0;i<8;i++){
        board[0][i] = malloc(sizeof(struct board_Pos));
        board[0][i]->no_Pieces = 0;
        board[0][i]->Top = NULL ;
    }

    for(i=0;i<8;i++){
        board[7][i] = malloc(sizeof(struct board_Pos));
        board[7][i]->no_Pieces = 0;
        board[7][i]->Top = NULL ;
    }

    for(i=1;i<7;i++){
        board[i][0] = malloc(sizeof(struct board_Pos));
        board[i][0]->no_Pieces = 0;
        board[i][0]->Top = NULL ;
    }

    for(i=1;i<7;i++){
        board[i][7] = malloc(sizeof(struct board_Pos));
        board[i][7]->no_Pieces = 0;
        board[i][7]->Top = NULL ;
    }


    Pl1_stcks = 18 ;
    Pl2_stcks = 18 ;

    Pl1_piece = 0 ;
    Pl2_piece = 0 ;

    return 0 ;
}
