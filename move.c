//
// Created by lear on 2/6/19.
//
#include <stdio.h>
#include "move.h"
#include "Board.h"
#include "Play.h"

Move getValidMove(Board* board, TurnType playerTurn, Play* win, FILE* fp){
    if (win->cols == win->hold){
        win->cols = 0;
    }
    Move move;
    mvwaddch(win->cursesWin, 0, win->cols, "XO"[playerTurn]);
    wmove(win->cursesWin, 0, win->cols);
    while (true) {
        char input = wgetch(win->cursesWin);
        if (input == 'a' || input == 'j' || input == (KEY_LEFT & A_CHARTEXT)) {
            if (win->cols > 0) {
                mvwaddch(win->cursesWin, 0, win->cols, ' ');
                win->cols -= 1;
                wmove(win->cursesWin, 0, win->cols);
                mvwaddch(win->cursesWin, 0, win->cols, "XO"[playerTurn]);
                wmove(win->cursesWin, 0, win->cols);
                for(int p =0; p < win->hold; p++){
                    if (p == win->cols){
                        char meh = "XO"[playerTurn];
                        fprintf(fp,"%c", meh);
                    }else{
                        fprintf(fp, " ");
                    }
                }
                fprintf(fp, "\n");
                printBoardFile(*board, fp);
                fprintf(fp, "\n               \n");
            } else{
                mvwaddch(win->cursesWin, 0, win->cols, ' ');
                win->cols = (win->hold)-1;
                wmove(win->cursesWin, 0, win->cols);
                mvwaddch(win->cursesWin, 0, win->cols, "XO"[playerTurn]);
                wmove(win->cursesWin, 0, win->cols);
                for(int p =0; p < win->hold; p++){
                    if (p == win->cols){
                        char meh = "XO"[playerTurn];
                        fprintf(fp,"%c", meh);
                    }else{
                        fprintf(fp, " ");
                    }
                }
                fprintf(fp, "\n");
                printBoardFile(*board, fp);
                fprintf(fp, "\n               \n");
            }
        } else if (input == 's' || input == 'k' || input == (KEY_RIGHT & A_CHARTEXT)) {
            if (win->cols < board->cols - 1) {
                mvwaddch(win->cursesWin, 0, win->cols, ' ');
                win->cols += 1;
                wmove(win->cursesWin, 0, win->cols);
                mvwaddch(win->cursesWin, 0, win->cols, "XO"[playerTurn]);
                wmove(win->cursesWin, 0, win->cols);
                for(int p =0; p < win->hold; p++){
                    if (p == win->cols){
                        char meh = "XO"[playerTurn];
                        fprintf(fp,"%c", meh);
                    }else{
                        fprintf(fp, " ");
                    }
                }
                fprintf(fp, "\n");
                printBoardFile(*board, fp);
                fprintf(fp, "\n               \n");
            } else{
                mvwaddch(win->cursesWin, 0, win->cols, ' ');
                win->cols = 0;
                wmove(win->cursesWin, 0, win->cols);
                mvwaddch(win->cursesWin, 0, win->cols, "XO"[playerTurn]);
                wmove(win->cursesWin, 0, win->cols);
                for(int p =0; p < win->hold; p++){
                    if (p == win->cols){
                        char meh = "XO"[playerTurn];
                        fprintf(fp,"%c", meh);
                    }else{
                        fprintf(fp, " ");
                    }
                }
                fprintf(fp, "\n");
                printBoardFile(*board, fp);
                fprintf(fp, "\n               \n");
            }
        } else if (input == ' ' || input == '\n') {
            for (int y = ((board->rows)-1); y>=0; y--){
                if (board->Position[y][win->cols] == '*'){
                    move.col = win->cols;
                    move.row = y;
                    move.marker = "XO"[playerTurn];
                    return move;
                }
            }
            for(int p =0; p < win->hold; p++){
                if (p == win->cols){
                    char meh = "XO"[playerTurn];
                    fprintf(fp,"%c", meh);
                }else{
                    fprintf(fp, " ");
                }
            }
            fprintf(fp, "\n");
            printBoardFile(*board, fp);
            fprintf(fp, "\n               \n");

        } else{
            for(int p =0; p < win->hold; p++){
                if (p == win->cols){
                    char meh = "XO"[playerTurn];
                    fprintf(fp,"%c", meh);
                }else{
                    fprintf(fp, " ");
                }
            }
            fprintf(fp, "\n");
            printBoardFile(*board, fp);
            fprintf(fp, "\n               \n");
        }
        wrefresh(win->cursesWin);
    }

}
