#include <iostream>
#include <string>


using namespace std;

struct Buku
{
    string halaman  ,
           judul    ,
           pengarang;
};

struct Queue
{
    int depan       ,
        belakang    ;
    Buku buku[10]   ;

    Queue() : depan(-1), belakang(-1){}
} kuiwi;

bool isFull() {
    return (kuiwi.belakang == 9);
}

bool isEmpty() {
    return (kuiwi.belakang == -1);
}

void tambahAntrianBiasa() {
    if (!isFull()) {
        kuiwi.depan = 0;
        kuiwi.belakang++;
        cout << "Penambahan data baru...\n";
        string judul,
               Pengarang,
               halaman;
        cout << "Judul Buku baru: ";
        getline(cin, judul);
        cout << "Nama pengarang " << judul <<"\n: ";
        getline(cin, Pengarang);
        cout << "Jumlah halaman " << judul << ": ";
        getline(cin, halaman);
        //cin.ignore();
        kuiwi.buku[kuiwi.belakang].judul        = judul;
        kuiwi.buku[kuiwi.belakang].pengarang    = Pengarang;
        kuiwi.buku[kuiwi.belakang].halaman      = halaman;
        cout << "Data berhasil ditambahkan...\n";
        getchar();
    } else {
        cout << "Data sudah maksimal";
        getchar();
    }
}

void kurangiAntrian() {
    if (isEmpty()) {
        cout << "Data kosong";
    } else {
        for (int i = 0; i <= kuiwi.belakang; i++) {
            kuiwi.buku[i].halaman   = kuiwi.buku[i+1].halaman;
            kuiwi.buku[i].judul   = kuiwi.buku[i+1].judul;
            kuiwi.buku[i].pengarang   = kuiwi.buku[i+1].pengarang;
        }
        kuiwi.belakang--;
        cout << "data berhasil dikurangi";
        getchar();
    }
}

void cetakData() {
    if (isEmpty()) {
        cout << "Data kosong...";
    } else {
        for (int i = 0; i <= kuiwi.belakang; i++) {
            cout << "Data " << i+1 << "\n"
                 << "Judul:     "<<kuiwi.buku[i].judul << "\n"
                 << "Pengarang: "<<kuiwi.buku[i].pengarang << "\n"
                 << "Jml Hal:   "<<kuiwi.buku[i].halaman << "\n\n";
        }
        getchar();
    }
}

void tambahke() {
    if (kuiwi.belakang + 1 != 10) {
        int brp;
        cout << "Penambahan data baru...\n"
             << "Penambahan secara spesial dengan\n"
             << "menambahkannya ditengah tengah atau depan\n\n"
             << "Jumlah data saat ini (bukan index)...\n";
             if (kuiwi.belakang == -1) {
                cout << "0, Data belum ada";
             } else {
                cout << kuiwi.belakang + 1;
             }
             //<< ": " <<((kuiwi.belakang == -1) ? "0, belum ada data" : kuiwi.belakang) << "\n"
        cout << "\nPenambahan pada data ke - ";cin >> brp;
        cin.ignore();
        if (brp <= 0) {
            cout << "tdk bisa...";
            getchar();
            return;
        } else if ((kuiwi.belakang + 1) < brp) {
            cout << "Gunakan tambah antrian!";
            getchar();
            return;
        }
        string judul,
               Pengarang,
               halaman;
        cout << "Judul Buku baru: ";
        getline(cin, judul);
        cout << "Nama pengarang " << judul <<"\n: ";
        getline(cin, Pengarang);
        cout << "Jumlah halaman " << judul << ": ";
        getline(cin, halaman);

        kuiwi.belakang++;
        for (int i = kuiwi.belakang; i >= brp; i--) {
            kuiwi.buku[i].halaman   = kuiwi.buku[i-1].halaman;
            kuiwi.buku[i].judul     = kuiwi.buku[i-1].judul;
            kuiwi.buku[i].pengarang = kuiwi.buku[i-1].pengarang;
        }

        kuiwi.buku[brp-1].judul = judul;
        kuiwi.buku[brp-1].pengarang = Pengarang;
        kuiwi.buku[brp-1].halaman = halaman;
    }
}

int main () {
    int pil;
    do {
        system("clear");
        cout << "pilih\n"
             << "1. Tambah\n"
             << "2. Kurang\n"
             << "3. Cetak\n"
             << "4. tambah ke...\n"
             << "-> "; cin >> pil;
             cin.ignore();
        switch (pil) {
            case 1:
                tambahAntrianBiasa();
            break;
            case 2:
                kurangiAntrian();
            break;
            case 3:
                cetakData();
            break;
            case 4:
                tambahke();
            break;
        }

    } while (pil != 0);

}

