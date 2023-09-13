#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main() {
int pilihan; bool ngitung = true;
while (ngitung) {
cout << "\t+=======================================================+" << endl;
cout << "\t|       Selamat datang di perhitungan segitiga          |" << endl;
cout << "\t|   disini anda dapat menghitung panjang sisi segitiga  |" <<endl;
cout << "\t+=================+=====================================+" <<endl;
cout << "\t|                 |                                     |" << endl;
cout << "\t|   |\\            | Silahkan pilih sisi mana yang ingin |" << endl;
cout << "\t|   | \\           | Anda cari:                          |" << endl;
cout << "\t|   |  \\          |  pilih 1 - 3                        |" << endl;
cout << "\t| a |   \\ c       |   1. sisi a (sisi tinggi)           |" << endl;
cout << "\t|   |    \\        |   2. sisi b (sisi alas)             |" << endl;
cout << "\t|   |     \\       |   3. sisi c (sisi panjang)          |" << endl;
cout << "\t|   |______\\      |                                     |" << endl;
cout << "\t|       b         |                                     |" <<endl;
cout << "\t+=================+=====================================+" <<endl;
cout << "\nmasukkan pilihan anda (contoh: 3): ";
cin >> pilihan;
int a, b ,c;
float hasil; char balik;
//\033[31mMerah\033[0m"
switch (pilihan) {
    case 1:
        ngitung = false;
        cout << "\nAnda akan mencari panjang sisi a (sisi tinggi)."<< endl;
        cout << "masukkan nilai sisi c: "; cin >> c;
        cout << "masukkan nilai sisi b: "; cin >> b;
        hasil = sqrt(pow(c,2) - pow(b, 2));
        cout << "panjang sisi a yang didapat adalah: " << hasil << endl;
        cout << "\napakah Anda ingin menghitung sisi yang lain (kembali?) [Y/n]: "; cin >> balik;
        balik = tolower(balik);
        if (balik == 'y') {system("clear"); ngitung = true;}
        else {return 0;}
    break;
    case 2:
        ngitung = false;
        cout << "\nAnda akan mencari panjang sisi b (sisi alas)."<< endl;
        cout << "masukkan nilai sisi c: "; cin >> c;
        cout << "masukkan nilai sisi a: "; cin >> a;
        hasil = sqrt(pow(c,2) - pow(a, 2));
        cout << "panjang sisi b yang didapat adalah: " << hasil << endl;
        cout << "\napakah Anda ingin menghitung sisi yang lain (kembali?) [Y/n]: "; cin >> balik;
        balik = tolower(balik);
        if (balik == 'y') {system("clear"); ngitung = true;}
        else {return 0;}
    break;
    case 3:
        ngitung = false;
        cout << "\nAnda akan mencari panjang sisi c (sisi panjang)."<< endl;
        cout << "masukkan nilai sisi a: "; cin >> a;
        cout << "masukkan nilai sisi b: "; cin >> b;
        hasil = sqrt(pow(a,2) + pow(b, 2));
        cout << "panjang sisi c yang didapat adalah: " << hasil << endl;
        cout << "\napakah Anda ingin menghitung sisi yang lain (kembali?) [Y/n]: "; cin >> balik;
        balik = tolower(balik);
        if (balik == 'y') {system("clear"); ngitung = true;}
        else {return 0;}
    break;
    default:
    /*
    hilangkan komen (//) dibawah ini agar kode bekerja dengan lebih rapi.
    Jika menggunakan windows maka hilangkan // pada cls
    Jika menggunakan unix/linux hilangkan // pada clear
    */
        //system("clear");
        //system("cls");
        cout << "\t\033[31m Pilihan tidak valid, tolong pilih ulang dengan benar...\033[0m"<< endl;
        break;
}}

}

