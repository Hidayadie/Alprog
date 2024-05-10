#include <iostream>

using namespace std;
struct Mahasiswa {
    char npm[11];
    char nama[30];
    char alamat[100];
    float ipk;
};
int main() { // input jumlah mahasiswa
    int jumlahMahasiswa;
    cout << "Jumlah mahasiswa yang ingin diinputkan : "; cin >> jumlahMahasiswa;
    cout << endl;
    Mahasiswa mhs[jumlahMahasiswa];
    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        cout << "Data Mahasiswa ke #" << (i+1) << endl;
        cout << " NPM : "; cin >> mhs[i].npm;
        cout << " Nama : "; cin >> mhs[i].nama;
        cout << " Alamat : "; cin >> mhs[i].alamat;
        cout << " IPK : "; cin >> mhs[i].ipk;
        cout << endl;
    }
    cout << endl;
    cout << "Laporan Data Mahasiswa" << endl;
    cout << "======================" << endl;
    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        cout << "No. #" << (i+1) << endl;
        cout << " NPM : " << mhs[i].npm << endl;
        cout << " Nama : " << mhs[i].nama << endl;
        cout << " Alamat : "<< mhs[i].alamat << endl;
        cout << " IPK : " << mhs[i].ipk << endl;
        cout << endl << endl;
    }
    system("pause");
    return 0;
}
