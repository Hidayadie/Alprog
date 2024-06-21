struct Stock {
        int jumlah          ; 
        string kondisi[100] ; 
        Stock() : jumlah(-1){};

        void tambah(string _kondisi) {
            jumlah++;
            kondisi[jumlah] = _kondisi;
        }

        void tambah(int berapa) {
            string _kondisi;
            if (berapa > 0) {
                for (int i = 0; i < berapa; i++) {
                    jumlah++;
                    cout << "Kondisi barang "<<i<<" : ";
                    getline(cin, _kondisi);
                    kondisi[jumlah] = _kondisi;
                }
            } else {
                cout << "Gunakan kurang() untuk mengurangi stok";
            }
        }
        void kurang() {
            if (jumlah > 0) {
                jumlah--;
            } else {
                cout << "Stok sudah kosong";
            }
        }

        void kurang(int berapa) {
            if (jumlah > 0) {
                jumlah -= berapa;
                jumlah = (jumlah < 0) ? -1 : jumlah;
            } else {
                cout << "Stok sudah kosong";
            }
        }
        void cekStok() {
            cout << jumlah;
        }
    };
