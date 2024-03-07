#include <iostream>

using namespace std;

int main() {
    int umur[] = {21,22,23,24,25};
	int *ptrX = umur;

	for (int i = 0; i < (sizeof(umur) / sizeof(umur[0])); i++) {
		cout << "Alamat umur[" << i <<"] = "<< &umur[i] << "\n";
	}

	cout << "\nNilai ptrUmur = "<< ptrX << " sama dengan alamat umur[0] " << &umur[0];
	ptrX += 3;
	cout << "\nNilai ptrUmur = "<< ptrX << " sama dengan alamat umur[0] " << &umur[3];
	ptrX -= 2;
	cout << "\nNilai ptrUmur = "<< ptrX << " sama dengan alamat umur[0] " << &umur[1];

}
