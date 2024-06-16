#include <iostream>

#define bersih "\033[2J \033[1;1H"
#define Hitam "\e[0;30m"
#define Merah "\e[0;31m"
#define Hijau "\e[0;32m"
#define Kuning "\e[0;33m"
#define Biru "\e[0;34m"
#define Ungu "\e[0;35m"
#define BiruMuda "\e[0;36m"
#define Putih "\e[0;37m"


using std::cout;
using std::cin;

int  pilihan;
void tokoSepatu(),
Dashboard(),
Katalog(),
Keranjang(),
Profil(),
Pencarian(),
Costumer();

void Dashboard() {
    cout << bersih
        << "+-------------------------------+\n"
        << "|         SELAMAT DATANG        |\n"
        << "+-------------------------------+\n"
        << "|Silahkan masukkan pilihan Anda |\n"
        << "+-------------------------------+\n"
        << "|1. Profil                      |\n"
        << "|2. Katalog Barang              |\n"
        << "|3. Pencarian                   |\n"
        << "|4. Keranjang                   |\n"
        << "|5. Keluar                      |\n"
        << "+-------------------------------+\n"
        << "Pilihan Anda: ";
}

void Katalog() {
    cout << bersih
        << "+-------------------------------------+\n"
        << "|                KATALOG              |\n"
        << "+-------------------------------------+\n"
        << "| Selamat datang di katalog, terdapat |\n"
        << "| Banyak pilihan sepatu disini...     |\n"
        << "+-------------------------------------+\n"
        << "| 1. Sepatu Dewasa lk                 |\n"
        << "| 2. Sepatu Dewasa pr                 |\n"
        << "| 3. Sepatu Dewasa bebas              |\n"
        << "| 4. Sepatu Anak lk                   |\n"
        << "| 5. Sepatu Anak pr                   |\n"
        << "| 6. Sepatu Anak bebas                |\n"
        << "+-------------------------------------+\n"
        << "cari: ";

    getchar();
}

void Keranjang() {
    cout << bersih
        << "+--------------------------------------------+\n"
        << "|                   KERANJANG                |\n"
        << "+--+-----------------+----------+------------+\n"
        << "|no|    Nama         |  Jenis   |    Harga   |\n"
        << "+--+-----------------+----------+------------+\n"
        << "|1 | Naiki Casual    | Sneakers | Rp 215.000 |\n"
        << "|2 | Konvera Entera  | Loafers  | RP 314.000 |\n"
        << "+--+-----------------+----------+------------+\n"
        << "|                       Total:    Rp 529.000 |\n"
        << "+--------------------------------------------+";
    getchar();
}

void Profil() {
    cout << bersih
        << "+---------------------------------------------------------------+\n"
        << "|                         Tentang Kami                          |\n"
        << "+---------------------------------------------------------------+\n"
        << "| Trex Shoes CLI, adalah toko sepatu berbasis TUI yang kami     |\n"
        << "| Kembangkan sepenuh hati untuk anda yang ingin berbelanja      |\n"
        << "| Sepatu secara minimalis melalui Terminal.                     |\n"
        << "+---------------------------------------------------------------+\n"
        << "|                          ---=+=---                            |\n"
        << "| Keluhan dan saran silahkan menghubungi kontak kami dibawah    |\n"
        << "| Telp  +62 8123456789                                          |\n"
        << "| Email sepatu_t-rex@rawrrr.co.id                               |\n"
        << "| Jl. Nusa Keren, no.123, kec Amomo, kab Yahelu, Kayangan       |\n"
        << "+---------------------------------------------------------------+";


    getchar();
}

void Pencarian() {
    cout << bersih
        << "+--------------------------------------------+\n"
        << "|    Hasil Pencarian untuk \"Adiboss\"         |\n"
        << "+--+-----------------+----------+------------+\n"
        << "|no|    Nama         |  Jenis   |    Harga   |\n"
        << "+--+-----------------+----------+------------+\n"
        << "|1 | Adiboss Gaskann | Sneakers | Rp 350.000 |\n"
        << "|2 | Adiboss Sporty  | Sport    | Rp 450.000 |\n"
        << "|3 | Adiboss Swift   | Sneakers | Rp 217.750 |\n"
        << "|4 | Adiboss Champ   | Football | Rp 615.500 |\n"
        << "+--------------------------------------------+";
    getchar();
}

void tokoSepatu() {
    do {
        Dashboard();
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
        case 1:
            Profil();
            break;
        case 2:
            Katalog();
            break;
        case 3:
            Pencarian();
            break;
        case 4:
            Keranjang();
            break;
        case 5:
            return;
            break;
        default:
            cout << "Pilihan tidak valid";
            getchar();

            break;
        }
    } while (pilihan != 5);
}

int main() {
    tokoSepatu();

}
