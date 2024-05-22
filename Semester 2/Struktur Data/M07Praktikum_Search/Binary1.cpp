#include <iostream>

using namespace std;

int main() {
    int arr[] = {6, 15, 20, 25, 30, 45, 50, 75, 80, 95};
    int kiri, kanan, tengah;
    int temp, key, n = sizeof(arr)/sizeof(arr[0]);
    bool ketemu = false;

    //cout << "Masukkan jumlah data: "; cin >> n;
    /*
    for (int i = 0; i < n; i++) {
        cout << "Angka ke - ["<<i<<"]: "; cin >> arr[i];
    }*/
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);

			}
		}
	}

    cout << "\nData yang telah diurutkan: \n";
    for (int i =0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nMasukkan angka yang dicari: "; cin >> key;
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
        cout << "Angka ditemukan di index " << tengah;
    }
    else {
        cout << "Ga ketemu";
    }
}
