#include <iostream>

#include <iostream>
#include <string>
#define Merah "\033[31m"
#define Kuning "\033[33m"
#define Hijau "\033[32m"
#define Biru "\033[34m"
#define Hitam "\033[0m"

using namespace std;

struct Node {
	int data;
	Node *next, *prev;
};

Node *head, *tail, *print, *del, *newNode;

bool isEmpty();
void insertNode(int data);
void deleteFromFront();
void printNode();

int main () {
	
	int pilihan;
	int data;
    
    while (true)
    {
    	system("cls");
        cout << Merah << ">>> PILIHAN MENU DOUBLE LINKED LIST <<<" << Hitam
			 << "\n"
        	 << "1. Menambah Node\n" 
        	 << "2. Menghapus Node dari depan\n" 
        	 << "3. Menampilkan\n" 
       		 << "4. Selesai";
        
        cout << std::endl;
        
        cout << "Masukkan Pilihan anda: "; std::cin >> pilihan;
       
        std::cin.ignore();
        switch (pilihan)
        {
            case 1:
                cout << "Masukkan data: "; std::cin >> data;
                insertNode(data);
                break;
            case 2:
                deleteFromFront();
                break;
            case 3:
                //deleteFromFront();
                printNode();
				break;
            case 4:
                return 0;
                break;
            default:
                cout << "Pilihan tidak valid!" << std::endl;
        }
    }
    
    return 0;
}

bool isEmpty() {
	head = NULL;
	tail = NULL;
}

void insertNode(int data) {
	newNode = new Node;
	newNode->data = data;
	newNode->next	= NULL;
	newNode->prev	= NULL;
	
	if (isEmpty()) {
		head	= newNode;
		head->next	= NULL;
		head->prev	= NULL;
		tail		= head;
	}
	else {
		tail->next	= newNode;
		newNode->prev	= tail;
		tail 			= newNode;
	}
	//getchar();
	cin.ignore();
	cout << "200 ok";
	getchar();
}

void deleteFromFront() {
	int simpan;
	if (head != NULL) {
		if (head->next != NULL) {
			del = head;
			simpan = head->data;
			cout << "hapus";
			head = head->next;
			head->prev = NULL;
			delete del;
		}
		else {
			simpan = head->data;
			cout << "hapus";
			head = NULL;
		}
	}
	else {
		cout << "nope";
	}
	getchar();
}


void printNode() {
	print = head;
    if (head != NULL)
    {
        cout << "Isi linked list: ";
        while (print != NULL)
        {
            cout << print->data;
            if (print->next != NULL)
            {
                cout << " <= => ";
            }
            print = print->next;
        }
        cout << endl;
    }
    else
    {
        cout << "\nTidak ada data dalam linked list" << endl;
    }
    getchar();
}

