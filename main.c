#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "View.h"
#include "Play.h"
#include "Board.h"
#include "Win.h"

FILE* validate_input(int argc, char* argv[]){

    FILE* fp = NULL;

    if(argc < 2){
        printf("Not enough arguments entered.\nEnding program.\n");
        exit(0);
    }
    else if(argc > 2){
        printf("Too many arguments entered.\nEnding program.\n");
        exit(0);
    }

    fp = fopen(argv[1], "w");

    if(fp == NULL){
        printf("Unable to open file: %s\nEnding program.\n", argv[1]);
        exit(0);
    }

    return fp;

}

void placeMove(Move move, Board* board, Play* play, Viewboard* win) {
    board->Position[move.row][move.col] = move.marker;
    addCharacter(win, play, move.marker);
    playmove(play, play->cols);
    wrefresh(win->cursesWin);
    wrefresh(play->cursesWin);
}


int main(int argc, char *argv[]) {
    //FILE * fp = validate_input(argc, argv);
    int rows=6;
    int cols=6;
    int condition=3;
    sscanf(argv[1],"%d", &rows);
    sscanf(argv[2],"%d", &cols);
    sscanf(argv[3],"%d", &condition);
    FILE* fp = fopen(argv[4], "w");

    initscr();
    cbreak();
    noecho();
    Viewboard view =makeview(rows, cols);
    Play playarea = makeplay(cols);
    keypad(playarea.cursesWin, true);
    wrefresh(view.cursesWin);
    wrefresh(playarea.cursesWin);
    mvwin(playarea.cursesWin, 0, 0);
    mvwin(view.cursesWin, 1, 0);
    Board board = makeBoard(rows,cols,'*');
    TurnType playerTurn = Player1;
    wmove(playarea.cursesWin, 0, 0);
    playarea.cols =0;
    wrefresh(playarea.cursesWin);
    //printBoardFileFirst(board, fp);
    while(!isGameOver(board, condition, fp, &playarea, playerTurn)){
        Move move = getValidMove(&board, playerTurn, &playarea, fp);
        board.Position[move.row][move.col] = move.marker;
        //printBoardFile(board, fp);
        mvwaddch(view.cursesWin, move.row, move.col, move.marker);
        playmove(&playarea, playarea.cols);
        wrefresh(view.cursesWin);
        wrefresh(playarea.cursesWin);
        //change turn
        //playerTurn = (playerTurn + 1) % 2;
        playerTurn = playerTurn == Player1 ? Player2 : Player1;
    }
    delwin(playarea.cursesWin);
    delwin(view.cursesWin);
    endwin();
    printBoard(board);
    cleanUpBoard(&board);
    fclose(fp);
    return 0;
}