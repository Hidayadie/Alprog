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

int  pilihan        ;
void tokoSepatu()   ,
     Dashboard()    ,
     Katalog()      ,
     Keranjang()    ,
     Profil()       ,
     Hub()          ,
     Costumer()     ;

void Dashboard() {
    cout << bersih
         << "\tSELAMAT DATANG               \n"
         << "Silahkan masukkan pilihan Anda \n"
         << "1. Katalog Barang              \n"
         << "2. Keranjang                   \n"
         << "3. Profil                      \n"
         << "4. Pengaturan preferensi       \n"
         << "5. Keluar                      \n"
         << "Pilihan Anda: ";
}

void Katalog() {
    cout << bersih
         << "\tKATALOG\n"
         << "Disini anda dapat mencari\n"
         << "Sepatu yang Anda inginkan\n\n"
         << "Pastikan ejaan nama sepatu, Merek, ataupun jenisnya benar...\n"
         << "cari: ";

    getchar();
    cout << bersih
         << "Hasil Pencarian untuk\n"
         << "\"Adiboss\"\n"
         << "1. Adiboss Gaskann, Sneakers, Rp 350.000\n"
         << "2. Adiboss Sporty, Sport, Rp 450.000\n"
         << "3. Adiboss Swift, Sneakers, Rp 217.750\n"
         << "4. Adiboss Champ, Football, Rp 615.500";
    getchar();
}

void Keranjang() {
    cout << bersih
         << "\tKERANJANG\n"
         << "isi Keranjang Anda,\n\n"
         << "1. Naiki Casual, Sneakers, Rp 215.000\n"
         << "2. Konvera Entera, Loafers, RP 314.000";
    getchar();
}

void Profil() {
    cout << bersih
         << "\tPROFIL\n"
         << "Nama: Adolf Churchill Roosevelt\n"
         << "Domisili: Kayangan\n\n"
         << "Alamat: Jl. Nusa Keren, no.123, kec Amomo, kab Yahelu, Kayangan";

    getchar();
}

void Hub() {
    cout << bersih
         << "\tTENTANG KAMI"
         << "Jika Anda memiliki pertanyaan atau pengajuan\n"
         << "Silahkan menghubungi kontak yang ada dibawah ini\n"
         << "telp: 09123456789\n"
         << "email: sepatumu@sepatu.co.id";

    getchar();
}
void tokoSepatu() {
    do {
        Dashboard();
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1:
                Katalog();
            break;
            case 2:
                Keranjang();
            break;
            case 3:
                Profil();
            break;
            case 4:
                Hub();
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

int main () {
    cout << "Program toko sepatu sederhana...\n"
         << "kalau semisal disuruh ngetik apa\n"
         << "Tekan enter aja";

    getchar();
    tokoSepatu();

}
