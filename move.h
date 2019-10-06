//
// Created by lear on 2/6/19.
//

#ifndef CONNECTN_MOVE_H
#define CONNECTN_MOVE_H

#include "ncurses.h"
#include "Play.h"
#include <stdbool.h>
#include "Board.h"


typedef enum{Player1 = 0, Player2 = 1}TurnType;

typedef struct Move_struct{
    int row, col, orgcol;
    char marker;
}Move;

Move getValidMove(Board* board, TurnType playerTurn, Play* win, FILE* fp);

#endif //CONNECTN_MOVE_H
