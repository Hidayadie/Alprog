#include <iostream>

using namespace std;

int main() {
    int nilai[] = {20,10,40,80,70,50,30,60,100,75,85};

    int n = sizeof(nilai)/sizeof(int);

    cout << "Isi array: \n";
    for (int i = 0; i < n; i++) {
        cout << nilai[i] << " ";
    }
    int cari = 0;
    cout << "\nmasukkan nilai search : "; cin >> cari;

    bool ketemu = false;

    int index;
    for (int index = 0; index < n; index++) {
        if (cari == nilai[index]) {
            ketemu = true;
            break;
        }
    }

    cout << "\n" << ((ketemu) ? "Data ditemukan" : "Data tidak ditemukan");
}
