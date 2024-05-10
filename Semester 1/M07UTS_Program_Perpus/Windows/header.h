#include <string>
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
struct Buku {
    int index;
    string kode, judul, pengarang, jumHalaman, tersedia;
};
struct User {
    int index;
    string akses, nama, password, meminjam, judul;
};
string login =
    "============================================\n"
    "|   PROGRAM PEMINJAMAN BUKU PERPUSTAKAAN   |\n"
    "============================================\n"
    "|                                          |\n"
    "| 1. Login sebagai Admin                   |\n"
    "| 2. Login sebagai Member                  |\n"
    "| 0. Keluar                                |\n"
    "============================================\n"
    "| Masukan pilihan Anda        :            |\n"
    "============================================";
string loginAdmin =
    "====================================\n"
    "|           LOGIN ADMIN            |\n"
    "====================================\n"
    "|                                  |\n"
    "| Username        :                |\n"
    "| Password        :                |\n"
    "|                                  |\n"
    "====================================";
string loginMember =
    "====================================\n"
    "|           LOGIN MEMBER           |\n"
    "====================================\n"
    "|                                  |\n"
    "| Username        :                |\n"
    "| Password        :                |\n"
    "|                                  |\n"
    "====================================";
string dashboardAdmin =
    "====================================\n"
    "|         DASHBOARD ADMIN          |\n"
    "====================================\n"
    "|                                  |\n"
    "| 1. Input Buku                    |\n"
    "| 2. Edit Buku                     |\n"
    "| 3. Data Buku                     |\n"
    "| 4. Log Out                       |\n"
    "|                                  |\n"
    "====================================\n"
    "| Masukan pilihan anda      :      |\n"
    "====================================";
string inputBuku =
    "========================================================================\n"
    "|                               INPUT BUKU                             |\n"
    "========================================================================\n"
    "|                                                                      |\n"
    "| Masukan kode buku       :                                            |\n"
    "| Masukan judul buku      :                                            |\n"
    "| Masukan nama penggarang :                                            |\n"
    "| Masukan jumlah halaman  :                                            |\n"
    "|                                                                      |\n"
    "========================================================================";
string dataBuku =
    "===========================================\n"
    "|                DATA BUKU                |\n"
    "===========================================\n"
    "| kode |   Judul    |  Penggarang  |  hal |\n"
    "===========================================\n"
    "| xxxx |   Buku 1   |  Mr. X       |  xx  |\n"
    "| xxxx |   Buku 2   |  Mr. Y       |  xxx |\n"
    "| xxxx |   Buku 3   |  Mr. Z       |  xx  |\n"
    "| xxxx |   Buku 4   |  Mr. X       |  xx  |\n"
    "| xxxx |   Buku 5   |  Mr. Y       |  xxx |\n"
    "| xxxx |   Buku 6   |  Mr. Z       |  xx  |\n"
    "| xxxx |   Buku 7   |  Mr. X       |  xx  |\n"
    "| xxxx |   Buku 8   |  Mr. Y       |  xxx |\n"
    "===========================================";
string dashboardMember =
    "====================================\n"
    "|         DASHBOARD MEMBER         |\n"
    "====================================\n"
    "|                                  |\n"
    "| 1. Cari Buku                     |\n"
    "| 2. Peminjaman Buku               |\n"
    "| 3. Log Out                       |\n"
    "|                                  |\n"
    "====================================\n"
    "| Masukan pilihan anda      :      |\n"
    "====================================";

string peminjaman =
    "====================================\n"
    "|          MENU PEMINJAMAN         |\n"
    "====================================\n"
    "|                                  |\n"
    "|                                  |\n"
    "| 1. Pinjam Buku                   |\n"
    "| 2. Kembalikan Buku               |\n"
    "| 3. Exit                          |\n"
    "|                                  |\n"
    "====================================\n"
    "| Masukan pilihan anda      :      |\n"
    "====================================";


