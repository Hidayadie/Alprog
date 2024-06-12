#include <iostream>
#include <string>

using std::cout;
using std::cin;

void print();

bool kosong();

/*******************************/


void isi(int matrix[5][5]) {
	
}

int main() {

	int ukuran	,
		edge	,
		sumber	,
		tujuan	;
	
	
		
	bool kosong	,
		 trigger;
		 	
		 	
	cout << "Jumlah Vertex	= "; cin >> ukuran;
	cout << "Jumlah Edge	= "; cin >> edge;
	
	cin.ignore();
	
	// INISIALISASI GRAPH
	int matrix[ukuran][ukuran] = {0};
	char nama[ukuran];
	int jarak[ukuran];
	
	// FUNGSI PENAMAAN
	
	for (int i = 0; i < ukuran; i++) {
		cout << "Nama Vertex ke - " << i+ 1 << " : "; cin >> nama[i];
	}
	
	// FUNGSI ISI
	
	for (int i = 0; i < edge; i++) {
		cout << "\nEdge " << i +1;
		cout << "\nVertex Sumber\t= "; cin >> sumber;
		cout << "Vertex Tujuan\t= "; cin >> tujuan;
		cout << "Panjang simpul\t= "; cin >> jarak[i];
		matrix[sumber-1][tujuan-1] = 1;
	}


	// FUNGSI CARI KEKOSONGAN

	for (int i = 0; i < ukuran; i++) {
		for (int j = 0; j < ukuran; j++) {
			((matrix[i][j] == 1) ? trigger = true : trigger = false);
			if (trigger) {
				kosong = true;
				break;
			}
		}
	}
	
	
	
	cout << "\nGraph Berhasil dibuat\n";
	cout << ((!kosong) ? "Semua Graph Terhubung" : "");
	cout << "\nSimpul yang terbentuk:\n";
	
	
	
	// FUNGSI CEK GARIS
	int total = 0;
	for (int i = 0; i < ukuran; i++) {
		for (int j = 0; j < ukuran; j++) {
			if (matrix[i][j] == 1) {
				cout << " - "
					 << nama[i] << nama[j] << " dengan panjang " << jarak[i] 
					 << "\n";
				total += jarak[i];
				
			}
		}
	}
	
	cout << "\nTotal panjang: " << total;
	
}
