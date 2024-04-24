#include <iostream>

using namespace std;
void selectionSort(int n, int arr[]), print(int arr[], int n);

int main() {
	int arr[] = {20,12,10,15,2};
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
