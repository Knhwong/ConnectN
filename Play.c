//
// Created by lear on 2/6/19.
//

#include "Play.h"
Play makeplay(int cols){
    Play playarea;
    playarea.hold=cols;
    playarea.cursesWin = newwin(1, cols, 0, 0);
    wmove(playarea.cursesWin, 0,0);
    return playarea;
}

void playmove(Play* win, int col) {
    wmove(win->cursesWin, 0, col);
    win->cols = col;
}

