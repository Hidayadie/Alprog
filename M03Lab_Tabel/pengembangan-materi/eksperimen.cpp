#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

//membuat struck/struktur (seperti class)
struct Barang {
    string nama;
    double harga;
};

int main() {
    srand(time(0));

    // Barang yang tersedia di toko
    Barang daftarBarang[] = {
        {"Buku cerita", 20000},
        {"Buku tulis", 10000},
        {"Pulpen", 2500},
        {"Pensil", 2000},
        {"Penghapus", 1500},
        {"Peraut", 1000},
        {"Kertas manila", 15000},
        {"Kertas origami", 10000},
        {"Buku gambar", 10000},
        {"Buku cacah", 7500}
    };

    int jumlahTipeBarang = rand() % 10 + 1;  // Randomizer berapa barang yang akan dibeli (1-10)
    int jenisBarangTerpilih[10] = {0};       // Menyimpan memori jika belum pernah terpilih maka akan bernilai 0, (cek bawah)
    int belanjaan[10];                       // Untuk menyimpan tipe barang yang dibeli
    int jumlahBeli[10];                      // Untuk menyimpan jumlah yang dibeli

    for (int i = 0; i < jumlahTipeBarang; i++) {    // Kode untuk memilih barang mana yang akan dibeli secara acak
        int index;
        do {
            index = rand() % 10;                    // Memilih barang yang mana yang akan dibeli dari gudang toko
        } while (jenisBarangTerpilih[index] == 1);  // Ngulangin kalo sebelumny udah dipilih

        jenisBarangTerpilih[index] = 1;             // Update nilai jadi 1 biar ga kepilih lagi sama while diatasny
        belanjaan[i] = index;                       // Belanjaan ke brp...
        jumlahBeli[i] = rand() % 10 + 1;            // Jumlah yang akan dibeli (1-10)
    }

    double totalHarga = 0.0;    // Buat hasil akhir
    int totalBeli = 0;          // Buat hasil akhir jg

    // Tampilan akhir
    cout << "\t+===========================================+" << endl;
    cout << "\t|           Tabel Hasil Belanja             |" << endl;
    cout << "\t+===========================================+" << endl;
    cout << "\t| No |   Nama Barang   | Jumlah |   Harga   |" << endl;
    cout << "\t+-------------------------------------------+" << endl;

    for (int i = 0; i < jumlahTipeBarang; i++) {            // nge print(cout) isi tabel secara berulang ulang
        int index = belanjaan[i];                           // Menyimpan memori tentang barang yang dibeli ke-...
        int jumlah = jumlahBeli[i];                         // Menyimpan memori tentang jumlah pembeliannya pada ke-...
        double harga = daftarBarang[index].harga * jumlah;  // Jumlah harga barang yang dibeli dikalikan banyaknya Ia membeli
        totalHarga += harga;                                // Menghitung jumlah harga
        totalBeli += jumlahBeli[i];                         // Menghitung jumlah barang yang dibelu

        cout << "\t| " << setw(2) << i + 1 << " | " << setw(15) << daftarBarang[index].nama << " | " << setw(6) << jumlah << " | " << setw(9) << harga << " |" << endl;
    }

    cout << "\t+===========================================+" << endl;
    cout << "\t|\tTotal: " <<setw(10)<<" | "<<setw(6)<<totalBeli<<" | "<<setw(9)<< totalHarga << " |" << endl;
    cout << "\t+===========================================+" << endl;

    return 0;
}

