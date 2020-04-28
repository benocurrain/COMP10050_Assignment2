//
// Created by Ben on 25/04/2020.
//

#ifndef UNTITLED3_MOVE_H
#define UNTITLED3_MOVE_H

#include <stdio.h>
#include <stdlib.h>

void Move(int Player) ;
void get_Co_ordinates(int player, int *row, int *column ) ;

void subtract_Dom_stck_other(int plyer);
void subtract_Dom_stck_player(int plyer);
void add_Dom_stck_other(int plyer);
void add_Dom_stck_player(int plyer);

#endif //UNTITLED3_MOVE_H
