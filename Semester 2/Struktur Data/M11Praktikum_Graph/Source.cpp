#include <iostream>

using std::cout;
using std::cin;

int main() {
	int ukuran	,
		edge	,
		sumber	,
		tujuan	,
		i		= 1;
		
	bool nolsemua	,
		 ketemu		;
		 	
	cout << "Jumlah Vertex: "; cin >> ukuran;
	cout << "Jumlah Edge  : "; cin >> edge;
	int matrix[ukuran][ukuran];
	
	for (i = 1; i <= ukuran; i++) {
		for (int j = 1; j <= ukuran; j++) {
			matrix[i][j] = 0;
		}
	}
	
	for (i = 1; i <= edge; i++) {
		cout << "Sumber: "; cin >> sumber;
		cout << "Tujuan: "; cin >> tujuan;
		
		matrix[sumber][tujuan] = matrix[tujuan][sumber] = 1;
	}
	
	i = 1;
	while (i<=ukuran && nolsemua == false) {
		int j = 1;
		while (j<=ukuran && ketemu == false) {
			if (matrix[i][j] == 1) {
				ketemu = true;
			} else {
				j++;
				
			}
		}
		if (!ketemu) {
			nolsemua = true;
		} else {
			i++;
		}
	}
	
	
	if (nolsemua) {
		cout << "Graph tidak terhubung";
	}
	else {
		cout << "Graph terhubung";
	}
}
