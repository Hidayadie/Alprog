
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
#define Merah "\033[31m"
#define Kuning "\033[33m"
#define Hijau "\033[32m"
#define Biru "\033[34m"
#define Hitam "\033[0m"

using namespace std;

const int Max = 5;

struct Queue {
	int depan, belakang, data[Max];
};
Queue queue;
int tiket = 0;
void init(), deque(), enque(), clear(), print();
bool isEmpty(), isFull();

int main () {
    init();
    int pil;
    do {
        system("clear");
        cout << Hitam;
        cout << " +----------------------+\n"
             << " | >-"<<Biru<< " Sistem antrian "<<Hitam<<"-< |\n"
             << " | 1. Tambah antrian\t|\n"
             << " | 2. Panggil antrian\t|\n"
             << " | 3. Daftar antrian\t|\n"
             << " | 4. Kosongkan antrian\t|\n"
             << " | 5. Keluar\t\t|\n"
             << " +----------------------+\n"
             << "Kapasitas kursi: " << (queue.belakang + 1 == Max ? Merah : Hijau) << queue.belakang + 1 << "/" << Max <<"\n";
        //cout << (queue.belakang + 1 == Max ? Merah : Hijau) << (queue.belakang + 1 == Max ? "Queue Sudah Penuh!!!" : "Queue masih tersedia...");
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
		tiket++;
		cout << "Antrian dengan nomor "<< Hijau << tiket << Hitam << " berhasil dibuat\n";
		queue.depan = 0;
		queue.belakang++;
		queue.data[queue.belakang] = tiket;
		cout << "Sisa kapasitas: " << (queue.belakang + 1 == Max ? Merah : Hijau) << queue.belakang + 1 << "/" << Max <<"\n";
        cout << (queue.belakang + 1 == Max ? Kuning : Hijau) << (queue.belakang + 1 == Max ? "Antrian sudah penuh" : "Antrian masih tersedia...");


	}
	else {
		cout << Merah << "Kapasitas Penuh!\n" << Hitam;
	}
	cout << Biru << "\n\nKetuk enter untuk kembali..." << Hitam;
	getchar();
}

void deque() {
    if (!isEmpty()) {
        cout << "Nomor antrian "<< queue.data[queue.depan] << " telah dipanggil\n\n";
        for (int i = queue.depan; i <= queue.belakang; i++) {
            queue.data[i] = queue.data[i + 1];
        }
        queue.belakang--;
    }
    else {
        cout << Merah << "Antrian kosong\n" << Hitam;
    }
	cout << Biru << "Ketuk enter untuk kembali..." << Hitam;
	getchar();
}

void clear() {
	queue.depan = queue.belakang = -1;
	cout << "Antrian berhasil dikosongkan\n\n";
	cout << Biru << "Ketuk enter untuk kembali..." << Hitam;
	getchar();
}

void print() {
	cout << "Rekap antrian hari ini,";
    cout << "\nNomor antrian yang sedang menunggu : " << Merah;
	for (int i = queue.depan; i <= queue.belakang; i++) {
        if (i == -1) {
            continue;
        }
        else {
            cout << queue.data[i] << " ";
        }
	}
	cout << Hitam << "\nNomor antrian yang telah terpanggil: "<< Hijau;
	for (int i = 1; i < tiket - queue.belakang; i ++) {
        cout << i << " ";
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
