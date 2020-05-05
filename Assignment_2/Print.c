//
// Created by Ben on 25/04/2020.
//

#include "Print.h"
#include "intialzing.h"

void print_Board(){
    int i, j ;
    // Going through each position of the board
    for(i=0;i<8;i++) {
        for (j = 0; j < 8; j++) {
            if(board[i][j]->Top==NULL){
                printf("     |") ;
            }
            else {
                // Formatting
                switch(board[i][j]->no_Pieces){
                    case 4: printf(" ") ;break;
                    case 3: printf("  ") ;break;
                    case 2: printf("   ") ;break;
                    case 1: printf("    ") ;break;
                }

                // Will be used to filter through the current position to print the colour
                struct piece *currPtr;
                currPtr = malloc(sizeof(struct piece));
                currPtr = board[i][j]->Top;

                while (currPtr != NULL) {
                    printf("%d", currPtr->player_col);
                    currPtr = currPtr->piece_below;
                }
                printf("|");
            }
        }
        printf("\n");
    }
    printf("\nPlayer 1 has %d stacks dominated and %d Pieces in hand",Pl1_stcks, Pl1_piece) ;
    printf("\nPlayer 2 has %d stacks dominated and %d Pieces in hand\n",Pl2_stcks,Pl2_piece) ;
}

