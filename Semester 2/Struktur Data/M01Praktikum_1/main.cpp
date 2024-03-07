// Header sama namespace //
#include <iostream>
using namespace std;


// Cetak biru //
//void printArray();
int minArray(int aray[], int *), maxArray(int aray[], int *);


// Fungsi utama //
int main() {
    int ukuran;
    cout << "Size array: "; cin >> ukuran;
    int aray[ukuran];                       // Menggunakan ukuran input langsung tanpa menggunakan sizeof()/int()
    for (int i = 0; i < ukuran; i++) {
        cout << "Masukkan nilai array ke - " << i+1 << " : "; cin >> aray[i];
    }
    cout << "\n";
    //system("clear");                      // Biar rapi
    cout << "Nilai aray: ";
    for (const auto& i : aray) {            // Memakai loop for each biar keren hehe
        cout << i << " ";
    }
    cout << "\nNilai minimum: "<< minArray(aray, &ukuran)
         << "\nNilai maximum: "<< maxArray(aray, &ukuran);
}

// Fungsib b4 lain //

int minArray(int aray[], int *ukuran) {
    int kecil = aray[0];
    for (int i = 0; i < *ukuran; i++) {
        if (kecil > aray[i]) {
            kecil = aray[i];
        }
    }
    return kecil;
}

int maxArray(int aray[], int *ukuran) {
    int besar = aray[0];
    for (int i = 0; i < *ukuran; i++) {
        if (besar < aray[i]) {
            besar = aray[i];
        }
    }
    return besar;
}

