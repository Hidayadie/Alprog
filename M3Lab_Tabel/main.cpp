#include <iostream>
#include <iomanip>

using namespace std;
void kasirTes(), kosongan();
int main() {
    cout << "+----+-------------------------+------+" <<endl;
    cout << "|" << setw(3)<<"No"<< " |" << setw(24)<<"Item" << " |" << setw(5) << "Qty"<< " |"<<endl;
    cout << "+----+-------------------------+------+" <<endl;
    cout << "|" << setw(3)<<"01"<< " |" << setw(24)<<"Buku cerita" << " |" << setw(5) << "1"<< " |"<<endl;
    cout << "|" << setw(3)<<"02"<< " |" << setw(24)<<"Pulpen" << " |" << setw(5) << "2"<< " |"<<endl;
    cout << "|" << setw(3)<<"03"<< " |" << setw(24)<<"Peraut pensil" << " |" << setw(5) << "1"<< " |"<<endl;
    cout << "|" << setw(3)<<"04"<< " |" << setw(24)<<"Kertas manila" << " |" << setw(5) << "4"<< " |"<<endl;
    cout << "|" << setw(3)<<"05"<< " |" << setw(24)<<"Penghapus" << " |" << setw(5) << "1"<< " |"<<endl;
    cout << "+----+-------------------------+------+" <<endl;
    cout << "|" << setw(3)<<""<< " |" << setw(24)<<"Total" << " |" << setw(5) << "9"<< " |"<<endl;
    cout << "+----+-------------------------+------+" <<endl;
}

void kasirTes() {
        cout << "\t+===================================================+" << endl;
        cout << "\t|                                                   |" << endl;
        cout << "\t|           Selamat datang di Toko Saya!            |" << endl;
        cout << "\t|___________________________________________________|" << endl;
        cout << "\t| Silahkan masukkan pilihan anda pada sesuai dengan |" << endl;
        cout << "\t|             Item yang anda ingin beli             |" << endl;
        cout << "\t|                                                   |" << endl;
        cout << "\t|                                                   |" << endl;
        cout << "\t|                                                   |" << endl;
        cout << "\t+===================================================+" << endl;
        cout << "\t|       'X' Keluar              'G' Kembali         |" << endl;
        cout << "\t+===================================================+" << endl;
}
