#include <iostream>

using namespace std;
void selectionSort(int n, int arr[]), print(int arr[], int n);

int main() {
	cout << "masukkan 5 nilai ke array...\n";
	int arr[5];
	for (int i = 0; i < 5; i++) {
        cout << "Masukkan nilai ke - " << i +1 << " : "; cin >> arr[i];
	}
	int n = sizeof(arr)/sizeof(int);
	cout << "Sebelum disorting: ";
	print(arr, n);
	cout << "\nSetelah disorting: ";
	selectionSort(n, arr);
	print(arr, n);
}

void selectionSort(int n, int arr[]) {

	int i, j, min;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
			swap(arr[j], arr[min]);
		}
	}
}

void print(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}
