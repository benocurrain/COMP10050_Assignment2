#include <stdio.h>
#include "intialzing.h"
#include "Print.h"
#include "Move.h"

int main() {
    printf("Hello, World!\n");
    int i ;


    intialize_board() ;

    print_Board() ;

    for(i=0;i<7;i++) {
        Move();

        print_Board();
    }

    return 0;
}
