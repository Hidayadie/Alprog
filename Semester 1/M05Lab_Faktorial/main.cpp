#include <iostream>

using namespace std;

int main() {
cout << "\t+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n"
     << "\t|         Selamat Datang        |\n"
     << "\t|                               |\n"
     << "\t|  Disini anda bisa menghitung  |\n"
     << "\t|  hasil dari suatu faktorial/  |\n"
     << "\t|  (!) bilangan.                |\n"
     << "\t|  contoh: 5! = 5x4x3x2x1 = 120 |\n"
     << "\t+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n";
bool ngitung = true;
while (ngitung) {
int bilangan, hasil = 1; char jawaban;
cout << "\nmasukkan bilangan: ";cin>> bilangan;
for (int i = 1; i <= bilangan; i++) {
    hasil *= i;}
cout <<"faktorial dari " << bilangan << " adalah "<<hasil
     <<"\n\nApakah anda ingin menghitung lagi? (y/n): "; cin>> jawaban;
ngitung = false;
if (jawaban == 'y' || jawaban == 'Y') {
    ngitung = true;}
    }
}
