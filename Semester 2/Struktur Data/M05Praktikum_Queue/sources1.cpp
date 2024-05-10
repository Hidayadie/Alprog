#include <iostream>

using namespace std;

const int Max = 5;

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
		system("cls");
		cout << ">>> PILIHAN MENU <<<\n"
			 << "1. Tambah\n"
			 << "2. Hapus\n"
			 << "3. Print\n"
			 << "4. Kosongkan\n"
			 << "5. Keluar\n"
			 << "\n -> "; cin >> pil;
		
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
				cout << "pilihan g ad... ketuk enter untuk kembali";
		}
	} while (pil != 5); 
}

void init() {
	queue.depan = queue.belakang = -1;
}

void enque() {
	int data;
	cout << "Data yang ingin ditambah = "; cin >> data;
	queue.depan = 0;
	queue.belakang++;
	queue.data[queue.belakang] = data;
	cout << "Data ok.\n\n";
	system("pause");
}

void deque() {
	cout << "Data "<< queue.data[queue.depan] << " dihapus\n\n";
	for (int i = queue.depan; i <= queue.belakang; i++) {
		queue.data[i] = queue.data[i + 1];
	}
	queue.belakang--;
	system("pause");
}

void clear() {
	queue.depan = queue.belakang = -1;
	cout << "Kosong\n\n";
	system("pause");
}

void print() {
	cout << "isi: ";
	for (int i = queue.depan; i <= queue.belakang; i++) {
		cout << queue.data[i] << " ";
	}
	cout << "\n\n";
	system("pause");
}
