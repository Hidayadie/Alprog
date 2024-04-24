#include <iostream>

using namespace std;

void bubbleSort(int n, int arr[]);


int main() {
	int arr[] = {-2,45,0,11,-9};
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
