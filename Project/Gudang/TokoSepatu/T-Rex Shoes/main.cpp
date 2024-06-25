#include "database.h"
#include "Katalog.h"
#include "Pencarian.h"

#define bersih "\033[2J \033[1;1H"
using namespace std;

int main() {
    database();
    cout << jumlahSepatu << " Terimput...";
    Program();
}

void Program() {

    getchar();
    do {
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
        << "Pilihan Anda: "; cin >> pil;
        cin.ignore();

        switch (pil) {
            case 1:

            case 2:
                Katalog();
            break;
            case 3:
                Pencarian(sepatu, jumlahSepatu, "Air");
            break;
            case 5:
                return;
            break;
        }


    } while (true);
}



void pencarian() {
    string key;
    cout << "Silahkan input nama yang ingin dicari...\n"
         << "-> "; getline(cin, key);


}

void Keranjang() {


}
