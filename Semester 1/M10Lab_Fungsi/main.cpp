#include <iostream>
#include <string>
using namespace std;

string Hex(int desimal) {
    string hasil = "";
    char kode;
    if (desimal == 0) {
        return "0";
    }
    else {
        while (desimal > 0) {
            int sisa = desimal % 16;
            if (sisa < 10) {
                kode = '0' + sisa;
            }
            else {
                kode = 'A' + sisa - 10;
            }
            hasil = kode + hasil;
            desimal /= 16;
        }
    }
    return hasil;
}

int main() {
    int nilai;
    cout << "Selamat datang di konverter Desimal ke\n"
         << "Hexadesimal, silahkan masukkan angka..\n\n"
         << "Masukkan nilai desimalnya: "; cin >> nilai;
    string hasil = Hex(nilai);
    cout << "Hasil konversinya adalah:  " << hasil << endl;

    return 0;
}
