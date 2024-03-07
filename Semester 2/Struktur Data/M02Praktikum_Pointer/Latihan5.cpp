#include <iostream>
#include <cstring>

using namespace std;

struct Mahasiswa {
    char npm[11];
    int nilai;
};

int main() {

    Mahasiswa mhs1;

    strcpy(mhs1.npm, "23.11.5757");
    mhs1.nilai = 99;

        cout << "Mahasiswa 1: "<< mhs1.npm << ", nilai: "<< mhs1.nilai << "\n\n";

    Mahasiswa *mhs2;
    mhs2 = &mhs1;

    strcpy(mhs2->npm, "30.11.5757");
    mhs2->nilai = 60;

    cout << "Mahasiswa 1: "<< mhs1.npm << ", nilai: "<< mhs1.nilai << "\n"
         << "Mahasiswa 2: "<< mhs2->npm << ", nilai: "<< mhs2->nilai;
}
