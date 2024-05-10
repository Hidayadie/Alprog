#include <iostream>

using namespace std;

int main() {
    int arr[10];
    int kiri, kanan, tengah;
    int temp, key, n;
    bool ketemu = false;

    cout << "Masukkan jumlah data: "; cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Angka ke - ["<<i<<"]: "; cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);

			}
		}
	}

    cout << "Data yang telah diurutkan: \n";
    for (int i =0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "Masukkan angka yang dicari: "; cin >> key;
    kiri = 0;
    kanan = n-1;

    while (kiri <= kanan) {
        tengah = (kiri + kanan)/2;

        if (key == arr[tengah]) {
            ketemu = true;
            break;
        }
        else if (key < arr[tengah]) {
            kanan = tengah-1;
        }
        else {
            kiri = tengah +1;
        }
    }
    if (ketemu == true) {
        cout << "Angka ditemukan pada index ke " << tengah;
    }
    else {
        cout << "Ga ketemu";
    }
}
