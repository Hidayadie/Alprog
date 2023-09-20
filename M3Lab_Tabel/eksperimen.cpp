#include <iostream>
#include <iomanip>

using namespace std;
void kasirTes(), cumaTes();
int main() {
    char pilihan;
    cout << "\t+===================================================+" << endl;
    cout << "\t|                                                   |" << endl;
    cout << "\t|           Selamat datang di Toko Saya!            |" << endl;
    cout << "\t|___________________________________________________|" << endl;
    cout << "\t| Silahkan masukkan pilihan anda pada sesuai dengan |" << endl;
    cout << "\t|             Item yang anda ingin beli             |" << endl;
    cout << "\t|___________________________________________________|" << endl;
    cout << "\t| No |    Nama barang     |  Stok  |      Harga     |" << endl;
    cout << "\t|----+--------------------+--------+----------------|" << endl;
    cout << "\t| 01 | Buku cerita        |  004   |   Rp. 20.000   |" << endl;
    cout << "\t| 02 | Buku tulis         |  010   |   Rp. 10.000   |" << endl;
    cout << "\t| 03 | Pulpen             |  020   |   Rp. 2.500    |" << endl;
    cout << "\t| 04 | Pensil             |  020   |   Rp. 2.000    |" << endl;
    cout << "\t| 05 | Penghapus          |  015   |   Rp. 1.500    |" << endl;
    cout << "\t| 06 | Peraut             |  009   |   Rp. 1.000    |" << endl;
    cout << "\t| 07 | Kertas manila      |  050   |   Rp. 15.000   |" << endl;
    cout << "\t| 08 | Kertas origami     |  025   |   Rp. 10.000   |" << endl;
    cout << "\t+===================================================+" << endl;
    cout << "\t|       'X' Keluar              'G' Kembali         |" << endl;
    cout << "\t+===================================================+" << endl;
    cout << "\tPilihan anda: "; cin >> pilihan;
}
