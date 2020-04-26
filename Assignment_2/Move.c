//
// Created by Ben on 25/04/2020.
//

#include "Move.h"
#include "intialzing.h"

void Move(){
   int X_Co, Y_Co, direction,i ;
   int total_X=0, total_y=0;
   int no_to_move=0 ;
   int Player = 1 ;

   // Getting the stack user would like to move
   do{
       printf("What position would you like to move from\n");
       printf("Please enter an X co-ordinate:");
       scanf("%d", &X_Co);
       printf("Please enter a Y co-ordinate:");
       scanf("%d", &Y_Co);

       if (board[Y_Co][X_Co]->no_Pieces == 0) {
           printf("There are no pieces in this position please Choose another position.");
       }
   }while(board[Y_Co][X_Co]->no_Pieces == 0) ;

   // Checking how many pieces the user would like to move from stack
   do{
       printf("How many pieces would you like to move from stack?\nThere are %d available to move:",board[Y_Co][X_Co]->no_Pieces);
       scanf("%d", &no_to_move);
   }while( (no_to_move<1) || (no_to_move>board[Y_Co][X_Co]->no_Pieces) );

   // Getting the direction the user wants to move
   for(i=0;i<no_to_move;i++) {
       printf("What direction what you like to move?\n1.Up\n2.Down\n3.Left\n4.Right\n");
       scanf("%d", &direction);

       // This calculates the difference along the x and y that the user wants to move the pieces
       switch (direction) {
           case 1: total_y -= 1; break;
           case 2: total_y += 1; break;
           case 3: total_X -= 1; break;
           case 4: total_X += 1; break;
       }
   }

   if(board[Y_Co][X_Co]->no_Pieces==1) {
       // Making piece user wants moved point to top of desire stack
       board[Y_Co][X_Co]->Top->piece_below = board[Y_Co + total_y][X_Co + total_X]->Top;

       // Updating the amount of pieces on positions
       board[Y_Co][X_Co]->no_Pieces-=no_to_move ;
       board[Y_Co+total_y][X_Co+total_X]->no_Pieces+=no_to_move ;

       // Making position top point to the piece that was just moved
       board[Y_Co + total_y][X_Co + total_X]->Top = board[Y_Co][X_Co]->Top;

       // Empty position pointing to null
       board[Y_Co][X_Co]->Top = NULL;
   }
   else{
       // Will be used to find and store the bottom of stack being moved
       struct piece *currPtr;
       currPtr = malloc(sizeof(struct piece));
       currPtr = board[][]->Top->piece_below;
       // Will be used and store the top the of stack being moved
       struct piece *moving_top;
       moving_top = malloc(sizeof(struct piece));
       moving_top = board[][]->Top->piece_below;

       switch(no_to_move){
           case 5:

       }

   }
    return ;
}