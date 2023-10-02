#include <iostream>

using namespace std;

int main() {
int bilangan;
bool prima = true;
cout << "\t\t+===========================+\n"
     << "\t\t|      Selamat datang       |\n"
     << "\t\t| Disini anda akan mengecek |\n"
     << "\t\t| apakah bilangan yang anda |\n"
     << "\t\t| masukan merupakan prima / |\n"
     << "\t\t| bukan prima               |\n"
     << "\t\t+===========================+\n\n"
     //<< "ketik '1' jika sudah selesai.\n"
     << "Bilangan: "; cin >> bilangan;

if (bilangan <= 0) {
    cout << "masukkan bilangan bulat positif diatas 0: ";cin >> bilangan;}
else if (bilangan == 1) {
    cout << "1 bukan bilangan prima, bilangan: "; cin >> bilangan;}
else {
    for (int i = 2; i <= bilangan / 2; i++) {
        if (bilangan % i == 0) {
            prima = false;
    }
}
}
if (prima == true) {
    cout << "bilangan "<< bilangan<< " adalah bilangan prima";}
else {
    cout << "bilangan "<< bilangan<< " bukan bilangan prima\n\n" << bilangan<<" dapat dibagi dengan: \n";
        for (int i = 2; i <= bilangan / 2; i++) {
        if (bilangan % i == 0) {
            cout << i <<" ";}
        } cout << "dan bilangan itu sendiri ("<<bilangan<<")";
}
cout << "\n\n";
}
