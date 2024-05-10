#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int ngitungspasi(string *ptr) {
    int jumlah;
    for (char karakter : *ptr) {
        if (karakter == ' ') {
            ++jumlah;
        }
    }
    return jumlah;
}


int main() {
    string kalimat;
    int spasi;
    cout << "Masukkan kalimat: "; getline(cin, kalimat);
    spasi = ngitungspasi(&kalimat);
    cout << "\n\nPada kalmat \n\"" << kalimat << "\"\nterdapat spasi sebanyak: " << spasi;
}
