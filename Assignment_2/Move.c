//
// Created by Ben on 25/04/2020.
//

#include "Move.h"
#include "intialzing.h"

void Move(){
   int X_Co, Y_Co; // The co-ordinates from which the user will move pieces to
   int no_to_move=0,no_spaces = 0 ; // The number of pieces the user will move from selected stack, and the number os spaces they will move it
   int direction ; // Used for selecting the direction the user will move
   int total_X=0, total_y=0; // X will be distance left/right, y will be up/down
   int new_X, new_Y ; // Will be co-ordinates of the stack the user is moving to
   int Player = 1,i ;

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

   // Asking how many spaces the user woould like to move their stack
    do{
        printf("How many spaces would you like to move the stack");
        scanf("%d", &no_spaces);
    }while( (no_spaces<1) || (no_spaces>no_to_move) );

   // Getting the direction the user wants to move
   for(i=0;i<no_spaces;i++) {
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

   // Calculating new co-ordinates
   new_X = X_Co + total_X ;
   new_Y = Y_Co + total_y ;

   if(no_to_move==11) {
       // Making piece user wants moved point to top of desire stack
       board[Y_Co][X_Co]->Top->piece_below = board[new_Y][new_X]->Top;

       // Updating the amount of pieces on positions
       board[Y_Co][X_Co]->no_Pieces-=no_to_move ;
       board[new_Y][new_X]->no_Pieces+=no_to_move ;

       // Making position top point to the piece that was just moved
       board[new_Y][new_X]->Top = board[Y_Co][X_Co]->Top;

       // Empty position pointing to null
       board[Y_Co][X_Co]->Top = NULL;
   }
   else{
       // Will be used to find and store the bottom of stack being moved
       struct piece *currPtr;
       currPtr = &board[Y_Co][X_Co]->Top;

       // Will be used to store the piece that the position being moved from will point to
       struct piece *tmp;
       tmp = malloc(sizeof(struct piece)) ;
       tmp = board[Y_Co][X_Co]->Top;

       switch(no_to_move){
           case 5:
               // Finding The bottom of the stack being moved
               for(i=0;i<4;i++)
                   currPtr = &currPtr->piece_below ;
               // Finding the Piece that the bottom of the stack was pointing to
               for(i=0;i<5;i++)
                   tmp = tmp->piece_below ;

               // Moving the stack ontop of the desired stack
               board[Y_Co][X_Co]->Top->piece_below->piece_below->piece_below->piece_below->piece_below =board[new_Y][new_X]->Top;
               board[new_Y][new_X]->Top = board[Y_Co][X_Co]->Top ;
               board[Y_Co][X_Co]->Top = tmp ;

               // Changing the number of pieces in the stacks
               board[Y_Co][X_Co]->no_Pieces -= no_to_move ;
               board[new_Y][new_X]->no_Pieces += no_to_move ;
               free(currPtr) ;
               break ;

           case 4:
               // Finding The bottom of the stack being moved
               for(i=0;i<3;i++)
                   currPtr = &currPtr->piece_below ;
               // Finding the Piece that the bottom of the stack was pointing to
               for(i=0;i<4;i++)
                   tmp = tmp->piece_below ;

               // Moving the stack ontop of the desired stack
               board[Y_Co][X_Co]->Top->piece_below->piece_below->piece_below->piece_below = board[new_Y][new_X]->Top;
               board[new_Y][new_X]->Top = board[Y_Co][X_Co]->Top ;
               board[Y_Co][X_Co]->Top = tmp ;

               // Changing the number of pieces in the stacks
               board[Y_Co][X_Co]->no_Pieces -= no_to_move ;
               board[new_Y][new_X]->no_Pieces += no_to_move ;
               free(currPtr) ;
               break ;

           case 3:
               // Finding The bottom of the stack being moved
               for(i=0;i<2;i++)
                   currPtr = &currPtr->piece_below ;
               // Finding the Piece that the bottom of the stack was pointing to
               for(i=0;i<3;i++)
                   tmp = tmp->piece_below ;

               // Moving the stack ontop of the desired stack
               board[Y_Co][X_Co]->Top->piece_below->piece_below->piece_below =board[new_Y][new_X]->Top;
               board[new_Y][new_X]->Top = board[Y_Co][X_Co]->Top ;
               board[Y_Co][X_Co]->Top = tmp ;

               // Changing the number of pieces in the stacks
               board[Y_Co][X_Co]->no_Pieces -= no_to_move ;
               board[new_Y][new_X]->no_Pieces += no_to_move ;
               free(currPtr) ;
               break ;
           case 2:
               // Finding The bottom of the stack being moved
               currPtr = &currPtr->piece_below ;
               // Finding the Piece that the bottom of the stack was pointing to
               for(i=0;i<2;i++)
                   tmp = tmp->piece_below ;

               // Moving the stack ontop of the desired stack
               board[Y_Co][X_Co]->Top->piece_below->piece_below = board[new_Y][new_X]->Top;
               board[new_Y][new_X]->Top = board[Y_Co][X_Co]->Top ;
               board[Y_Co][X_Co]->Top =  tmp ;

               // Changing the number of pieces in the stacks
               board[Y_Co][X_Co]->no_Pieces -= no_to_move ;
               board[new_Y][new_X]->no_Pieces += no_to_move ;
               free(currPtr) ;
               break ;
           case 1:
               // Finding the Piece that the bottom of the stack was pointing to
               tmp=tmp->piece_below ;

               // Moving the stack ontop of the desired stack
               board[Y_Co][X_Co]->Top->piece_below = board[new_Y][new_X]->Top ;
               board[new_Y][new_X]->Top = board[Y_Co][X_Co]->Top ;
               board[Y_Co][X_Co]->Top = tmp ;

               // Changing the number of pieces in the stacks
               board[Y_Co][X_Co]->no_Pieces -= no_to_move ;
               board[new_Y][new_X]->no_Pieces += no_to_move ;
               break ;

           default: printf("Error in move.c") ; break ;
       }
   }
   printf("\nThere are %d pieces in column %d,row %d\n",board[new_Y][new_X]->no_Pieces,new_Y,new_X) ;

/*
   // Pop extras funtion
   if(board[new_Y][new_X]->no_Pieces>5){
       struct piece *pop;
       pop = malloc(sizeof(struct piece)) ;
       pop = board[new_Y][new_X]->Top;
       for(i=0;i<6;i++)
           pop = pop->piece_below;
       board[new_Y][new_X]->Top->piece_below->piece_below->piece_below->piece_below->piece_below = NULL ;
       while(pop->piece_below!=NULL){
           printf("\nspare piece colour = %d\n",pop->player_col) ;
           pop = pop->piece_below ;
       }


   }
*/
       return ;
}