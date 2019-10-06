//
// Created by lear on 2/6/19.
//

#include <stdbool.h>
#include "Win.h"

bool isGameOver(Board board, int condition, FILE* fp, Play* playarea, TurnType playerTurn) {
    if ((win(board, condition))== true) {
        for(int p =0; p < playarea->hold; p++){
            if (p == playarea->cols){
                char meh = "XO"[playerTurn];
                if (meh == 'O'){
                    meh = 'X';
                } else if (meh == 'X'){
                    meh = 'O';
                }
                fprintf(fp,"%c", meh);
            }else{
                fprintf(fp, " ");
            }
        }
        fprintf(fp, "\n");
        printBoardFile(board, fp);
        if (playerTurn == Player1){
            printf("Player O wins!\n");
        } else if (playerTurn == Player2){
            printf("Player X wins!\n");
        }

        if (playerTurn == Player1){
            fprintf(fp, "Player 2 won!  \n");
        } else if (playerTurn == Player2){
            fprintf(fp, "Player 1 won!  \n");
        }
        return win(board, condition) || tie(board, condition);
    }

    if ((tie(board, condition))== true) {
        for(int p =0; p < playarea->hold; p++){
            if (p == playarea->cols){
                char meh = "XO"[playerTurn];
                if (meh == 'O'){
                    meh = 'X';
                } else if (meh == 'X'){
                    meh = 'O';
                }
                fprintf(fp,"%c", meh);
            }else{
                fprintf(fp, " ");
            }
        }
        fprintf(fp, "\n");
        printBoardFile(board, fp);
       fprintf(fp, "Tie Game  ");
        return win(board, condition) || tie(board, condition);
    }






    for(int p =0; p < playarea->hold; p++){
        if (p == playarea->cols){
            char meh = "XO"[playerTurn];
            fprintf(fp,"%c", meh);
        }else{
            fprintf(fp, " ");
        }
    }

    fprintf(fp, "\n");
    printBoardFile(board, fp);
    fprintf(fp, "\n               \n");
    return win(board, condition) || tie(board, condition);
}

bool win(Board board, int condition) {
    return horzWin(board, condition) || vertWin(board, condition) || diagWin(board, condition);
}


bool horzWin(Board board, int condition) {
    int checker;
    int num=0;
    checker = board.cols - condition-1;
    for (int y =0; y<board.rows; y++){
        for (int x= 0; x<board.cols; x++) {
            if (board.Position[y][x] != '*') {
                if (x < checker && x != checker) {
                    for (int w = x; w < (x+condition); w++) {
                        if (board.Position[y][w] == board.Position[y][x]) {
                            num++;
                            if (num == condition){
                                return true;
                            }
                        }
                    }



                    num=0;
                } else if (x > checker && x != checker) {
                    for (int w = x; w > (x - condition); w--) {
                        if (board.Position[y][w] == board.Position[y][x]) {
                            num++;
                            if (num == condition){
                                return true;
                            }
                        }
                    }
                    num=0;
                }
            }
        }
    }
    return false;
}

bool vertWin(Board board, int condition) {
    int checker;
    int num=0;
    checker = board.rows - condition;
    if (checker == 0){
        checker = condition/2;
    }
    for (int y =0; y<board.rows; y++){
        for (int x= 0; x<board.cols; x++) {
            if (board.Position[y][x] != '*') {
                if (y < checker && y != checker) {
                    for (int w = y; w < (condition + y); w++) {
                        if (w > board.rows-1){
                            return false;
                        }
                        if (board.Position[w][x] == board.Position[y][x]) {
                            num++;
                            if (num == condition){
                                return true;
                            }
                        }
                    }
                    num=0;
                } else if (y > checker && y != checker) {
                    for (int w = y; w > (y - condition); w--) {
                        if (w<0){
                            return false;
                        }
                        if (board.Position[w][x] == board.Position[y][x]) {
                            num++;
                            if (num == condition){
                                return true;
                            }
                        }
                    }
                    num=0;
                }
            }
        }
    }
    return false;
}

























bool diagWin(Board board, int condition) {
    return leftDiagWin(board, condition) || rightDiagWin(board, condition);
}

bool leftDiagWin(Board board, int condition) {
    int conditionx = board.cols - condition;
    int conditiony = board.rows - condition;

    if (conditiony == 0){
        conditiony = condition/2;
    }

    int num=0;
    for (int rows =0; rows < board.rows; rows++){
        for (int cols=0; cols<board.cols; cols++) {
            if (board.Position[rows][cols] != '*') {
                if ((cols >= conditionx) && (rows <= conditiony)){
                int x = cols;
                int y = rows;
                for (int p = 0; p < condition; p++) {

                    if (y > board.rows-1){
                        return false;
                    }

                    if (x < 0){
                        return false;
                    }


                    if (board.Position[rows][cols] == board.Position[y][x]) {
                        y++;
                        x--;
                        num++;
                        if (num == condition) {
                            return true;
                        }
                    }
                }
                num = 0;

            } else if ((cols <= conditionx) && (rows >= conditiony)) {
                int x = cols;
                int y = rows;
                for (int p = 0; p < condition; p++) {
                    if (y < 0){
                        return false;
                    }
                    if (x > board.rows-1){
                        return false;
                    }

                    if (board.Position[rows][cols] == board.Position[y][x]) {
                        y--;
                        x++;
                        num++;
                        if (num == condition) {
                            return true;
                        }
                    }
                }
                num = 0;
            }
            }
        }

    }
    return false;
}


bool rightDiagWin(Board board, int condition) {
    int conditionx = board.cols - condition;
    int conditiony = board.rows - condition;

    if (conditiony == 0){
        conditiony = condition/2;
    }

    int num=0;
    for (int rows =0; rows < board.rows; rows++){
        for (int cols=0; cols < board.cols; cols++){
            if (board.Position[rows][cols] != '*') {
                if ((cols <= conditionx) && (rows <= conditiony)) {
                    int x = cols;
                    int y = rows;
                    for (int p = 0; p < condition; p++) {

                        if (y > board.rows-1){
                            return false;
                        }
                        if (x > board.rows-1){
                            return false;
                        }


                        if (board.Position[rows][cols] == board.Position[y][x]) {
                            y++;
                            x++;
                            num++;
                            if (num == condition) {
                                return true;
                            }
                        }
                    }
                    num = 0;
                } else if ((cols >= conditionx) && (rows >= conditiony)) {
                    int x = cols;
                    int y = rows;
                    for (int p = 0; p < condition; p++) {

                        if (y > 0){
                            return false;
                        }
                        if (x > 0){
                            return true;
                        }

                        if (board.Position[rows][cols] == board.Position[y][x]) {
                            y--;
                            x--;
                            num++;
                            if (num == condition) {
                                return true;
                            }
                        }
                    }
                    num = 0;
                }
            }
        }
    }
    return false;
}

bool tie(Board board, int condition) {

    if(win(board, condition)){
        return false;
    }

    for (int row = 0; row < board.rows; ++row) {
        for (int col = 0; col < board.cols; ++col) {
            if(board.Position[row][col] == board.empty){
                return false;
            }
        }
    }
    return true;
}

void declareWinner(Board board, TurnType playerTurn, int condition) {
    if(win(board, condition)){
        //if someone one it would actually be the loser's turn
        //so account for this here
        int winner = playerTurn == Player1 ? Player2 : Player1;
        winner++;

        printf("Player %d won!\n", winner);

    }else{
        printf("Tie Game.\n");
    }
}
