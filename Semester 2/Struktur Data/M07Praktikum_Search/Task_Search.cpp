#include <iostream>
#include <string>

using namespace std;

int main() {

    int n, kiri, kanan, tengah;
    cout << "Masukkan jumlah data: "; cin >> n;
    string arr[n], key;
    bool ketemu = false;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "Nama ke - ["<<i<<"]: "; getline(cin, arr[i]);
        //cin.ignore();
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
        cout << arr[i] << "\n";
    }
    //cin.ignore();
    cout << "\nMasukkan Nama yang dicari: "; getline(cin, key);
    //key = "Malik";
    kiri = 0;
    kanan = n-1;

    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;

        if (key == arr[tengah]) {
            ketemu = true;
            cout << "\nNama ditemukan pada index ke " << tengah;
            break;
        }
        else if (key < arr[tengah]) {
            kanan = tengah - 1;
        }
        else {
            kiri = tengah + 1;
        }
    }

    if (!ketemu) {
        cout << "\nGa ketemu";
    }
}
