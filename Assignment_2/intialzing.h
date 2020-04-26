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

struct Player {

    int no_Pieces ;

    int no_Stacks ;

    int no_Pieces_hand ;

} ;

struct Player Player_1;
struct Player Player_2;

struct board_Pos *board[8][8] ;

int intialize_board() ;

#endif //UNTITLED3_INTIALZING_H
