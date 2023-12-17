#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>

using namespace std;
void masukkanBuku(), editBuku(), admin(), masuk(), member();

struct Buku {
    string kode;
    string judul;
    string pengarang;
    int halaman;
};
void move(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void tampilkanDataBuku() {
    ifstream file("databuku.txt");
    if (file.is_open()) {
        for (int i = 0; i < 10; i++) {
            if (i == 0) {
                cout << "+------+-----------------------------------------------+------------------------+-----------+\n"
                     << "| kode |        Judul                                  |       Pengarang        |   jum hal |\n"
                     << "+------+-----------------------------------------------+------------------------+-----------+\n";
            }
            else if (i == 9) {
                cout << "+------+-----------------------------------------------+------------------------+-----------+\n";
            }
            else {
                string kode[1000], judul[1000], pengarang[1000], halaman[1000];
                int i = 0;
                while (getline(file, kode[i], ',')) {
                    getline(file, judul[i], ',');
                    getline(file, pengarang[i], ',');
                    getline(file, halaman[i]);
                    cout << "| " << left
                    << setw(5)  << kode[i]  <<"|"
                    << setw(47) << judul[i] <<"|"
                    << setw(24) << pengarang[i] << "|"
                    << setw(11)  << halaman[i] << "|\n";
                i++;
                }
            }

        }
        file.close();
    } else {
        cout << "Gagal membuka file." << endl;
    }
}
void cari() {
    system("cls");
    string input;
    ifstream file("databuku.txt");
    if (file.is_open()) {
    string kode[1000], judul[1000], pengarang[1000], halaman[1000];
    cout << "+-------------------------------------------------------------------------------------------+\n"
         << "|       Masukkan Kata Kunci:                                                                |\n"
         << "+------+-----------------------------------------------+------------------------+-----------+\n"
         << "| kode |        Judul                                  |       Pengarang        |   jum hal |\n"
         << "+------+-----------------------------------------------+------------------------+-----------+";
    move(28,1);
    cin.ignore();
    getline(cin, input);
    move(0,5);
    int k = 0;
    while (getline(file, kode[k], ',')) {
        getline(file, judul[k], ',');
        getline(file, pengarang[k], ',');
        getline(file, halaman[k]);
        size_t found = judul[k].find(input);
        if (found != string::npos) {
            cout << "| " << left
                 << setw(5) << kode[k] << "|"
                 << setw(47) << judul[k] << "|"
                 << setw(24) << pengarang[k] << "|"
                 << setw(11) << halaman[k] << "|\n";
        }
    }
    cout << "+------+-----------------------------------------------+------------------------+-----------+\n";
    file.close();
    }
    else {
        cout << "Gagal membuka file." << endl;
    }
}
    string login =
        "============================================\n"
        "|   PROGRAM PEMINJAMAN BUKU PERPUSTAKAAN   |\n"
        "============================================\n"
        "|                                          |\n"
        "| 1. Login sebagai Admin                   |\n"
        "| 2. Login sebagai Member                  |\n"
        "| 0. Keluar                                |\n"
        "============================================\n"
        "| Masukan pilihan Anda        :            |\n"
        "============================================";
    string loginAdmin =
        "====================================\n"
        "|           LOGIN ADMIN            |\n"
        "====================================\n"
        "|                                  |\n"
        "| Username        :                |\n"
        "| Password        :                |\n"
        "|                                  |\n"
        "====================================";
    string loginMember =
        "====================================\n"
        "|           LOGIN MEMBER           |\n"
        "====================================\n"
        "|                                  |\n"
        "| Username        :                |\n"
        "| Password        :                |\n"
        "|                                  |\n"
        "====================================";
    string dashboardAdmin =
        "====================================\n"
        "|         DASHBOARD ADMIN          |\n"
        "====================================\n"
        "|                                  |\n"
        "| 1. Input Buku                    |\n"
        "| 2. Edit Buku                     |\n"
        "| 3. Data Buku                     |\n"
        "| 4. Log Out                       |\n"
        "|                                  |\n"
        "====================================\n"
        "| Masukan pilihan anda      :      |\n"
        "====================================";
    string inputBuku =
        "====================================\n"
        "|           INPUT BUKU             |\n"
        "====================================\n"
        "|                                  |\n"
        "| Masukan judul buku      :        |\n"
        "| Masukan kode buku       :        |\n"
        "| Masukan nama penggarang :        |\n"
        "| Masukan jumlah halaman  :        |\n"
        "|                                  |\n"
        "====================================";
    string dataBuku =
        "===========================================\n"
        "|                DATA BUKU                |\n"
        "===========================================\n"
        "| kode |   Judul    |  Penggarang  |  hal |\n"
        "===========================================\n"
        "| xxxx |   Buku 1   |  Mr. X       |  xx  |\n"
        "| xxxx |   Buku 2   |  Mr. Y       |  xxx |\n"
        "| xxxx |   Buku 3   |  Mr. Z       |  xx  |\n"
        "| xxxx |   Buku 4   |  Mr. X       |  xx  |\n"
        "| xxxx |   Buku 5   |  Mr. Y       |  xxx |\n"
        "| xxxx |   Buku 6   |  Mr. Z       |  xx  |\n"
        "| xxxx |   Buku 7   |  Mr. X       |  xx  |\n"
        "| xxxx |   Buku 8   |  Mr. Y       |  xxx |\n"
        "===========================================";
string dashboardMember =
        "====================================\n"
        "|         DASHBOARD MEMBER         |\n"
        "====================================\n"
        "|                                  |\n"
        "| 1. Cari Buku                     |\n"
        "| 2. Peminjaman Buku               |\n"
        "| 3. Exit                          |\n"
        "|                                  |\n"
        "====================================\n"
        "| Masukan pilihan anda      :      |\n"
        "====================================";

void masuk (int user) {
    string nama,pw;
    system("cls");
    if (user == 1) {
        cout << loginAdmin;
        move(19, 4);
        cin >> nama;
        move(19, 5);
        cin >> pw;
        if ((nama == "admin") &&(pw == "123")) {
            admin();
        }
    }

    else if (user == 2) {
        cout << loginMember;
        move(19, 4);
        cin >> nama;
        move(19, 5);
        cin >> pw;
        if ((nama == "member") &&(pw == "123")) {
            member();
        }
    }
}



int main() {
    int input;
    system("cls");
    cout << login;

    move(31, 8);
    cin >> input;
    if (input > 0 && input < 3) {
        masuk(input);
    }
    else if (input == 0) {
        return 0;
    }

    return 0;
}

void masukkanBuku() {
    system("cls");
    cout << inputBuku;
}
void editBuku() {
}
void data() {
    system("cls");
    tampilkanDataBuku();
}
void admin() {
    int input;
    system("cls");
    cout << dashboardAdmin;
    move(29, 10);
    cin >> input;
    switch (input) {
        case 1:
            masukkanBuku();
        break;
        case 2:
            cari();
        break;
        case 3:
            data();
        break;
        case 4:
            main();
        break;
    }
}
void member() {
    int input;
    system("cls");
    cout << dashboardMember;
    move(29, 9);
    cin >> input;
    switch (input) {
        case 1:
            cari();
        break;
        case 2:

        break;
        case 3:

        break;

    }
}
