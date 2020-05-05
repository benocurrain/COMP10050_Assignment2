#include <stdio.h>
#include "intialzing.h"
#include "Print.h"
#include "Move.h"


int main() {
    int i ;
    intialize_board() ;

    print_Board() ;

    for(i=0;;i++) {
        if( (Pl1_stcks==0) && (Pl1_piece==0) ){
            printf("Player 2 Wins!!"
                   "They have %d stacks dominated and %d pieces in hand",Pl2_stcks, Pl2_piece) ;
            break ;
        }
        if( (Pl2_stcks==0) && (Pl2_piece==0) ){
            printf("Player 1 Wins!!\n"
                   "They have %d stacks dominated and %d pieces in hand",Pl1_stcks, Pl1_piece) ;
            break ;
        }

        Move(((i%2)+1));

        print_Board();
    }

    return 0;
}
