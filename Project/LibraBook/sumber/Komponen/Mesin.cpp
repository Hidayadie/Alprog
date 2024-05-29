#include "Mesin.h"


void Mesin::Inisialisasi() {
    initscr();
    noecho();
    curs_set(0);
    start_color();

}



void Mesin::Hentikan() {
    getch();
    refresh();
    endwin();
}


bool Mesin::CekWarna() {

    return(has_colors());

}

void Mesin::BuatWarna() {
    start_color();
    //init_color(acak, 896, 100, 100);
    //init_pair(7, acak, COLOR_GREEN);
    if (COLORS > 8) {
        init_color(COLOR_BLUE, 27, 212, 259);
        init_color(COLOR_MAGENTA,478, 556, 545);
        init_pair(100, COLOR_WHITE, COLOR_MAGENTA);
        init_pair(101, COLOR_WHITE, COLOR_BLUE);
        init_pair(1, COLOR_YELLOW, COLOR_MAGENTA);
        init_pair(2, COLOR_WHITE, COLOR_CYAN);

    }
}
