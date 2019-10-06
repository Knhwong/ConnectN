//
// Created by lear on 2/6/19.
//

#include "View.h"
#include <ncurses.h>

Viewboard makeview(int rows, int cols){
    Viewboard viewboard;
    viewboard.cursesWin = newwin(rows, cols, 1, 0);
    viewboard.rows = rows;
    viewboard.cols = cols;
    for (int x=0; x<rows; x++){
        for (int y=0; y<cols; y++){
            mvwaddch(viewboard.cursesWin, x, y, '*');
        }
    }
    return viewboard;
}