#include <ncurses.h>
#include <string>

using namespace std;
const int lebar = 42, header = 3, footer = 3, StartLine = header+1;
string login[] = {"Login Admin", "Login Member"};
string pw[] = {"Username", "Password"};
string pilihanAdmin[] = {"Input Buku", "Edit Buku", "History", "Exit"};

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
    }
    else if (kode == 7) {
        init_pair(14, COLOR_BLACK, COLOR_WHITE);
        return 14;
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

int menuAdmin() {
    curs_set(0);
    clear();
    string JudulMenuAdmin = "Menu Administrasi";
    int milih = 0, pilihan = 1, baris, mid;
    mid = (lebar/2) - (JudulMenuAdmin.length()/2);
    baris = sizeof(pilihanAdmin)/sizeof(pilihanAdmin[0]);
    tabel(baris);
    attron(COLOR_PAIR(warna(1)));
        move(1, mid);
        printw("%s", JudulMenuAdmin.c_str());
        attroff(COLOR_PAIR(warna(1)));
    for (int i = 0; i < baris; i++) {
        attron(COLOR_PAIR(warna(1)));
        move(StartLine + i, 5);
        if (i == 0) {
            attron(COLOR_PAIR(warna(2)));
            printw("%-13s          ",pilihanAdmin[milih].c_str());
            attroff(COLOR_PAIR(warna(2)));
        }
        else {
            printw("%-13s          ",pilihanAdmin[i].c_str());
        }
        attroff(COLOR_PAIR(warna(1)));
    }
    while ((pilihan = getch()) != 10) {
        switch (pilihan) {
            case KEY_UP:
                if (milih > 0) {
                    milih--;
                    attron(COLOR_PAIR(warna(1)));
                    move(StartLine + milih + 1, 5);
                    printw("%-13s          ",pilihanAdmin[milih +1].c_str());
                    attroff(COLOR_PAIR(warna(1)));
                    attron(COLOR_PAIR(warna(2)));
                    move(StartLine + milih, 5);
                    printw("%-13s          ",pilihanAdmin[milih].c_str());
                    attroff(COLOR_PAIR(warna(2)));
                }
            break;
            case KEY_DOWN:
                if (milih < 3) {
                    milih++;
                    attron(COLOR_PAIR(warna(1)));
                    move(StartLine + milih - 1, 5);
                    printw("%-13s           ",pilihanAdmin[milih -1].c_str());
                    attroff(COLOR_PAIR(warna(1)));
                    attron(COLOR_PAIR(warna(2)));
                    move(StartLine + milih, 5);
                    printw("%-13s          ",pilihanAdmin[milih].c_str());
                    attroff(COLOR_PAIR(warna(2)));
                }
            break;
        }
    }
    refresh();
    //getch();
    return 0;
}
int choose(int menu) {
    if (menu == 1) {
        int milih = 0;
        int pilihan = 1, key, mid, baris;
        string JudulUtama = "Program Perpusku";
        baris = sizeof(login)/ sizeof(login[0]);
        mid = (lebar / 2) - (JudulUtama.length()/2);
        tabel(baris);
        attron(COLOR_PAIR(warna(1)));
        move(1, mid);
        printw("%s",JudulUtama.c_str());
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
    else if (menu == 2) {
        move(0,0);
        curs_set(1);
        echo();
        string username = "", password = "", JudulLoginAdmin = "Login Sebagai Admin";
        int baris = sizeof(pw)/sizeof(pw[0]);
        int huruf, pilihan = 0, mid;
        mid = (lebar/2) - (JudulLoginAdmin.length()/2);
        tabel(baris);
        attron(COLOR_PAIR(warna(1)));
        move(1, mid);
        printw("%s", JudulLoginAdmin.c_str());
        attroff(COLOR_PAIR(warna(1)));
        move(StartLine, 5);
        printw("%s", pw[0].c_str()); move(StartLine, 15); printw(":");
        move(StartLine+1, 5);
        printw("%s", pw[1].c_str()); move(StartLine+1,15); printw(":");
        move(StartLine, 17);
        do {

            huruf = getch();
            switch(huruf) {
                case KEY_UP:
                    pilihan = 0;
                    move(StartLine, 17 + username.length());
                break;
                case KEY_DOWN:
                    pilihan = 1;
                    move(StartLine +1, 17 + password.length());
                break;
                case 10:
                    if (pilihan == 0) {
                        move(StartLine +1, 17 + password.length());
                        pilihan = 1;
                    }
                    else if (pilihan == 1){
                        pilihan = 2;
                    }
                break;
                case KEY_BACKSPACE:
                    if (pilihan == 0 && !username.empty()) {
                        printw(" ");
                        move(StartLine, 17+ username.length() - 1);
                        username.pop_back();
                    }
                    else if (pilihan == 1 && !password.empty()) {
                        printw(" ");
                        move(StartLine+1, 17+ password.length() - 1);
                        password.pop_back();
                    }
                    else {
                        move(StartLine + pilihan, 17);
                    }
                break;
                default:
                    if (pilihan == 0) {
                        username += huruf;
                    }
                    if (pilihan == 1) {
                        password += huruf;
                    }
                break;
            }
        refresh();
        }while (pilihan != 2);
    clear();
    refresh();
    printw("username: %s", username.c_str());
    printw("password: %s", password.c_str());
    if (username == "Admin1" && password == "Abc123") {
        noecho();
        attron(COLOR_PAIR(warna(1)));
        menuAdmin();
        attroff(COLOR_PAIR(warna(1)));
    }
    else {
        //printw("fail");
        //getch();
        noecho();
        attron(COLOR_PAIR(warna(1)));
        menuAdmin();
        attroff(COLOR_PAIR(warna(1)));
    }

    //getch();
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
    if (pilihan == 0) {
        clear();
        refresh();
        attron(COLOR_PAIR(warna(1)));
        pilihan = choose(2);
        attroff(COLOR_PAIR(warna(1)));

    }

    //getch();

}



