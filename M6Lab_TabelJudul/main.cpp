#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;

void biasa (), bertema();

int main() {
    char pilihan;
    cout << "\t\t+=-=-=-=-=-=-=-=-+\n"
         << "\t\t| Selamat Datang |\n"
         << "\t\t+=-=-=-=-=-=-=-=-+\n";
    sleep(1);
    cout << "\ndisini anda dapat membuat kotak \njudul(box) dengan kalimat anda sendiri"<<endl;
    sleep(1.5);
    cout << "\nApakah Anda ingin memilih tema atau langsung ingin membuatnya?"
         << "\n[Y/N]: "; cin>> pilihan;
         tolower(pilihan);
    if (pilihan == 'y') {
        bertema();}
    else {biasa();}
}
void biasa() {
    //cout <<"bilekapa";
    string judul;
    cout << "\nmasukkan judul anda: ";  cin.ignore(); getline(cin, judul);
    int panjang = judul.length();

    for (int i = 1; i <= 3; i++) {
        if (i == 1) {
            cout << "@";
            for (int b = 0; b < panjang+2; b++) {
                cout << "#";
            }
            cout << "@\n";
        }
        else if (i == 2) {
            cout << "# "<<judul<<" #\n";
        }
        else if (i == 3) {
            cout << "@";
            for (int b = 0; b < panjang+2; b++) {
                cout << "#";
            }
            cout << "@\n";
        }
    }
}


void bertema() {
cout<< "apbilek";}
