#include <iostream>

using namespace std;

struct Karyawan {
	int karyawanID;
	int umur;
	float gaji;

};

int main() {
    Karyawan joko, paijo;
	cout << "input data karyawan Joko\n"
		 << "========================\n"
		 << "  Id   : "; cin >> joko.karyawanID;
	cout << "  Umur : "; cin >> joko.umur;
	cout << "  Gaji : "; cin >> joko.gaji;
	cout << "\ninput data karyawan paijo\n"
		 << "========================\n"
		 << "  Id   : "; cin >> paijo.karyawanID;
	cout << "  Umur : "; cin >> paijo.umur;
	cout << "  Gaji : "; cin >> paijo.gaji;

	float total_gaji = joko.gaji + paijo.gaji;
	cout << "\nTotal gaji Joko dan Paijo: " << total_gaji << "\n";
}
