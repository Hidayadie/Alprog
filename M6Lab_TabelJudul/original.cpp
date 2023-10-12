#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;

void biasa (), bertema(), rahasia();

int main() {
    char pilihan;
    cout << "\t\t+=-=-=-=-=-=-=-=-+\n"
         << "\t\t| Selamat Datang |\n"
         << "\t\t+=-=-=-=-=-=-=-=-+\n";
    //sleep(1);
    cout << "\ndisini anda dapat membuat kotak \njudul(box) dengan kalimat anda sendiri"<<endl;
    //sleep(1.5);
    cout << "\nApakah Anda ingin memilih tema atau langsung ingin membuatnya?"
         << "\n [Yes]\tMenggunakan Tema memerlukan \"DOS Latin-US\" (CP-437)"
         << "\n [No]\tTanpa tema hanya menggunakan UTF-8"
         << "\n [H]\tUntuk mengecek karakter yang dapat anda gunakan"
         << "\n [Q]\tKeluar"
         << "\n\n[Y/N]: "; cin>> pilihan;
         tolower(pilihan);
    if (pilihan == 'y') {
        bertema();}
    else if (pilihan == 'n'){
        biasa();}
    else if (pilihan == 'h'){
        rahasia();}
    else if (pilihan == 'q'){
        return 0;}
}
void biasa() {
    system("clear");
    cout <<"Anda memilih tanpa tema"<<endl;
    string judul; char balik;
    cout << "\nmasukkan judul anda: ";  cin.ignore(); getline(cin, judul);
    int panjang = judul.length();
    cout << "kotak anda..."<<endl;
    for (int i = 1; i <= 3; i++) {
        if (i == 1) {
            cout << "\t\t+";
            for (int b = 0; b < panjang+2; b++) {
                cout << "-";
            }
            cout << "+\n";
        }
        else if (i == 2) {
            cout << "\t\t| "<<judul<<" |\n";
        }
        else if (i == 3) {
            cout << "\t\t+";
            for (int b = 0; b < panjang+2; b++) {
                cout << "-";
            }
            cout <<"+\n";
        }
    }
    cout << "apakah anda ingin mencoba coba tema lain?\n[Y/N]: "; cin >> balik;
    tolower(balik);
    if (balik == 'y') {
        system("clear");
        main();
    }
    else {
        cout << "\nTerimaksih telah mampir, Sampai Jumpa lagi...";
    }
}


void bertema() {
    system("clear");
    char pilihan;
    cout << "Anda memilih menggunakan tema...\nSilahkan pilih tema yang ingin anda pilih\n";
    char ataskiri,ataskanan,bawahkiri,bawahkanan,hori,verti;
    cout << "┌────────┐\t╒════════╕\t╔════════╗\n"
         << "│ Tema 1 │\t│ Tema 2 │\t║ Tema 3 ║\n"
         << "└────────┘\t╘════════╛\t╚════════╝\n"
         << "┏━━━━━━━━┓\t╓────────╖\t◆◆◆◆◆◆◆◆◆◆\n"
         << "┃ Tema 4 ┃\t║ Tema 5 ║\t◆ Tema 6 ◆\n"
         << "┗━━━━━━━━┛\t╙────────╜\t◆◆◆◆◆◆◆◆◆◆\n"
         << "☆☆☆☆☆☆☆☆☆☆\n"
         << "☆ Tema 7 ☆\n"
         << "☆☆☆☆☆☆☆☆☆☆\n";
    cout << "pilihan anda: ";
}


void rahasia() {
    for (int i = 0; i < 256; i++) {
    cout <<"ke - "<<i<<" "<< char(i)<<endl;
    }

}
