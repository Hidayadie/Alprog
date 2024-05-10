#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <fstream>
#include <iomanip>

using namespace std;
string user_sekarang = "Tamu";
class data_perpus {
    public:
        struct Buku {
            int index;
            string kode, judul, pengarang, jumHalaman, tersedia;
        };
        vector<Buku> buku;
        data_perpus() {

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
                    buku.push_back(buku_baru);
                    index++;
                }
            file.close();
            }
            else {
                cout << "Gagal membuka file Buku" << endl;
            }
        }
        void tampilkan_data() {
            system("clear");
            ifstream file("databuku.txt");
            if (file.is_open()) {
                cout << "no, kode, judul, pengarang, jumhal, tersedia";
                for (size_t i = 0; i < buku.size(); i++) {
                        cout << left
                             << buku[i].index <<", "
                             << buku[i].kode  <<", "
                             << buku[i].judul <<", "
                             << buku[i].pengarang << ", "
                             << buku[i].jumHalaman << ", "
                             << buku[i].tersedia << "\n";
                }
                cout << "\n";
                file.close();
            }
             else {
                cout << "Gagal membuka file." << endl;
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
                cout << "kode: "; getline(cin, buku_baru.kode);
                cout << "judul: "; getline(cin, buku_baru.judul);
                cout << "author: "; getline(cin, buku_baru.pengarang);
                cout << "hal: "; getline(cin, buku_baru.jumHalaman);
                char save;
                cout << "save? (y/n): "; cin >> save;
                switch (save) {
                    case 'y':
                        file << buku_baru.kode << ',' << buku_baru.judul << ',' << buku_baru.pengarang << ',' << buku_baru.jumHalaman << ',' << "true\n";
                        buku_baru.index = index;
                        buku.push_back(buku_baru);
                    break;
                }
                file.close();
            }
            else {
                cout << "error ngab";
            }
        }
        void edit() {
            system("clear");
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
        }
        void update() {
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
};

class client {
    public:
        struct User {
            int index;
            string akses, nama, password, meminjam, judul;
        };
        string name,pw;
        vector<User> user;

        client() {
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
        }
        void buat_akun() {
            string kompw;
            cout << "Nama: ";
            getline(cin, name);
            cout << "Password: ";
            getline(cin, pw);
            cout << "Konfirmasi Password: ";
            getline(cin, kompw);
            if (pw == kompw) {
                cout << "user baru: \"" << name <<"\" berhasil dibuat dengan password: \"" << pw <<"\"\n";
                ofstream file("datauser.txt", ios::app);
                file << "member,"<< name << ','<<pw<<",false,\n";
                update();
            }

        }
        string login() {

            //system("clear");
            cout << "Nama: ";
            getline(cin, name);
            if (name == "0") {
                system("clear");
                buat_akun();
            }

            else if (name != "0"){
                for (size_t i = 0; i < user.size(); i++) {
                    if (user[i].nama == name) {
                        cout << "password " << name << ": ";
                        getline(cin, pw);
                        if (pw == user[i].password) {
                            return name;
                        }
                    }
                }
            }
            else {
                cout << "Tidak dapat menemukan username, silahkan coba ulang atau periksa typo\n";
                return "Tamu";
            }

            return "Tamu";
        }
        void update() {
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
        }
};


int main() {
    data_perpus buku;
    client pengguna;

    cout << "Perpusku CLI, silahkan login terlebih dahulu untuk melanjutkan\n"
         << "Jika anda belum memiliki akun, masukkan 0 pada input nama\n"
         << "ketik \\help untuk list perintah\n"
         << "--------------------------------------------------------------\n\n";
    //pengguna.login();
    string prompt;
    do {
        cout <<"["<< user_sekarang << "] > ";
        getline(cin, prompt);
        if (prompt == "clear") {
            system("clear");
        }
        else if (prompt == "login") {
            user_sekarang = pengguna.login();
        }
        else if (prompt == "update") {
            pengguna.update();
        }

    } while (prompt != "q");


}
