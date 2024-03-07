#include <iostream>

using namespace std;

int main() {
    char kalimat[] = "Universitas AMIKOM";
    int panjang = sizeof(kalimat)/sizeof(char);
    cout << "Kalimat, ";
    for (int i = 0; i < panjang; i++) {
        cout << kalimat[i];
    }
    cout << " dibalik menjadi, ";
    for (int i = panjang; i >= 0; i--) {
        cout << kalimat[i];
    }
}
