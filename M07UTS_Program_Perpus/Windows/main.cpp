#include "header.h"
using namespace std;
void masukkanBuku(), edit(), admin(), masuk(), member(), cari();
bool Start_Pertama_Kali = true;
vector<Buku> buku;
vector<User> user;
int user_sekarang = 0;
void rewrite() {
    ofstream file("databuku.txt");
    if (file.is_open()) {
        for (size_t o = 0; o < buku.size(); o++) {
            file << buku[o].kode << ',' << buku[o].judul << ',' << buku[o].pengarang << ',' << buku[o].jumHalaman << ','<<buku[o].tersedia << "\n";
        }
        file.close();
    }
    else {
        cout << "error ngab";
    }
    ofstream data("datauser.txt");
    if (data.is_open()) {
        for (size_t o = 0; o < user.size(); o++) {
            data << user[o].akses << ',' << user[o].nama << ',' << user[o].password << ',' << user[o].meminjam << ',' << user[o].judul << "\n";
        }
        data.close();
    }
    else {
        cout << "errorrr";
    }
}
void move(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void masuk (int input) {
    string nama,pw;
    system("cls");

    if (input == 1) {
        cout << loginAdmin;
        move(19, 4);
        cin >> nama;
        move(19, 5);
        cin >> pw;
        for (size_t i = 0; i < user.size(); i++){
            if (((user[i].akses == "admin"|| user[i].akses == "host")) && (user[i].nama == nama) && (user[i].password == pw)) {
                user_sekarang = i;
                admin();
            }
        }
    }

    else if (input == 2) {
        cout << loginMember;
        move(19, 4);
        cin >> nama;
        move(19, 5);
        cin >> pw;
        for (size_t i = 0; i < user.size(); i++) {
            if (((user[i].akses == "member" || user[i].akses == "host")) && (user[i].nama == nama) && (user[i].password == pw)) {
                user_sekarang = i;
                member();
            }
        }
    }
}
int main() {
    system("cls");
    if (Start_Pertama_Kali) {
        ifstream file("databuku.txt");
        if (file.is_open()) {
            string kode, judul, pengarang, jumHalaman, tersedia;
            int index = 1;

            while (getline(file, kode, ',')) {
                getline(file, judul, ',');
                getline(file, pengarang, ',');
                getline(file, jumHalaman, ',');
                getline(file, tersedia);

                // Membuat objek Buku baru
                Buku buku_baru;
                buku_baru.kode = kode;
                buku_baru.judul = judul;
                buku_baru.pengarang = pengarang;
                buku_baru.jumHalaman = jumHalaman;
                buku_baru.tersedia = tersedia;
                buku_baru.index = index;
                // Menambahkan objek Buku ke dalam vektor daftarBuku
                buku.push_back(buku_baru);
                index++;
            }
        file.close();
        }
        else {
            cout << "Gagal membuka file Buku" << endl;
        }

        ifstream data("datauser.txt");
        if (data.is_open()) {
            int index = 1;
            string akses, nama, password, meminjam, judul;
            while (getline(data, akses, ',')) {
                getline(data, nama, ',');
                getline(data, password, ',');
                getline(data, meminjam, ',');
                getline(data, judul);

                User user_iterasi;
                user_iterasi.index = index;
                user_iterasi.akses = akses;
                user_iterasi.nama = nama;
                user_iterasi.password = password;
                user_iterasi.meminjam = meminjam;
                user_iterasi.judul = judul;

                user.push_back(user_iterasi);
                index++;
            }
        data.close();
        }

        else {
            cout << "Gagal membuka file User" << endl;
        }
        Start_Pertama_Kali = false;
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
                     << setw(11) << buku[i].jumHalaman << "|"
                     << setw(11) << buku[i].tersedia << "\n";
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
    for (size_t i = 0; i < buku.size(); i++) {
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
                            file << buku[o].kode << ',' << buku[o].judul << ',' << buku[o].pengarang << ',' << buku[o].jumHalaman << ','<<buku[o].tersedia << "\n";
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
void minjem() {
    int index, input;
    char ya;
    system("cls");
    cout << peminjaman;
    move(29, 10);
    cin >> input;
    if (input == 1 && user[user_sekarang].meminjam == "false") {
        cout << "\n\nindex buku: "; cin >> index;
        for (size_t i = 0; i < buku.size(); i++) {
            if ((buku[i].index == index) && (buku[i].tersedia == "true")) {
                cout <<"Apakah \""<< buku[i].judul << "\" ?(y/n): "; cin >> ya;
                if (ya == 'Y' || ya == 'y') {
                    user[user_sekarang].judul = buku[i].judul;
                    user[user_sekarang].meminjam = "true";
                    buku[i].tersedia = "false";
                    rewrite();
                }
            }
        }
        system("cls");
        cout << "tunggu sebentar... kembali ke menu sebelumnya...";
        Sleep(1500);
        minjem();
    }
    else if (input == 1 && user[user_sekarang].meminjam == "true") {
        system("cls");
        cout << "Anda memiliki pinjaman aktif";
        Sleep(1500);
        minjem();
    }
    else if (input == 2 && user[user_sekarang].meminjam == "true") {
        cout << "\n\napakah anda ingin mengembalikan buku " << user[user_sekarang].judul << " ?(y/n): "; cin >> ya;
        if (ya == 'Y' || ya == 'y') {
            for (size_t i = 0; i < buku.size(); i++) {
                if (buku[i].judul == user[user_sekarang].judul) {
                   buku[i].tersedia == "true";
                }
            }
            user[user_sekarang].judul = " ";
            user[user_sekarang].meminjam = "false";
            rewrite();
        }
        system("cls");
        cout << "tunggu sebentar... kembali ke menu sebelumnya...";
        Sleep(1500);
        minjem();
    }
    else if (input == 2 && user[user_sekarang].meminjam == "false") {
        system("cls");
        cout << "Anda tidak memiliki pinjaman aktif";
        Sleep(1500);
        minjem();
    }
    else if (input == 3) {
        member();
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
    //cout << user_sekarang << "\n";
    cout << dashboardMember;
    move(29, 9);
    cin >> input;
    switch (input) {
        case 1:
            cari();
        break;
        case 2:
            minjem();
        break;
        case 3:
            main();
        break;

    }
}
