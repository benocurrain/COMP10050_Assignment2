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
                printf("|");

                   //printf("%d",board[i][j]->Top->piece_below->player_col) ;
                    struct piece *currPtr;
                    currPtr = malloc(sizeof(struct piece));
                    currPtr = board[i][j]->Top;
                    //printf("%d",currPtr->player_col) ;
                    while (currPtr != NULL) {
                        printf("%d", currPtr->player_col);
                        currPtr = currPtr->piece_below;

                }
            }
        }
        printf("\n");
    }
    printf("\nPlayer 1 has %d stacks dominated",Pl1_stcks) ;
    printf("\nPlayer 2 has %d stacks dominated\n",Pl2_stcks) ;

    return ;
}

