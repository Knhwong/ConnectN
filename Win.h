//
// Created by lear on 2/6/19.
//

#ifndef CONNECTN_WIN_H
#define CONNECTN_WIN_H
#include <stdbool.h>
#include "Board.h"
#include "move.h"

bool isGameOver(Board board, int condition, FILE* fp, Play* win, TurnType playerTurn);
bool win(Board board, int condition);
bool horzWin(Board board, int condition);
bool vertWin(Board board, int condition);
bool diagWin(Board board, int condition);
bool leftDiagWin(Board board, int condition);
bool rightDiagWin(Board board, int condition);
bool tie(Board board, int condition);
void declareWinner(Board board, TurnType playerTurn, int condition);
#endif //CONNECTN_WIN_H
