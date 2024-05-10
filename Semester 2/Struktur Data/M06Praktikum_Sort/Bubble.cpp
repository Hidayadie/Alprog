#include <iostream>

using namespace std;

void bubbleSort(int n, int arr[]);


int main() {
    cout << "masukkan 5 nilai ke array...\n";
	int arr[5];
	for (int i = 0; i < 5; i++) {
        cout << "Masukkan nilai ke - " << i +1 << " : "; cin >> arr[i];
	}
	int n = sizeof(arr)/sizeof(int);
	cout << "Sebelum disorting: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\nSetelah disorting: ";
	bubbleSort(n, arr);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

void bubbleSort(int n, int arr[]) {
	int i, j;
	bool flag;
	for (int i = 0; i < n; i++) {
		flag = false;
		for (int j = 0; j < n-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
				flag = true;
			}
		}
	}
}
