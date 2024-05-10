#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "\t+===================================================+\n"
         << "\t|  Selamat datang, disini saya akan mengecek nilai  |\n"
         << "\t|  yang anda input dan saya akan meng-output nilai  |\n"
         << "\t|  terbesarnya...                                   |\n"
         << "\t+===================================================+\n" << endl;
    cout << "Berapa kali anda ingin memasukkan nilai?\n"
         << "Anda akan ditanya sebanyak nilai yang anda masukkan: "; cin >> n;

    while(n <= 1) {
        cout << "tolong masukkan nilai yang valid (diatas 1)" << endl;
        cout << "pilih ulang: ";cin >> n;}
    int nilai[n];
    system("clear");
    cout << "anda akan diminta sebanyak " << n << " kali..." << endl;
    for (int i = 0; i < n; i++) {
    cout << "masukkan nilai ke - "<< i + 1<<" : "; cin >> nilai[i];}

    int nilaiTertinggi = nilai[0];
    int keberapaTingginya = 1;

    for (int i = 1; i < n; i++) {
        if (nilai[i] > nilaiTertinggi) {
            nilaiTertinggi = nilai[i];
            keberapaTingginya = i + 1;
        }
    }

    cout <<"\nnilai tertinggi berapa pada ke - "<< keberapaTingginya << " yang bernilai "<< nilaiTertinggi;


}
