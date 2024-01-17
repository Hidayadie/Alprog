#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <fstream>
#include <iomanip>

using namespace std;
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
        }
};
class admin {

};
class member {

};


int main() {
    data_perpus buku;
    int pil;
    cin >> pil;

    if (pil == 1) {
        buku.tampilkan_data();
    }
    else if (pil == 2) {
        buku.tambah();
    }
    else if (pil == 3) {
        buku.edit();
    }
    //buku.tambah();
    //buku.tampilkan_data();
}
