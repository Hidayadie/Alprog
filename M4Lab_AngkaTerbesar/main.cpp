#include <iostream>

using namespace std;

int main() {
int a,b,c,d;
cout << "Selamat datang, disini saya akan mengecek nilai\n"
     << "yang anda input dan saya akan meng-output nilai\n"
     << "terbesarnya..., Anda diminta untuk memasukkan 4\n"
     << "nilai yang berbeda.\n" << endl;

cout << "Masukkan nilai pertama : "; cin >> a;
cout << "Masukkan nilai kedua   : "; cin >> b;
cout << "Masukkan nilai ketiga  : "; cin >> c;
cout << "Masukkan nilai keempat : "; cin >> d;
cout << endl;


if      (a == b || a == c || a == d || b == c || b == d || c == d) {
    cout << "Peringatan!, terdapat angka yang sama...\n" << endl;}

if      (a > b && a > c && a > d) {
    cout << "nilai yang paling besar adalah nilai pertama yaitu "<< a;}
else if (b > a && b > c && b > d) {
    cout << "nilai yang paling besar adalah nilai kedua yaitu "<< b;}
else if (c > a && c > b && c > d) {
    cout << "nilai yang paling besar adalah nilai ketiga yaitu "<< c;}
else if (d > a && d > b && d > c) {
    cout << "nilai yang paling besar adalah nilai keempat yaitu "<< d;}
cout << endl;
return 0;
}
