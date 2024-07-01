#include <iostream>
#include <iomanip>
#include <fstream>

#define bersih "\033[2J \033[1;1H"
using namespace std;

void Program()          ,
     database()         ,
     Katalog()          ,
     _Katalog_Cetak(int pilihan)   ;

const int MAX_ISI = 30;
int pil, jumlahSepatu = 0;
struct Stock {
        int jumlah          ; // jumlah sepatu itu sendiri
        string kondisi[100] ; // Implementasian stack berada pada
                              // string kondisi yang dimana setiap
                              // satuan sepatu memiliki kondisinya
                              // masing masing
};

struct Sepatu {
        string ID          ,
               Merek       ,   // Merek dari sepatu
               kategori    ,   // Kategori sepatu
               Nama        ,   // Nama sepatunya
               Jenis       ;   // Jenis (Sneakers, sport, dsb)
        int    Harga       ;   // Harga sepatunya
        Stock  stok        ;   // Stack buat jumlah stok
};

Sepatu sepatu[MAX_ISI];
void database() {
    ifstream fileSepatu("database.txt");
    if (fileSepatu.is_open()) {
        cout << "200 ok";
        string _ID          ,
               _Merek       ,   // Merek dari sepatu
               _kategori    ,   // Kategori sepatu
               _Nama        ,   // Nama sepatunya
               _Jenis       ;   // Jenis (Sneakers, sport, dsb)
        int    _Harga       ,   // Harga sepatunya
               _stok        ;   // Stack buat jumlah stok


        string temp;
        while (getline(fileSepatu, _ID      ,   ',')) {
               getline(fileSepatu, _Merek   ,   ',');
               getline(fileSepatu, _kategori,   ',');
               getline(fileSepatu, _Nama    ,   ',');
               getline(fileSepatu, _Jenis   ,   ',');
               getline(fileSepatu, temp     ,   ','); _Harga = stoi(temp);
               getline(fileSepatu, temp            ); _stok  = stoi(temp);

               sepatu[jumlahSepatu].ID          =   _ID      ;
               sepatu[jumlahSepatu].Merek       =   _Merek   ;
               sepatu[jumlahSepatu].kategori    =   _kategori;
               sepatu[jumlahSepatu].Nama        =   _Nama    ;
               sepatu[jumlahSepatu].Jenis       =   _Jenis   ;
               sepatu[jumlahSepatu].Harga       =   _Harga   ;
               sepatu[jumlahSepatu].stok.jumlah =   _stok    ;
               jumlahSepatu++;
        }

    } else {
        cout << "not ok";
    }
}


void tes() {
    for (int i = 0; i < jumlahSepatu; i++) {
        cout << sepatu[i].ID << ", " << sepatu[i].Nama;
    }
    getchar();
}

int main() {

    Program();
}

void Program() {
    database();
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
            case 2:
                Katalog();
            break;

            case 5:
                return;
            break;
            case 6:
                tes();
                getchar();
            break;
        }


    } while (true);
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
        << "pilih (0 kembali): ";
        cin >> pil;
        cin.ignore();
        switch (pil) {
            case 0:
                return;
            break;
            case 1:
                _Katalog_Cetak(1);
            break;
            case 2:
                _Katalog_Cetak(2);
            break;
            case 3:
                _Katalog_Cetak(3);
            break;
            case 4:

            break;
        }
}

void _Katalog_Cetak(int pilihan) {
    string pencarian, target;
    switch (pilihan) {
        case 1:
            pencarian = "Dewasa Laki-laki";
        break;
        case 2:
            pencarian = "Dewasa Perempuan";
        break;
        case 3:
            pencarian = "Dewasa";
        break;
    }


    // cetak tabel

    cout << bersih
         << "+--------------------------------------------------------------+\n"
         << "|" <<setw(17)<< "Menampilkan " <<left<<setw(20) << pencarian <<right<< setw(27) << "|\n"
         << "+----+-----------+--------------------+------------+-----------+\n"
         << "| ID | Merek     | Nama               | Jenis      | Harga     |\n"
         << "+----+-----------+--------------------+------------+-----------+\n"
         << left;
    // cari sepatu yang sama
    for (int i = 0; i < jumlahSepatu; i++) {
        if (pencarian == "Dewasa") {
            if (sepatu[i].kategori == "Dewasa Perempuan" || sepatu[i].kategori == "Dewasa Laki-laki" ){
            cout << "| "
                 << setw(3) << sepatu[i].ID     << "| "
                 << setw(10) << sepatu[i].Merek  << "| "
                 << setw(19)<< sepatu[i].Nama   << "| "
                 << setw(11)<< sepatu[i].Jenis  << "| "
                 << setw(10) << sepatu[i].Harga  << "|\n";
            }
        } else if (sepatu[i].kategori == pencarian) {
            cout << "|"
                 << setw(4) << sepatu[i].ID     << "| "
                 << setw(10) << sepatu[i].Merek  << "| "
                 << setw(19)<< sepatu[i].Nama   << "| "
                 << setw(11)<< sepatu[i].Jenis  << "| "
                 << setw(10) << sepatu[i].Harga  << "|\n";

        }
    }
    cout << "+----+-----------+--------------------+------------+-----------+";
    getchar();
}
