//
// Created by lear on 2/6/19.
//

#ifndef CONNECTN_VIEW_H
#define CONNECTN_VIEW_H
#include <ncurses.h>

typedef struct Viewwindow_Struct{
    WINDOW* cursesWin;
    int rows;
    int cols;
}Viewboard;

Viewboard makeview(int rows, int cols);



#endif //CONNECTN_VIEW_H
