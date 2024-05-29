#include <iostream>
#include <string>
#define Merah "\033[31m"
#define Kuning "\033[33m"
#define Hijau "\033[32m"
#define Biru "\033[34m"
#define Hitam "\033[0m"
using namespace std;

bool isEmpty();
void insertNode(int data), deleteFromFront(), deleteFromEnd(), deleteAll();

struct Node {
	string data;
	Node *next;
};

Node *headNode = NULL;
Node *currentNode = NULL;
int jumlahNode = 0;

bool isEmpty() {
	return (headNode == NULL);
}

void insertNode(string data) {
	Node *newNode = NULL;
	newNode = new Node;
	newNode->data = data;
	if (isEmpty()) {
		headNode = newNode;
	}
	else {
		currentNode->next = newNode;
	}

	currentNode = newNode;
	currentNode->next = NULL;
	jumlahNode++;
}

void deleteFromFront()
{
	if (!isEmpty())
	{

		Node *hapusNode = headNode;
		headNode = headNode->next;
		delete hapusNode;
		cout << Hijau << "Node berhasil dihapus" << Hitam;
		jumlahNode--;

	}
	else {
        cout << Merah << "Node masih Kosong" << Hitam;
	}
	getchar();
}

void deleteFromEnd()
{
    if (!isEmpty()) {

        if (headNode == currentNode)
        {
            headNode = NULL;
            currentNode = NULL;
            jumlahNode--;
            cout << Hijau << "Node berhasil dihapus" << Hitam;
            getchar();
            return;
        }
        Node *bantu = headNode;
        Node *hapusNode = currentNode;
        while (bantu->next != currentNode)
        {
            bantu = bantu->next;
        }
        currentNode = bantu;
        currentNode->next = NULL;
        delete hapusNode;
        cout << Hijau << "Node berhasil dihapus" << Hitam;
        jumlahNode--;
    }
    else {
        cout << Merah << "Node masih Kosong" << Hitam;
    }
    getchar();
}

void deleteAll()
{
    if (!isEmpty()) {
        Node *hapusNode;
        while (headNode != NULL)
        {
            hapusNode = headNode;
            headNode = headNode->next;
            delete hapusNode;
        }

        currentNode = NULL;
        jumlahNode = 0;
        cout << Hijau << "Semua node berhasil dihapuskan";

    }
    else {
        cout << Merah << "Node masih Kosong" << Hitam;
    }
    getchar();

}

void printNode()
{
	if (!isEmpty()) {
        Node *awalNode = headNode;
        int i = 1;
        while (awalNode != NULL)
        {
            cout << "Data pada node #" << i << " = " << awalNode->data<< endl;
            awalNode = awalNode->next;
            i++;
        }
	}
	else {
        cout << Merah << "Node masih Kosong" << Hitam;
    }
    getchar();
}

int main () {

	int pilihan;
	string data;

    while (true)
    {
    	cout << "\033[2J" << "\033[1;1H";
        cout << Biru << "\t>>> PILIHAN MENU SINGLY LINKED LIST <<<" << Hitam << "\n\n"
             << "\tJumlah node: " << ((jumlahNode == 0) ? Merah : Hijau) << jumlahNode << Hitam << "\n"
        	 << "\t1. Menambah Node\n"
        	 << ((jumlahNode == 0) ? Merah : Hitam) <<"\t2. Menghapus Node dari depan\n"
        	 << "\t3. Menghapus Node dari Belakang\n"
       		 << "\t4. Mengosongkan Node\n"
       		 << "\t5. Menampilkan Semua Node\n" << Hitam
             << "\t6. Keluar\n\n";
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
                cout << Kuning << "Pilihan tidak valid!";
                getchar();
        }
    }

    return 0;
}
