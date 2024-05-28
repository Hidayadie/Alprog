#include "Layar.h"

Layar::Layar()
{
    getmaxyx(stdscr, y, x);


    warnaiBackGround(stdscr, 100);
    refresh();
}


void Layar::warnaiBackGround(WINDOW *layar, int kode) {
    //box(layar, 0,0);
    wbkgd(layar, COLOR_PAIR(kode));
    wrefresh(layar);
}

void Layar::tes() {
    mvprintw(5,6,"ha");
}
/*
Layar::~Layar()
{
    //dtor
}
*/
