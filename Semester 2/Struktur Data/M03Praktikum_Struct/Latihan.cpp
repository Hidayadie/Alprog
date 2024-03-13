#include <iostream>

using namespace std;

void latihan1(), latihan2();

struct Karyawan {
	int karyawanID;
	int umur;
	float gaji;
	
};

int main() {
	short pilihan;
	cout << "Source kode ke - "; cin >> pilihan;
	switch (pilihan) {
		case 1:
			system("cls");
			latihan1();
			break;
		case 2:
			system("cls");
			latihan2();
			break;
	}
	
}


void latihan1() {
	
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

void latihan2() {
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
