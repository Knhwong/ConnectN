//
// Created by lear on 2/6/19.
//

#ifndef CONNECTN_PLAY_H
#define CONNECTN_PLAY_H

#include <ncurses.h>
typedef struct play_Struct{
    WINDOW* cursesWin;
    int cols;
    int hold;
}Play;

Play makeplay(int cols);
void playmove(Play* win, int col);
void printplay(Play* playarea, FILE * fp);

#endif //CONNECTN_PLAY_H
