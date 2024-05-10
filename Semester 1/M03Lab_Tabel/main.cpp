#include <iostream>
#include <iomanip>

using namespace std;
int main() {
    cout << "+----+-------------------------+------+" <<endl;
    cout << "|" << setw(3)<<"No"<< " |" << setw(24)<<"Item" << " |" << setw(5) << "Qty"<< " |"<<endl;
    cout << "+----+-------------------------+------+" <<endl;
    cout << "|" << setw(3)<<"01"<< " |" << setw(24)<<"Buku Gambar" << " |" << setw(5) << "1"<< " |"<<endl;
    cout << "|" << setw(3)<<"02"<< " |" << setw(24)<<"Stabilo" << " |" << setw(5) << "2"<< " |"<<endl;
    cout << "|" << setw(3)<<"03"<< " |" << setw(24)<<"Peraut" << " |" << setw(5) << "1"<< " |"<<endl;
    cout << "|" << setw(3)<<"04"<< " |" << setw(24)<<"Pulpen" << " |" << setw(5) << "4"<< " |"<<endl;
    cout << "|" << setw(3)<<"05"<< " |" << setw(24)<<"Tinta Printer" << " |" << setw(5) << "1"<< " |"<<endl;
    cout << "|" << setw(3)<<"06"<< " |" << setw(24)<<"Pensil 2B" << " |" << setw(5) << "2"<< " |"<<endl;
    cout << "+----+-------------------------+------+" <<endl;
    cout << "|" << setw(3)<<""<< " |" << setw(24)<<"Total" << " |" << setw(5) << "11"<< " |"<<endl;
    cout << "+----+-------------------------+------+" <<endl;
}
