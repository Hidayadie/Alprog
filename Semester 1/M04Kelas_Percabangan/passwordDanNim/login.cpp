#include <iostream>
#include <string>

using namespace std;

int main() {
string nama, nim;

cout << "\t+==============================+\n"
     << "\t|        Selamat Datang        |\n"
     << "\t|  Silahkan masukkan nama dan  |\n"
     << "\t|         Password Anda        |\n"
     << "\t+==============================+\n";
cout << "\tNama : "; getline(cin, nama);
cout << "\tNim  : "; cin >> nim;

if (nama == "Hidayadie" || nama == "hidayadie") {
    if (nim == "23.11.5757") {
    //system("clear");
    //system("cls");
    cout << "\tSelamat Datang!";}
    else {
    //system("clear");
    //system("cls");
    cout << "\tNomor nim Anda salah atau tidak terdaftar";}
    }
else {
    cout << "\n\tData Anda tidak ditemukan...\n\n";}
return 0;
}
