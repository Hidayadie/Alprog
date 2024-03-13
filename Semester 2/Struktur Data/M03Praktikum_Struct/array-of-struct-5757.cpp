#include <iostream>
#include <string>

using namespace std;
struct Mahasiswa{
	string npm, nama, alamat;
	float ipk;
	int tahunMasuk;
};

int main() {
int jumlahMahasiswa;
	cout << 	"Jumlah mahasiswa yang ingin diinputkan : "; cin >> jumlahMahasiswa;
	cout << endl;
	Mahasiswa mhs[jumlahMahasiswa];
	cin.ignore();
	for (int i = 0; i < jumlahMahasiswa; i++)
	{
		cout << "Data Mahasiswa ke #" << (i+1) << endl;
		cout << " NPM : "; getline(cin, mhs[i].npm);
		cout << " Nama : "; getline(cin, mhs[i].nama);
		cout << " Alamat : "; getline(cin, mhs[i].alamat);
		cout << " Tahun Masuk :"; cin >> mhs[i].tahunMasuk;
		cout << " IPK : "; cin >> mhs[i].ipk; cin.ignore();
		cout << endl;
	}
	cout << endl;
	
	// menampilkan data mahasiswa yg sudah diinputkan
	cout << "Laporan Data Mahasiswa" << endl;
	cout << "======================" << endl;
	for (int i = 0; i < jumlahMahasiswa; i++)
	
	{
		cout << "No. #" << (i+1) << endl;
		cout << " NPM : " << mhs[i].npm << endl;
		cout << " Nama : " << mhs[i].nama << endl;
		cout << " Alamat : "<< mhs[i].alamat << endl;
		cout << " Tahun Masuk: " << mhs[i].tahunMasuk << endl;
		cout << " IPK : " << mhs[i].ipk << endl;
		cout << endl << endl;
	}
	
	system("pause");
	return 0;
}
