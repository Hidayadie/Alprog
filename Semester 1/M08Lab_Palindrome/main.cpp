#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cout << "Pengecek kata Palindrome\nMasukkan kata atau kalimat: ";
    string kata; getline(cin, kata); string balik = kata;
    reverse(balik.begin(),balik.end());
    if (kata == balik) {
        cout << "\n\nKalimat yang anda masukkan merupakan kalimat palindrome\n"
             << "Kalimat:\t" << kata
             << "\nTerbalik:\t"<< balik;
    }
    else {
        cout << "\n\nKata yang anda masukkan bukan merupakan Palindrome\n"
             << "Kalimat:\t" << kata
             << "\nTerbalik:\t"<<balik;
    }
    cout << "\n\n";
}
