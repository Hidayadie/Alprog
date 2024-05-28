#include "Komponen/Menu.h"
#include "Komponen/Mesin.h"
#include "Menu/Utama.h"


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
    refresh();
    getch();

    endwin();
}

