#include <iostream>
#include <string>
#define Merah "\033[31m"
#define Kuning "\033[33m"
#define Hijau "\033[32m"
#define Biru "\033[34m"
#define Hitam "\033[0m"
using namespace std;

bool isEmpty();
void insertNode(int data);
void deleteFromFront();
void deleteFromEnd();
void deleteAll();

struct Node {
	string data;
	Node *next;
};

Node *headNode = NULL;
Node *currentNode = NULL;

bool isEmpty() {
	return (headNode == NULL);
}

void insertNode(string data) {
	// deklarasi pointer newNode;
	Node *newNode = NULL;
	// mengalokasikan memory untuk pointer
	newNode = new Node;
	// isikan data ke node yang
	newNode->data = data;
	if (isEmpty()) {
		// node baru otomatis menjadi head
		headNode = newNode;
	}
	else // sudah ada node
	{
		// hubungkan pointer next node aktif (current node)
		// ke node yg baru
		currentNode->next =
		newNode;
	}
	// set node baru sebagai node aktif
	currentNode = newNode;
	// set pointer next node terakhir menjadi NULL
	currentNode->next = NULL;	
}

void deleteFromFront()
{
	if (!isEmpty())
	{
		// deklarasi var bantu untuk menampung
		Node *hapusNode = headNode;
		// pindahkan headNode ke node
		headNode = headNode->next;
		// hapus headNode yang
		delete hapusNode;
		cout << Hijau << "Node berhasil dihapus" << Hitam << endl;
		getchar();
	}
}

void deleteFromEnd()
{
	// jika node tinggal satu
	if (headNode == currentNode)
	{
		headNode = NULL;
		currentNode = NULL;
		return;
	}
	// deklarasi pointer bantu untuk menampung head
	Node *bantu = headNode;
	// deklarasi pointer hapus untuk menampung current
	Node *hapusNode = currentNode;
	// lakukan perulangan sebelum mencapai akhir node
	while (bantu->next != currentNode)
	{
		bantu = bantu->next;
	}
	currentNode = bantu;
	currentNode->next = NULL;
	delete hapusNode;
}

void deleteAll()
{
	Node *hapusNode;
    while (headNode != NULL)
    {
        hapusNode = headNode;
        headNode = headNode->next;
        delete hapusNode;
    }
    
    currentNode = NULL;
    cout << "Semua node berhasil dihapuskan" << endl << endl;
    getchar();

}

void printNode()
{
	// deklarasi pointer awal node untuk menampung head
	Node *awalNode = headNode;
	int i = 1;
	while (awalNode != NULL)
	{
		cout << "Data pada node #" << i << " = " << awalNode->data<< endl;
		awalNode = awalNode->next;
		i++;
	}
	getchar();
}

int main () {
	
	int pilihan;
	string data;
    
    while (true)
    {
    	system("cls");
        cout << Merah << ">>> PILIHAN MENU SINGLY LINKED LIST <<<" << Hitam
			 << "\n"
        	 << "1. Menambah Node\n" 
        	 << "2. Menghapus Node dari depan\n" 
        	 << "3. Menghapus Node dari Belakang\n" 
       		 << "4. Mengosongkan Node\n" 
       		 << "5. Menampilkan Semua Node\n"
             << "6. Keluar\n";
        
        cout << endl;
        
        cout << "Masukkan Pilihan anda: "; cin >> pilihan;
       
        cin.ignore();
        switch (pilihan)
        {
            case 1:
                cout << "Masukkan data: "; getline(cin, data);
                insertNode(data);
                break;
            case 2:
                deleteFromFront();
                break;
            case 3:
                deleteFromEnd();
                break;
            case 4:
                deleteAll();
                break;
            case 5:
                printNode();
                break;
            case 6:
                return 0;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }
    
    return 0;
}
