#include <ncurses.h>
#include <string>

using namespace std;
const int lebar = 42, header = 3, footer = 3, StartLine = header+1;
string login[] = {"Login Admin", "Login Member"};

int warna(int kode) {
    start_color();
    if (kode == 1) {
        init_pair(1, COLOR_YELLOW, COLOR_BLACK);
        return 1;
    }
    else if (kode == 2) {
        init_pair(2, COLOR_BLACK, COLOR_WHITE);
        return 2;
    }
    else if (kode == 3) {
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        return 3;
    }
return kode;
}
int background(int kode) {
    start_color();
    if (kode == 1) {
        init_pair(8, COLOR_BLACK, COLOR_RED);
        return 8;
    }
    else if (kode == 2) {
        init_pair(9, COLOR_BLACK, COLOR_YELLOW);
        return 9;
    }
    else if (kode == 3) {
        init_pair(10, COLOR_BLACK, COLOR_GREEN);
        return 10;
    }
    else if (kode == 4) {
        init_pair(11, COLOR_BLACK, COLOR_CYAN);
        return 11;
    }
    else if (kode == 5) {
        init_pair(12, COLOR_BLACK, COLOR_BLUE);
        return 12;
    }
    else if (kode == 6) {
        init_pair(13, COLOR_BLACK, COLOR_MAGENTA);
        return 13;
        //break;
    }
    else if (kode == 7) {
        init_pair(14, COLOR_BLACK, COLOR_WHITE);
        return 14;
        //break;
    }
    return kode + 7;
}

void tabel(int pilihan) {
    int tinggi = header + pilihan+2 + footer;
    for (int i = 0; i < tinggi; i++) {
        if ((i == 0)||(i == 2)||(i == tinggi-1) || (i == (tinggi - 3))) {
            move(i,0);
            printw("+");
            for (int j = 1; j <= lebar-1; j++) {
                move(i,j);
                printw("=");
            move(i,lebar);
            printw("+");
            }
        }
        else if ((i > header -1 ) && (i < (tinggi - footer))||(i == (tinggi - 2))|| (i == 1)) {
            move(i, 0);
            printw("|");
            move(i, lebar);
            printw("|");
        }
    }
    string apcb = "Perpusqu V 0.1 (LF)";
    move(tinggi -2 , 3);
    printw("%s", apcb.c_str());
    for (int i = 1; i < 8; i++) {
        move(tinggi-2, (apcb.length() +7) + i);
        attron(COLOR_PAIR(background(i)));
        printw(" ");
        attroff(COLOR_PAIR(background(i)));
    }
    refresh();
}

int choose(int menu) {
    if (menu == 1) {
        int milih = 0;
        int pilihan = 1, key, mid, baris;
        baris = sizeof(login)/ sizeof(login[0]);
        mid = login[1].size() / 2;
        tabel(baris);
        attron(COLOR_PAIR(warna(1)));
        for (int i = 0; i < baris; i++) {
            move(StartLine + i, 5);
            if (i == 0) {
                attron(COLOR_PAIR(warna(2)));
                printw("%s           ",login[milih].c_str());
                attroff(COLOR_PAIR(warna(2)));
            }
            else {
                printw("%s",login[i].c_str());
            }
        }
        attroff(COLOR_PAIR(warna(1)));
        while ((pilihan = getch()) != 10) {
            switch (pilihan) {
                case KEY_UP:
                    if (milih > 0) {
                        milih--;
                        attron(COLOR_PAIR(warna(2)));
                        move(StartLine, 5);
                        printw("%s           ",login[milih].c_str());
                        attroff(COLOR_PAIR(warna(2)));
                        attron(COLOR_PAIR(warna(1)));
                        move(StartLine + 1, 5);
                        printw("%s           ",login[milih +1].c_str());
                        attroff(COLOR_PAIR(warna(1)));
                    }
                break;
                case KEY_DOWN:
                    if (milih < 1) {
                        milih++;
                        attron(COLOR_PAIR(warna(2)));
                        move(StartLine + milih, 5);
                        printw("%s          ",login[milih].c_str());
                        attroff(COLOR_PAIR(warna(2)));
                        attron(COLOR_PAIR(warna(1)));
                        move(StartLine, 5);
                        printw("%s           ",login[milih -1].c_str());
                        attroff(COLOR_PAIR(warna(1)));
                    }
                break;
            }
        }
        return milih;

    }
    return 0;
}



int main() {
    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);
    attron(COLOR_PAIR(warna(1)));
    int pilihan = choose(1);
    attroff(COLOR_PAIR(warna(1)));
    clear();
    refresh();
    printw("%d", pilihan);
    getch();

}



