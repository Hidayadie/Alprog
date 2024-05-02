#include <iostream>

using namespace std;

int main() {
    int ukuran;
    cout << "Jumlah ukuran array: "; cin >> ukuran;
    int nilai[ukuran];
    for (int i = 0; i < ukuran; i++) {
        cout << "masukkan nilai ke "<<i +1<<" : "; cin >> nilai[i];
    }

    int cari = 0;
    cout << "\nmasukkan nilai search : "; cin >> cari;

    bool ketemu = false;

    int index = -1;
    for (int i = 0; i < ukuran; i++) {
        if (cari == nilai[i]) {
            index = i;
            ketemu = true;
            break;
        }
    }

    if (ketemu) {
        cout << "Data ditemukan pada index ke "<< index;
    }
    else {
        cout << "Data tidak ditemukan";
    }
}
