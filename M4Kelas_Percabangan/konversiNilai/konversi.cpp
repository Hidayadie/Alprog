#include <iostream>
#include <string>

using namespace std;

int main() {
    int nilai; char nilaiKonversi;
    string ucapan;
    cout << "selamat datang, disini saya akan mencetak skor anda kedalam bentuk nilai huruf.\nMasukkan nilai anda sebesar 0 - 100"<<endl;
    cout << "masukkan nilai anda: "; cin >> nilai;

    if      (nilai <= 100 && nilai >= 86) {
        nilaiKonversi = 'A';
        ucapan = "Selamat! Anda memperoleh nilai A, pertahankan nilai anda.";}
    else if (nilai <= 85  && nilai >= 66) {
        nilaiKonversi = 'B';
        ucapan = "Anda mendapatkan nilai B, tetap semangat!";}
    else if (nilai <= 65  && nilai >= 46) {
        nilaiKonversi = 'C';
        ucapan = "Anda memperoleh nilai C, teruslah berusahan dan lebih giat belajar!";}
    else if (nilai <= 45  && nilai >= 1 ) {
        nilaiKonversi = 'D';
        ucapan = "Anda mendapatkan nilai D, Terkadang keberhasilan itu perlu kegagalan,\njangan patah semangat...";}
    else if (nilai == 0) {
        nilaiKonversi = 'E';
        ucapan = "Mohon maaf, tetapi sepertinya anda tidak memiliki nilai, \ncobalah menghubungi pihak yang bersangkututan";}
    else {
        ucapan = "Mohon maaf nilai tidak valid";}

    cout <<"\n"<< ucapan;
}
