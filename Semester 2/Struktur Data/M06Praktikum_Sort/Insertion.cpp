#include <iostream>

using namespace std;
void insertSort(int n, int arr[]), print(int arr[], int n);

int main() {
	cout << "masukkan 5 nilai ke array...\n";
	int arr[5];
	for (int i = 0; i < 5; i++) {
        cout << "Masukkan nilai ke - " << i +1 << " : "; cin >> arr[i];
	}
	int n = sizeof(arr)/sizeof(int);
	cout << "\nSebelum disorting: ";
	print(arr, n);
	cout << "\nSetelah disorting: ";
	insertSort(n, arr);
	print(arr, n);
}

void insertSort(int n, int arr[]) {

	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i -1;
		while (key < arr[j] && j >= 0) {
			arr[j+1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

void print(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}
