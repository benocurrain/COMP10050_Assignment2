//
// Created by Ben on 25/04/2020.
//

#include "Move.h"
#include "intialzing.h"

void Move(){
   int X_Co, Y_Co, direction ;
   int total_X, total_y ;

    printf("What position would you like to move from\n") ;
    printf("Please enter an X co-ordinate:") ;
    scanf("%d",&X_Co) ;
    printf("Please enter a Y co-ordinate:") ;
    scanf("%d",&Y_Co) ;

    printf("What direction what you like to move?\n1.Up\n2.Down\n3.Left\n4.Right\n") ;
    scanf("%d", &direction) ;



    // Making piece user wants moved point to top of desire stack
    board[X_Co][Y_Co]->Top->piece_below = board[X_Co][Y_Co+1]->Top ;

    // Making position top point to the piece that was just moved
    board[X_Co][Y_Co+1]->Top = board[X_Co][Y_Co]->Top ;

    // Empty positin pointing to null
    board[X_Co][Y_Co]->Top = NULL ;

    return ;
}