#include <iostream>
//#include <conio.h>
#define Merah "\033[31m"
#define Hitam "\033[0m"
#define Hijau "\033[32m"
#define Biru "\033[34m"

using namespace std;

const int Max = 3;

struct Queue {
	int depan, belakang, data[Max];
};
Queue queue;

void init(), deque(), enque(), clear(), print();
bool isEmpty(), isFull();

int main () {
	init();
	int pil;
	do {
		system("clear");
		cout << Hitam;
		cout << ">>> PILIHAN MENU <<<\n"
			 << "1. Tambah\n"
			 << "2. Hapus\n"
			 << "3. Print\n"
			 << "4. Kosongkan\n"
			 << "5. Keluar\n";
		cout << "Sisa size: " << (queue.belakang + 1 == Max ? Merah : Hijau) << queue.belakang + 1 << "/" << Max <<"\n";
		cout << (queue.belakang + 1 == Max ? Merah : Hijau) << (queue.belakang + 1 == Max ? "Queue Sudah Penuh!!!" : "Queue masih tersedia...");
		cout << Hitam << "\n -> "; cin >> pil;
        cin.ignore();
		switch (pil) {
			case 1:
				enque();
				break;
			case 2:
				deque();
				break;
			case 3:
				print();
				break;
			case 4:
				clear();
				break;
			case 5:
				continue;
				break;
			default:

				cout << Merah << "\n\npilihan g ad... \n"<< Hitam <<"Enter untuk kembali";
				getchar();
		}
	} while (pil != 5);
}

void init() {
	queue.depan = queue.belakang = -1;
}

void enque() {
	if (!isFull()) {
		int data;
		cout << "Data yang ingin ditambah = "; cin >> data; cin.ignore();
		queue.depan = 0;
		queue.belakang++;
		queue.data[queue.belakang] = data;
		cout << "Data ok.\n\n";

	}
	else {
		cout << Merah << "Queue Penuh!\n" << Hitam;
	}
	cout << Biru << "Ketuk enter untuk kembali..." << Hitam;
	getchar();
}

void deque() {
	cout << "Data "<< queue.data[queue.depan] << " dihapus\n\n";
	for (int i = queue.depan; i <= queue.belakang; i++) {
		queue.data[i] = queue.data[i + 1];
	}
	queue.belakang--;
	cout << Biru << "Ketuk enter untuk kembali..." << Hitam;
	getchar();
}

void clear() {
	queue.depan = queue.belakang = -1;
	cout << "Kosong\n\n";
	cout << Biru << "Ketuk enter untuk kembali..." << Hitam;
	getchar();
}

void print() {
	cout << "isi: ";
	for (int i = queue.depan; i <= queue.belakang; i++) {
		cout << queue.data[i] << " ";
	}
	cout << "\n\n";
	cout << Biru << "Ketuk enter untuk kembali..." << Hitam;
	getchar();
}

bool isEmpty() {
	return (queue.belakang == -1);
}

bool isFull() {
	return (queue.belakang >= (Max -1));
}
