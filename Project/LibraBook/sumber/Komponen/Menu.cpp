#include "Menu.h"

Menu::Menu()
{
    getmaxyx(stdscr, y, x);


    warnaiBackGround(stdscr, 100);
    refresh();
}


void Menu::warnaiBackGround(WINDOW *layar, int kode) {
    //box(layar, 0,0);
    wbkgd(layar, COLOR_PAIR(kode));
    wrefresh(layar);
}

void Menu::tes() {
    mvprintw(5,6,"ha");
}
/*
Layar::~Layar()
{
    //dtor
}
*/
