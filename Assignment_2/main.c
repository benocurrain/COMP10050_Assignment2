#include <stdio.h>
#include "intialzing.h"
#include "Print.h"
#include "Move.h"


int main() {
    printf("Hello, World!\n");
    int i ;



    intialize_board() ;

    print_Board() ;

    for(i=0;i<11;i++) {
        Move(((i%2)+1));

        print_Board();
    }

    return 0;
}
