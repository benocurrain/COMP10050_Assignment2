//
// Created by Ben on 13/04/2020.
//

#ifndef UNTITLED3_INTIALZING_H
#define UNTITLED3_INTIALZING_H

#include <stdio.h>
#include <stdlib.h>

struct piece{

    int player_col ;

    struct piece *piece_below ;

};

struct board_Pos {

    int no_Pieces ;

    struct piece *Top ;

} ;


// The following global variables are used to keep track of dominated stacks and pieces in hand
int Pl1_stcks ;
int Pl2_stcks ;

int Pl1_piece ;
int Pl2_piece ;

struct board_Pos *board[8][8] ;

int intialize_board() ;

#endif //UNTITLED3_INTIALZING_H
