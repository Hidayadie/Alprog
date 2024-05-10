#include <iostream>
#include <algorithm>

using namespace std;

void nurun(int *data, int ukuran) {
    sort(data, data + ukuran, greater<int>());
}
void naik(int *data, int ukuran) {
    sort(data, data + ukuran, less<int>());
}

bool cari(int *data, int ukuran, int target) {
    for (int i = 0; i < ukuran; i++) {
        if (*data == target) {
            return true;
        }
    }
    return false;
}



int main() {
    int ukuran;
    cout << "Masukkan ukuran aray: "; cin >> ukuran;
    int data[ukuran];
    for (int i = 0; i < ukuran; i++) {
        cout << "Masukkan nilai ke - " << i + 1 << " : "; cin >> data[i];
    }

    naik(data, ukuran);
    cout << "\nArray setelah diurutkan secara ascending...\n\"";
    for (int i = 0; i < ukuran; i++) {
        cout << data[i] << " ";
    }
    cout << "\"";

    nurun(data, ukuran);
    cout << "\nArray setelah diurutkan secara descending...\n\"";
    for (int i = 0; i < ukuran; i++) {
        cout << data[i] << " ";
    }
    cout << "\"";
    int target;
    cout << "\nMasukkan nilai yang ingin dicari: ";
    cin >> target;

    if (cari(data, ukuran, target)) {
        cout << "\nNilai " << target << " ditemukan dalam array.\n";
    } else {
        cout << "\nNilai " << target << " tidak ditemukan dalam array.\n";
    }

    return 0;
}
