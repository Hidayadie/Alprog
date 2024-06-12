#include <iostream>
#include <string>

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





void _pointer()             ,   // fungsi pointer
     _struct_dan_stack()    ,   // dipake buat data sepatu
     _queue()               ,   // antrian preorder
     _sort()                ,   // pengurutan abjad/angka
     _search()              ,   // fungsi cari
     _linked()              ;   // dipake buat item keranjang


void _pointer() {
    // fungsi pointer sendiri dipake
    // buat ngubah data secara referensi
    // bingung mau ditulis apa...
    // yang jelas kodenya ntar make
}



void _struct_dan_stack() {


    // Fungsi stack digunakan sebagai
    // jumlah stok sepatu yang tersedia
    //
    struct Stock {
        int jumlah = 0;
        string kondisi[20];


        Stock(int x = 0) : jumlah(x){};

        void tambah() {
            jumlah++;
        }

        void tambah(int berapa) {
            if (berapa > 0) {
                jumlah += berapa;
            } else {
                cout << "Gunakan kurang() untuk mengurangi stok";
            }
        }

        void kurang() {
            if (jumlah > 0) {
                jumlah--;
            } else {
                cout << "Stok sudah kosong";
            }
        }

        void kurang(int berapa) {
            if (jumlah > 0) {
                jumlah -= berapa;
            } else {
                cout << "Stok sudah kosong";
            }
        }

        void cekStok() {
            cout << jumlah;
        }
    };


    // Sedangkan untuk struct sepatu akan
    // direpresentasikan dengan id array
    // untuk setiap data sepatu ada data
    // nama,jenis,merek,harga, dan stok yang
    // dipake buat ngatur apakah ada atau enggak

    // (gapunya ide sih aku enaknya make apa, tapi ini ga disaranin banget)
    // make array buat sizenya, harusnya make vector
    // vector lebih fleksibel, bisa ditambah tambah
    // kalo array harus konstant, gabisa diubah ubah


    // conto: Sepatu sepatu[100]
    // conto: sepatu array 0 datanya;
    //
    //       merek  : Adiboss
    //       nama   : Swift kasual
    //       jenis  : Sneakers
    //       harga  : 250.000
    //       stok   : 7
    /*
       sepatu[0].Merek__________= "Adiboss"
       sepatu[0].Nama___________= "Swift Kasual"
       sepatu[0].Jenis__________= "Sneakers"
       sepatu[0].harga__________= 250000
       sepatu[0].stok.jumlah____= 7

    */
    struct Sepatu {
        std::string Merek   ,   // Merek dari sepatu
                    Nama    ,   // Nama sepatunya
                    Jenis   ;   // Jenis (Sneakers, sport, dsb)
        int         Harga   ;   // Harga sepatunya
        Stock       stok    ;   // Stack buat jumlah stok
    };
}



void _queue() {
    // fungsi queue digunakan sebagai antrian
    // preorder. Untuk preorder memiliki batasan
    // stok. Siapa cepat dia dapat, dan jika
    // stok sudah habis maka sisa queue tidak men-
    // dapatkan jatah dan dibuang

    const int stock     = 25;   // jumlah stock yang tersedia

    struct Queue {
        int depan       ,       // sebenernya ya.. depan tu ga guna
            belakang    ,       // belakang, jumlah yang ada di antrian
            data[stock] ;       // sama aja ga guna, masih kopas aku
                                // karna cuman ngitung perorangan udah bisa
                                // make belakang
    };

}

void _sort() {
    // fungsi sort dapat digunakan sebagai
    // pengurutan baik secara abjad ataupun
    // urutan nomor seri
}

void _search() {
    // fungsi search dipake buat mencari baik
    // nama, merek, ataupun bisa digabungkan
    // dengan sort untuk mencari filter harga
    // dengan range x - y
}

void _linked() {
    // linked dipake untuk keranjang belanja
    // kemungkinan yang bakal dipake double
    // linked list supaya mudah pengecekan
    // antara first dengan last
}

int main() {

}
