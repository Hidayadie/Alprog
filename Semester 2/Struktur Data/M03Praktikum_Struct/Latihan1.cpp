#include <iostream>

using namespace std;

struct Karyawan {
	int karyawanID;
	int umur;
	float gaji;

};

int main() {
	Karyawan joko;
	joko.karyawanID = 10;
	joko.umur = 25;
	joko.gaji = 24.15;
	Karyawan paijo;
	paijo.karyawanID = 11;
	paijo.umur = 26;
	paijo.gaji = 28.23;
	float total_gaji = joko.gaji + paijo.gaji;
	cout << "Total gaji Joko dan Paijo: " << total_gaji << "\n";
	if ( paijo.gaji > joko.gaji) {
		cout << "gaji Paijo lebih besar daripada Joko\n";
	}
	joko.gaji += 2.5;
	cout << "Gaji Joko setelah kenaikan gaji: "<< joko.gaji << "\n\n";
}
