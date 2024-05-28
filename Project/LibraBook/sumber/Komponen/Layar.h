#ifndef LAYAR_H
#define LAYAR_H

#include "Mesin.h"
#include <ncurses.h>

class Layar
{
     public:
        Layar();
        void warnaiBackGround(WINDOW *layar, int kode);
        void tes();
    protected:

    private:
        int x,y;
        //WINDOW *layar;

};

#endif // LAYAR_H
