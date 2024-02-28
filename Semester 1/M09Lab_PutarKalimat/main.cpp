#include <iostream>
#include <string>

using namespace std;

int main() {
    string kalimatInput;
    cout << "Selamat Datang di pemutar kalimat!\n"
         << "Anda dapat memutar balikan kalimat\n\n"
         << "Masukkan kalimat: ";
         getline(cin, kalimatInput);
    string kata, kalimatTerputar;
    for (char karakter : kalimatInput) {
        if (karakter == ' ') {
            kalimatTerputar = kata + " " + kalimatTerputar;
            kata = "";
        } else {
            kata += karakter;
        }
    }
    kalimatTerputar = kata + " " + kalimatTerputar;
    cout << "Kalimat Terputar: " << kalimatTerputar << "\n";
}
