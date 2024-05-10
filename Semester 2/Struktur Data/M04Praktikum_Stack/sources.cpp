#include <iostream>

using namespace std;

const int max_stack = 5;

struct Stack {
	
	int top;
	int data[max_stack];
};

void init(), push(int data), pop(), clear(), print();
bool isEmpty(), isFull();

Stack stack;


int main() {
	
	init();
	int pilihanMenu, data;
	
	do {
		system("cls");
		cout << ">>> Menu pilihan <<<\n\n"
			 << "1. Menambah item stack\n"
			 << "2. Menghapus item stack\n"
			 << "3. Menampilkan item stack\n"
			 << "4. Mengosongkan stack\n"
			 << "5. Selesai\n\n"
			 << "sisa size = ["<< stack.top +1<<"/"<<max_stack<<"]\n"
			 << "Pilihan: "; cin >> pilihanMenu;
		cout << endl;
		
		switch (pilihanMenu) {
			case 1:
				push(data);
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

void push(int data) {
	if (stack.top < max_stack - 1) {
		cout << "menambah data: "; cin >> data;
		stack.top++;
		stack.data[stack.top] = data;
		cout << "Data berhasil ditambah\n\n";
		
	}
	else {
		cout << "Stack sudah penuh!!\n";
	}
	system("pause");
	
}

void pop() {
	cout << "data " << stack.data[stack.top] << " sudah dihapus\n\n";
	system("pause");
}

void clear() {
	stack.top = -1;
	cout << "Stack sudah dikosongkan\n\n";
	system("pause");
}

bool isEmpty() {
	return (stack.top == -1);
}

bool isFull() {
	return (stack.top >= (max_stack -1));
}

void print() {
	cout << "Isi stack: \n\n";
	for (int i = stack.top; i >= 0; i--) {
		cout << stack.data[i] << endl;
	}
	system("pause");
}
