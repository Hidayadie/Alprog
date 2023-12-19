#include "header.h"
using namespace std;
void masukkanBuku(), edit(), admin(), masuk(), member(), cari();
bool Start_Pertama_Kali = true;
vector<Buku> buku;
void move(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
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
    system("cls");
    ifstream file("databuku.txt");
    if (file.is_open()) {
        if (Start_Pertama_Kali) {
            string kode, judul, pengarang, jumHalaman;
            int index = 1;

            while (getline(file, kode, ',')) {
                getline(file, judul, ',');
                getline(file, pengarang, ',');
                getline(file, jumHalaman);

                // Membuat objek Buku baru
                Buku buku_baru;
                buku_baru.kode = kode;
                buku_baru.judul = judul;
                buku_baru.pengarang = pengarang;
                buku_baru.jumHalaman = jumHalaman;
                buku_baru.index = index;
                // Menambahkan objek Buku ke dalam vektor daftarBuku
                buku.push_back(buku_baru);
                index++;
                Start_Pertama_Kali = false;
            }
        }

        file.close();
    } else {
        cout << "Gagal membuka file." << endl;
    }
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
void read() {
    system("cls");
    ifstream file("databuku.txt");
    if (file.is_open()) {
        cout << "+------+------+-----------------------------------------------+------------------------+-----------+\n"
             << "|  no  | kode |        Judul                                  |       Pengarang        |   jum hal |\n"
             << "+------+------+-----------------------------------------------+------------------------+-----------+\n";
        for (size_t i = 0; i < buku.size(); i++) {
                cout << "| " << left
                     << setw(5)  << buku[i].index <<"|"
                     << setw(6)  << buku[i].kode  <<"|"
                     << setw(47) << buku[i].judul <<"|"
                     << setw(24) << buku[i].pengarang << "|"
                     << setw(11) << buku[i].jumHalaman << "|\n";
        }
        cout << "+------+------+-----------------------------------------------+------------------------+-----------+\n";
        file.close();
    }
     else {
        cout << "Gagal membuka file." << endl;
    }
    char balik;
    cout << "balik? (y/n): "; cin >> balik;
    switch (balik) {
        case 'y':
            admin();
        break;
    }
}
void tambah () {
    system("cls");
    ofstream file("databuku.txt", ios::app);
    if (file.is_open()) {
        //string kode, judul, pengarang, jumHalaman;
        Buku buku_baru;
        int index = 1 + buku.size();
        cin.ignore();
        cout << inputBuku;
        move(27, 4); getline(cin, buku_baru.kode);
        move(27, 5); getline(cin, buku_baru.judul);
        move(27, 6); getline(cin, buku_baru.pengarang);
        move(27, 7); getline(cin, buku_baru.jumHalaman);
        char save;
        move(40, 8); cout << "save? (y/n): "; cin >> save;
        switch (save) {
            case 'y':
                file << buku_baru.kode << ',' << buku_baru.judul << ',' << buku_baru.pengarang << ',' << buku_baru.jumHalaman << "\n";
                buku_baru.index = index;
                buku.push_back(buku_baru);
            break;
        }
        file.close();
    }
    else {
        cout << "error ngab";
    }

     char balik;
    cout << "balik? (y/n): "; cin >> balik;
    switch (balik) {
        case 'y':
            admin();
        break;
    }
}
void edit() {
    system("cls");
    string kode, judul, pengarang, jumHalaman;
    int index; char ngedit, save;
    cout << "pilih nomor index buku yang mau di edit\n(cek di data buku)\nindex: ";cin >> index;
    for (int i = 0; i < buku.size(); i++) {
        if (index == buku[i].index) {
            cout << "Apakah buku dengan judul \""<<buku[i].judul <<"\" ?\n(y/n): "; cin >> ngedit;
            if (ngedit == 'Y' || ngedit == 'y') {
                cin.ignore();
                cout << "kode\t\t" << buku[i].kode<< " diubah ke = "; getline(cin, kode);
                cout << "judul\t\t" << buku[i].judul<< " diubah ke = "; getline(cin, judul);
                cout << "pengarang\t" << buku[i].pengarang<< " diubah ke = "; getline(cin, pengarang);
                cout << "jumlah hal\t" << buku[i].jumHalaman<< " diubah ke = "; getline(cin, jumHalaman);
                cout << "kode buku " << kode
                     << " Buku \"" << judul
                     << "\" yang ditulis oleh \"" << pengarang
                     << "\" berjumlah " <<jumHalaman <<" halaman\n";
                cout << "save? (y/n): "; cin >> save;
                 switch (save) {
                    case 'y':
                        buku[i].kode = kode;
                        buku[i].judul = judul;
                        buku[i].pengarang = pengarang;
                        buku[i].jumHalaman = jumHalaman;
                        ofstream file("databuku.txt");
                        if (file.is_open()) {
                            for (size_t o = 0; o < buku.size(); o++) {
                            file << buku[o].kode << ',' << buku[o].judul << ',' << buku[o].pengarang << ',' << buku[o].jumHalaman << "\n";
                            }
                        file.close();
                        }
                        else {
                            cout << "error ngab";
                        }
                }
            }
        }
    }
     char balik;
    cout << "balik? (y/n): "; cin >> balik;
    switch (balik) {
        case 'y':
            admin();
        break;
    }
}
void cari() {
    system("cls");

    vector<Buku> buku_yang_ketemu;
    Buku buku_yang_dicari;
    string input;
    ifstream file("databuku.txt");

    if (file.is_open()) {
        cout << "+-------------------------------------------------------------------------------------------+\n"
             << "|       Masukkan Kata Kunci:                                                                |\n"
             << "+------+-----------------------------------------------+------------------------+-----------+\n"
             << "| kode |        Judul                                  |       Pengarang        |   jum hal |\n"
             << "+------+-----------------------------------------------+------------------------+-----------+";

        move(28, 1);
        cin.ignore();
        getline(cin, input);
        move(0, 5);
        while (getline(file, buku_yang_dicari.kode, ',')) {
            getline(file, buku_yang_dicari.judul, ',');
            getline(file, buku_yang_dicari.pengarang, ',');
            getline(file, buku_yang_dicari.jumHalaman);

            buku_yang_ketemu.push_back(buku_yang_dicari);
        }

        for (size_t i = 0; i < buku_yang_ketemu.size(); i++) {
            size_t found = buku_yang_ketemu[i].judul.find(input);
            if (found != string::npos) {
                cout << "| " << left
                     << setw(5) << buku_yang_ketemu[i].kode << "|"
                     << setw(47) << buku_yang_ketemu[i].judul << "|"
                     << setw(24) << buku_yang_ketemu[i].pengarang << "|"
                     << setw(11) << buku_yang_ketemu[i].jumHalaman << "|\n";
            }
        }

        cout << "+------+-----------------------------------------------+------------------------+-----------+\n";
        file.close();
    } else {
        cout << "Gagal membuka file." << endl;
    }
}
void admin() {
    int input;
    system("cls");
    cout << dashboardAdmin;
    move(29, 10);
    cin >> input;
    switch (input) {
        case 1:
            tambah();
        break;
        case 2:
            edit();
        break;
        case 3:
            read();
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
