#include "Menu.h"
#include "Mesin.h"
#include "Utama.h"


int main() {
    Mesin::Inisialisasi();

    if (!Mesin::CekWarna() || COLORS < 8) {
        printw("Terminal anda Support %d Warna", COLORS);
        Mesin::Hentikan();
        return 1;
    }
    printw("Terminal anda Support %d Warna", COLORS);
    Mesin::BuatWarna();
    MenuUtama apcb;
    //attron(COLOR_PAIR(7));
    //mvprintw(8, 8, "tesss");
    //refresh();
    refresh();
    getch();

    endwin();
}

