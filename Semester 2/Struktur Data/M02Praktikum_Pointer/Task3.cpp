#include <iostream>
#include <algorithm> // Untuk std::sort

// Fungsi untuk mengurutkan array secara descending
void urutkanDescending(int* arr, int ukuran) {
    std::sort(arr, arr + ukuran, std::greater<int>());
}

// Fungsi untuk mencari nilai tertentu dalam array menggunakan pointer
bool cariNilai(const int* arr, int ukuran, int nilaiCari) {
    for (int i = 0; i < ukuran; i++) {
        if (*arr == nilaiCari) {
            return true; // Nilai ditemukan
        }
        arr++;
    }
    return false; // Nilai tidak ditemukan
}

int main() {
    const int ukuranArray = 5;
    int data[ukuranArray];

    // Memasukkan nilai ke dalam array
    std::cout << "Masukkan " << ukuranArray << " angka:\n";
    for (int i = 0; i < ukuranArray; i++) {
        std::cout << "Angka ke-" << i + 1 << ": ";
        std::cin >> data[i];
    }

    // Panggil fungsi untuk mengurutkan array secara descending
    urutkanDescending(data, ukuranArray);

    // Tampilkan array setelah diurutkan
    std::cout << "Array setelah diurutkan secara descending: ";
    for (int i = 0; i < ukuranArray; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    // Cari nilai tertentu dengan fasilitas pointer
    int nilaiCari;
    std::cout << "Masukkan nilai yang ingin dicari: ";
    std::cin >> nilaiCari;

    if (cariNilai(data, ukuranArray, nilaiCari)) {
        std::cout << "Nilai " << nilaiCari << " ditemukan dalam array.\n";
    } else {
        std::cout << "Nilai " << nilaiCari << " tidak ditemukan dalam array.\n";
    }

    return 0;
}
