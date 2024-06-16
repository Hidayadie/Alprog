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
using std::string;




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
        int jumlah          ; // jumlah sepatu itu sendiri
        string kondisi[100] ; // Implementasian stack berada pada
                              // string kondisi yang dimana setiap
                              // satuan sepatu memiliki kondisinya
                              // masing masing


        // Constructor untuk struct, mirip seperti class
        Stock() : jumlah(-1){};


        // fungsi dibawah pada make overload, jadinya bisa dilakuin
        // manual kayak .tambah() atau kalo mau 5 sekaligus .tambah(5)
        // yang kurang juga mirip, bisa 1 per 1 atau make .kurang(5)

        // fungsi tambah mirip seperti push
        // sedagkan untuk kurang adalah pop
        /*****************************************/
        //              fungsi tambah
        void tambah(string _kondisi) {
            jumlah++;
            kondisi[jumlah] = _kondisi;
        }

        void tambah(int berapa) {
            string _kondisi;
            if (berapa > 0) {
                for (int i = 0; i < berapa; i++) {
                    jumlah++;
                    cout << "Kondisi barang "<<i<<" : ";
                    getline(cin, _kondisi);
                    kondisi[jumlah] = _kondisi;
                }
            } else {
                cout << "Gunakan kurang() untuk mengurangi stok";
            }
        }

        /*****************************************/
        //              fungsi kurang
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
                jumlah = (jumlah < 0) ? -1 : jumlah;
            } else {
                cout << "Stok sudah kosong";
            }
        }

        /*****************************************/
        //              Fungsi cek
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
    //       merek      : Adiboss
    //       kategori   : Dewasa Laki
    //       nama       : Swift kasual
    //       jenis      : Sneakers
    //       harga      : 250.000
    //       stok       : 7
    /*
       sepatu[0].Merek__________= "Adiboss"
       sepatu[0].kategori_______= "Dewasa lk"
       sepatu[0].Nama___________= "Swift Kasual"
       sepatu[0].Jenis__________= "Sneakers"
       sepatu[0].harga__________= 250000
       sepatu[0].stok.jumlah____= 7

    */
    struct Sepatu {
        string Merek       ,   // Merek dari sepatu
               kategori    ,   // Kategori sepatu
               Nama        ,   // Nama sepatunya
               Jenis       ;   // Jenis (Sneakers, sport, dsb)
        int    Harga       ;   // Harga sepatunya
        Stock  stok        ;   // Stack buat jumlah stok
    };

    // cek nama =   sepatu[0].Nama
}



void _queue() {
    // fungsi queue digunakan sebagai antrian
    // preorder. Untuk preorder memiliki batasan
    // Antrian. Siapa cepat dia dapat.

    const int MAX = 25;   // jumlah stock yang tersedia

    struct Queue {
        int antrian             ;   // Antrian adalah jumlah orang yang ngantri
        string orderan[MAX]     ;   // Orderan itu implementasian queuenya sendiri
                                    // jadinya tiap antrian memiliki nama orang


        // Konstruktor struct queue
        Queue() : antrian(-1){}

        void enque() {
            if (antrian < MAX) {
                antrian++;
                cout << "Masukkan nama anda: ";
                getline(cin, orderan[antrian]);
            }
            else {
                cout << "Maaf, antrian sudah penuh";
            }
        }

        void deque() {
            if (antrian == -1) {
                cout << "Antrian kosong";
            } else {
                for (int i = 0; i <= antrian; i++) {
                    orderan[i] = orderan[i+1];
                }
                antrian--;
            }
        }
    };

}

void _sort() {
    // fungsi sort dapat digunakan sebagai
    // pengurutan baik secara abjad ataupun
    // urutan nomor seri


    struct Sepatu {
        string Nama;
    };

    Sepatu sepatu[5];
    sepatu[0].Nama = "Lorem";
    sepatu[1].Nama = "Apa";
    sepatu[2].Nama = "Apa";
    sepatu[3].Nama = "Apa";
    sepatu[4].Nama = "Apa";

    // demo sort secara abjad:


    // muales cik, kerjain sapa lah gitu
    // tinggal kopas kopas trus buat menunya nih
    // usahakan ngodingnya didalem fungsi _sort
    // aja yah, jangan edit" yang diluar dari ini

    // source code:
    // https://github.com/Hidayadie/Alprog/blob/main/Semester%202/Struktur%20Data/M06Praktikum_Sort/Tugas.cpp

}

void _search() {
    // fungsi search dipake buat mencari baik
    // nama, merek, ataupun bisa digabungkan
    // dengan sort untuk mencari filter harga
    // dengan range x - y

    struct Sepatu {
        string Nama;
    };

    // sama lah, kerjain sapa kek...

    // source code
    // https://github.com/Hidayadie/Alprog/blob/main/Semester%202/Struktur%20Data/M07Praktikum_Search/Task_Search.cpp
}

void _linked() {
    // linked dipake untuk keranjang belanja
    // kemungkinan yang bakal dipake double
    // linked list supaya mudah pengecekan
    // antara first dengan last

    struct Sepatu {
        string Nama;
    };

    // Linked list double list
    // Node bernama keranjang dan
    // setiap node menyimpang data yang
    // berupa sepatu

    struct keranjang {
        Sepatu      data    ;   // Data yang disimpan untuk setiap node
        keranjang   *next   ,   // Node next/selanjutnya
                    *prev   ;   // Node previous/sebelumnya
    };

    keranjang *kepala   ,   // Node paling awal
              *ekor     ,   // Node paling belakang
              *baru     ,   // Dipakai untuk membuat node baru
              *hapus    ;   // Dipakai untuk menghapus node

    /*
    void tambah_belakang(Sepatu dataBaru) {
        baru        = new keranjang;
        baru->data  = dataBaru;
        baru->next  = NULL;
        baru->prev  = NULL;

        if (kepala == NULL && ekor == NULL) {
            kepala          = baru;
            kepala->next    = NULL;
            kepala->prev    = NULL;
            ekor            = kepala;
        } else {
            ekor->next      = baru;
            baru->prev      = ekor;
            ekor            = baru;
        }
    }
    */
}

int main() {
    std::cerr << "tes";
}
