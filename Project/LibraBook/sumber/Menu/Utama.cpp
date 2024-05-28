#include "Utama.h"

MenuUtama::MenuUtama()
{
    WINDOW *Utama = newwin(7, 20, 3, 3);
    box(Utama, 0, 0);
    wrefresh(Utama);
    warnaiBackGround(Utama, 101);

    wgetch(Utama);

}


