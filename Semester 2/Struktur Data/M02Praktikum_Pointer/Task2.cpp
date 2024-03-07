#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void awal(char* ptr) {
    if (ptr && *ptr) {
        *ptr = toupper(*ptr);
    }
}
void besar(char* ptr) {
    while (*ptr) {
        *ptr = toupper(*ptr);
        ptr++;
    }
}
void kecil(char* ptr) {
    while (*ptr) {
        *ptr = tolower(*ptr);
        ptr++;
    }
}

int main() {
    const int mentok = 100;
    char kalimat[mentok];

    cout << "Masukkan kalimat: ";
    cin.getline(kalimat, mentok);
    awal(kalimat);
    cout << "Huruf pertama menjadi huruf besar: " << kalimat << endl;
    besar(kalimat);
    cout << "Semua huruf menjadi huruf besar: " << kalimat << endl;
    kecil(kalimat);
    cout << "Semua huruf menjadi huruf kecil: " << kalimat << endl;

}

