/*
            BACA DULU KALO MAU MAKE

    kalo semisal eror system("clear") not found atau apalah,
    diubah jadi system("cls"). Soalnya ya, aku makenya bukan
    Windows.

    Kalo ada eror" lagi/bingung tanyain ajah
    discord : hytrin
    no      : 085602254537



*/




#include <iostream>
#include <string>

using namespace std;

const int max_stack = 5;

struct Stack {

	int top;
	string data[max_stack];
};

void init(), push(), pop(), clear(), print();
bool isEmpty(), isFull();

Stack stack;


int main() {
	init();
	int pilihanMenu;


	do {
		system("clear");
		cout << ">>> Menu pilihan <<<\n\n"
			 << "1. Menambah item stack\n"
			 << "2. Menghapus item stack\n"
			 << "3. Menampilkan item stack\n"
			 << "4. Mengosongkan stack\n"
			 << "5. Selesai\n" << endl;
		cout << "Pilihan: "; cin >> pilihanMenu; cin.ignore();
		//cout << endl;

		switch (pilihanMenu) {
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				print();
				break;
			case 4:
				clear();
				break;
		}

	} while (pilihanMenu != 5);

	cout << endl;

}

void init() {
	stack.top = -1;
}

void push() {

	if (stack.top < max_stack - 1) {
		stack.top++;
		cout << "menambah data: ";
        getline(cin, stack.data[stack.top]);
		cout << "Data berhasil ditambah\n\n";

	}
	else {
		cout << "Stack sudah penuh!!\n";
	}
	cout << "\nTekan enter untuk lanjut...";
	getchar();

}

void pop() {
    if (!isEmpty()) {
        cout << "data " << stack.data[stack.top] << " sudah dihapus\n\n";
        stack.data[stack.top] = "";
        stack.top--;

    } else {
        cout << "\nStack kosong, tidak ada yang bisa dihapus";
    }
        cout << "\nTekan enter untuk lanjut...";
        getchar();
}

void clear() {
    system("clear");
    for (int i = 0; i < max_stack; i++) {
		stack.data[i] = "";
	}
	stack.top = -1;
	cout << "Stack sudah dikosongkan\n"
         << "\nTekan enter kembali...";
	getchar();
}

bool isEmpty() {
	return (stack.top == -1);
}

bool isFull() {
	return (stack.top >= (max_stack -1));
}

void print() {
    system("clear");
    cout << "sisa size = ["<< stack.top +1<<"/"<<max_stack<<"] ";
    if (isFull()) {
        cout << "Stack sudah penuh!";
    } else {
        cout << "Stack belum penuh";
    }

	cout << "\nIsi stack:" << endl;
	for (int i = max_stack - 1; i >= 0; i--) {
		cout <<"- " << stack.data[i] << endl;
	}

    cout << "\nTekan enter untuk kembali...";
	getchar();
}
