//
// Created by lear on 2/6/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "Board.h"
#include "View.h"
#include "ncurses.h"
#include "Play.h"

Board makeBoard(int numRows, int numCols, char blankChar) {
    Board board;

    board.Position = (char**)malloc(numRows * sizeof(char*));
    for (int i = 0; i < numRows; ++i) {
        board.Position[i] = (char*)malloc(numCols * sizeof(char));
        for (int j = 0; j < numCols; ++j) {
            board.Position[i][j] = blankChar;
        }
    }
    board.rows = numRows;
    board.cols = numCols;
    board.empty = blankChar;
    return board;
}

void moveAndAddCharacter(Viewboard* win, Play* play, int row, int col, char toAdd) {
    mvwaddch(win->cursesWin, row, col, toAdd);
}

void addCharacter(Viewboard* win, Play* play, char toAdd) {
    moveAndAddCharacter(win, play, win->rows, win->cols, toAdd);
    }

void printBoard(Board board) {
    //print column header
    printf("  "); //make things line up
    for (int i = 0; i < board.cols; ++i) {
        printf("%d ", i);
    }
    printf("\n");

    for (int row = 0; row < board.rows; ++row) {
        printf("%d ", row); //print row header
        for (int col = 0; col < board.cols; ++col) {
            printf("%c ", board.Position[row][col]);
        }
        printf("\n");
    }
}

void printBoardFile(Board board, FILE* fp) {
    for (int row = 0; row < board.rows; ++row) {
        for (int col = 0; col < board.cols; ++col) {
            fprintf(fp ,"%c", board.Position[row][col]);
        }
        fprintf(fp,"\n");
    }
}


void printBoardFileFirst(Board board, FILE* fp) {
    fprintf(fp, "X");
    for (int row =0; row < board.rows-1; ++row){
        fprintf(fp, " ");
    }
    fprintf(fp, "\n");
    for (int row = 0; row < board.rows; ++row) {
        for (int col = 0; col < board.cols; ++col) {
            fprintf(fp ,"%c", board.Position[row][col]);
        }
        fprintf(fp,"\n");
    }
}






void cleanUpBoard(Board* board) {

    for (int row = 0; row < board->rows; ++row) {
        free(board->Position[row]);
    }
    free(board->Position);
    board->Position = NULL;
    board->rows = 0;
    board->cols = 0;
}