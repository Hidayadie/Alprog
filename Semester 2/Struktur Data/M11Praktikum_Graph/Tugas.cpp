#include <iostream>

using std::cout;
using std::cin;

/*******************************/


int main() {

	int ukuran	,	// jumlah vertexnya
		edge	,	// jumlah garisnya
		sumber	,	// titik asal
		tujuan	;	// titik tujuan
					 	
	cout << "Jumlah Vertex	= "; cin >> ukuran;
	cout << "Jumlah Edge	= "; cin >> edge;
	
	
	// INISIALISASI GRAPH
	int matrix[ukuran][ukuran] = {0}	;	// graph nya 
	char nama[ukuran]					; 	// nama graph
	int jarak[ukuran]					;	// jarak/weight graphnya	
	
	
	// FUNGSI PENAMAAN
	
	for (int i = 0; i < ukuran; i++) {
		cout << "Nama Vertex ke - " << i+ 1 << " : "; 
		cin >> nama[i];
	}
	
	
	// FUNGSI ISI
	
	for (int i = 0; i < edge; i++) {
		cout << "\nEdge " << i +1;
		cout << "\nVertex Sumber\t= "; 	cin >> sumber;		// titik asal
		cout << "Vertex Tujuan\t= "; 	cin >> tujuan;		// titik tujuan
		cout << "Panjang simpul\t= "; 	cin >> jarak[i];	// weight edge
		
		// DIRECTED GRAPH
		matrix[sumber-1][tujuan-1] = 1; 
	}


	// FUNGSI CARI KEKOSONGAN
	/*
	for (int i = 0; i < ukuran; i++) {
		for (int j = 0; j < ukuran; j++) {
			((matrix[i][j] == 1) ? trigger = true : trigger = false);
			if (trigger) {
				kosong = true;
				break;
			}
		}
	}
	*/
	
	
	cout << "\nGraph Berhasil dibuat\n";
	cout << "\nSimpul yang terbentuk:\n";
	
	
	// FUNGSI CEK GARIS
	int total = 0;
	for (int i = 0; i < ukuran; i++) {
		for (int j = 0; j < ukuran; j++) {
			if (matrix[i][j] == 1) {
				cout << " - "
					 << nama[i] << nama[j] << " dengan panjang " << jarak[i] 
					 << "\n";
				total += jarak[i]; // cek panjang simpulnya trus ditambah
				
			}
		}
	}
	
	cout << "\nTotal panjang: " << total;
	
}
