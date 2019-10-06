//
// Created by lear on 2/6/19.
//

#ifndef CONNECTN_BOARD_H
#define CONNECTN_BOARD_H
#include "View.h"
#include <ncurses.h>
#include "Play.h"

typedef struct Board_Struct{
    char ** Position;
    int rows;
    int cols;
    char empty;

}Board;

Board makeBoard(int numRows, int numCols, char blankChar);
void addCharacter(Viewboard* win, Play* play, char toAdd);
void moveAndAddCharacter(Viewboard* win, Play* play, int row, int col, char toAdd);
void printBoard(Board board);
void printBoardFile(Board board, FILE* fp);
void cleanUpBoard(Board* board);
void printBoardFileFirst(Board board, FILE* fp);


#endif //CONNECTN_BOARD_H
