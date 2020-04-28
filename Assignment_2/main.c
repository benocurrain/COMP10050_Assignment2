#include <stdio.h>
#include "intialzing.h"
#include "Print.h"
#include "Move.h"


int main() {
    printf("Hello, World!\n");
    int i ;



    intialize_board() ;
    printf("Runnung 1") ;

   // struct Player *Player_1;
  //  struct Player *Player_2;
  /*
    Player_1->no_Stacks = 18 ;
    Player_1->no_Pieces_hand = 0 ;

    Player_2->no_Stacks = 18 ;
    Player_2->no_Pieces_hand = 0 ;
*/
    Pl1_stcks = 18 ;
    Pl2_stcks = 18 ;

    Pl1_piece = 0 ;
    Pl2_piece = 0 ;

    printf("Runnung 2") ;
    print_Board() ;
    printf("Runnung 3") ;

    for(i=0;i<11;i++) {
        printf("Runnung 3") ;

        Move(((i%2)+1));

        print_Board();
    }

    return 0;
}
