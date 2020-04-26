//
// Created by Ben on 25/04/2020.
//

#include "Print.h"
#include "intialzing.h"

void print_Board(){
    int i, j ;

    for(i=0;i<8;i++) {
        for (j = 0; j < 8; j++) {
            if(board[i][j]->Top==NULL){
                printf("|0") ;
            }
            else {
                printf("|%d", board[i][j]->Top->player_col);
                if (board[i][j]->Top->piece_below != NULL) {
                   //printf("%d",board[i][j]->Top->piece_below->player_col) ;
                    struct piece *currPtr;
                    currPtr = malloc(sizeof(struct piece));
                    currPtr = board[i][j]->Top->piece_below;
                    printf("%d",currPtr->player_col) ;
                    while (currPtr->piece_below != NULL) {
                        printf("%d", currPtr->player_col);
                    }
                }
            }
        }
        printf("\n");
    }
    return ;
}