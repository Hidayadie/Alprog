#include <iostream>
#include <iomanip>

using namespace std;
void kasirTes(), cumaTes();


struct Barang {
    string nama;
    double harga;
    int stok;};

int main() {
     const int MAX_BARANG = 5;
    Barang daftarBarang[MAX_BARANG];


    daftarBarang[0] = {"Pensil", 0.5, 100};
    daftarBarang[1] = {"Buku", 2.5, 50};
    daftarBarang[2] = {"Pensil Warna", 1.0, 75};
    daftarBarang[3] = {"Penghapus", 0.3, 200};
    daftarBarang[4] = {"Pensil 2B", 0.6, 150};

    while (true) {
        cout << "=== Toko Barang ===" << endl;
        cout << "Pilih barang yang ingin dibeli (0 untuk keluar):" << endl;
        for (int i = 0; i < MAX_BARANG; i++) {
            cout << i + 1 << ". " << daftarBarang[i].nama << " - Harga: " << daftarBarang[i].harga << " - Stok: " << daftarBarang[i].stok << endl;
        }

        int pilihan;
        cin >> pilihan;

        if (pilihan == 0) {
            break;
        } else if (pilihan >= 1 && pilihan <= MAX_BARANG) {
            int index = pilihan - 1;
            cout << "Anda memilih " << daftarBarang[index].nama << " - Harga: " << daftarBarang[index].harga << " - Stok: " << daftarBarang[index].stok << endl;

            int jumlah;
            cout << "Masukkan jumlah yang ingin dibeli: ";
            cin >> jumlah;

            if (jumlah <= 0 || jumlah > daftarBarang[index].stok) {
                cout << "Jumlah tidak valid atau stok tidak cukup." << endl;
            } else {
                double totalHarga = jumlah * daftarBarang[index].harga;
                daftarBarang[index].stok -= jumlah;
                cout << "Total Harga: " << totalHarga << endl;
                cout << "Terima kasih telah berbelanja di toko kami!" << endl;
            }
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    }
    return 0;
}
