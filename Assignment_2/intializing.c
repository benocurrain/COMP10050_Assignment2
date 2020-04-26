//
// Created by Ben on 13/04/2020.
//
#include "intialzing.h"



int intialize_board(){
    int i, j, k=1;



    for(i=0;i<8;i++) {
        for (j = 0; j < 8; j++) {
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
        k+=2;
    }

    struct Player Player_1={18,18,0} ;
    struct Player Player_2={18,18,0} ;

    return 0 ;
}
