#ifndef MENU_H
#define MENU_H

#include "Mesin.h"
#include <ncurses.h>

class Menu
{
     public:
        Menu();
        void warnaiBackGround(WINDOW *layar, int kode);
        void tes();
    protected:

    private:
        int x,y;
        //WINDOW *layar;

};

#endif // MENU_H
