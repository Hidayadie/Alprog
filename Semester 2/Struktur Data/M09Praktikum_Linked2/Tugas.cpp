/*
        Program Dobel linked list
        banyak kode yang amburadul males ngerapiin
        ntar deh kalo sempet...

        kalo ada yang dibingungin tanya aja
        085602254537

*/

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
	Node *next,
         *prev;
};

Node *head,
     *tail,
     *tumbal,
     *del,
     *newNode,
     *setelah,
     *sebelum;

bool isEmpty();
void TambahDepan(int data),
     TambahBelakang(int data),
     TambahTengah(int data),
     HapusDepan(),
     HapusBelakang(),
     HapusTengah(),
     HapusSemua(),
     Print();

int jumlah = 0;

int main () {

	int pilihan,
        data;

    while (true)
    {
    	cout << "\033[2J" << "\033[1;1H";
        cout << Merah << ">>> PILIHAN MENU DOUBLE LINKED LIST <<<" << Hitam
			 << "\n"
        	 << "1. Menambah Node dari Depan\n"
        	 << "2. Menambah Node dari tengah\n"
        	 << "3. Menambah Node dari Belakang\n"
        	 << "4. Menghapus dari Depan\n"
        	 << "5. Menghapus dari Tengah\n"
        	 << "6. Menghapus dari Belakang\n"
        	 << "7. Menghapus semua Node\n"
        	 << "8. Menampilkan semua Node\n"
       		 << "9. Selesai\n"
       		 << "----------------------------------\n"
       		 << jumlah << "\n";



        cout << "Masukkan Pilihan anda: "; cin >> pilihan;


        switch (pilihan)
        {
            case 1:
                cout << "Masukkan data: "; cin >> data;

                TambahDepan(data);
                break;

            case 2:
                cout << "Masukkan data: "; cin >> data;
                TambahTengah(data);
                break;

            case 3:
                cout << "Masukkan data: "; cin >> data;

            	TambahBelakang(data);
                break;

            case 4:
                HapusDepan();
                break;

            case 5:
                HapusTengah();
            	break;

            case 6:
                HapusBelakang();
                break;

            case 7:
                HapusSemua();
                break;
            case 8:

                Print();
                break;

            case 9:
            	return 0;
            	break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    }

    return 0;
}

bool isEmpty() {

	return (head == NULL && tail == NULL);

}

void TambahDepan(int data) {
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
		newNode->next	= head;
		head->prev		= newNode;
		head 			= newNode;
	}
	//getchar();
	cin.ignore();
	cout << "200 ok";
	jumlah++;
	getchar();
}
void TambahBelakang(int data) {
	newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (isEmpty()) {
		head	= newNode;
		head->next	= NULL;
		head->prev	= NULL;
		tail		= head;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	jumlah++;
}

void TambahTengah(int data) {
    newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
	newNode->prev = NULL;

	if (isEmpty()) {
		head	= newNode;
		head->next	= NULL;
		head->prev	= NULL;
		tail		= head;
	}
	else {
        tumbal = head;
        int tengah = jumlah /2;
        int i = 1;
        while (i < tengah) {
            tumbal = tumbal->next;
            i++;
        }

        setelah = tumbal->next;

        tumbal->next = newNode;
        newNode->prev = tumbal;

        setelah->prev = newNode;
        newNode->next = setelah;

	}
    jumlah++;
}


void HapusDepan() {
	if (head != NULL) {
		if (head->next != NULL) {
			del = head;
			head = head->next;
			head->prev = NULL;
			delete del;
		}
		else {

			cout << "hapus";
			head = NULL;
		}
	}
	else {
		cout << "nope";
	}
	getchar();
}

void HapusBelakang() {
    if (head != NULL) {
        if (tail->prev != NULL) {
            del = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete del;
        }
        else {
            tail = NULL;
        }
    }
    else {
		cout << "nope";
	}
	getchar();
}

void HapusTengah() {
    if (head != NULL) {
        if (jumlah > 2) {
            int i = 1;
            int tengah = jumlah /2 + 1;

            tumbal = head;
            while (i < tengah) {
                tumbal = tumbal->next;
                i++;
            }
            del = tumbal;
            setelah = del->next;
            sebelum = del->prev;

            sebelum->next = setelah;
            setelah->prev = sebelum;
            delete del;
            jumlah--;
        }
        else {
            cout << "jumlah minimal 3";
            getchar();
            //getchar();
        }

    }
    else {
		cout << "nope";
	}
	getchar();
}

void HapusSemua() {
    if (isEmpty()) {
        cout << "kosong";
    }
    else {
        tumbal = head;
        while (tumbal != NULL) {
            setelah = tumbal;
            tumbal = tumbal->next;
            delete setelah;

        }
        jumlah = 0;
        head = NULL;
        tail = NULL;
    }
}

void Print() {
	tumbal = head;
    if (head != NULL)
    {
        cout << "Isi linked list: ";
        while (tumbal != NULL)
        {
            cout << tumbal->data;
            if (tumbal->next != NULL)
            {
                cout << " <= => ";
            }
            tumbal = tumbal->next;
        }
        cout << endl;
    }
    else
    {
        cout << "\nTidak ada data dalam linked list" << endl;
    }
    cin.ignore();
    getchar();

}

