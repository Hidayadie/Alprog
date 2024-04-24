#include <iostream>
#include <string>

using namespace std;
void sortZA(int n, string arr[]), print(string arr[], int n), sortAZ(int n, string arr[]);

int main() {
	string arr[] = {"Abdul", "Hadi", "Harsoyo", "Bajul", "Abdullah"};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Sebelum disorting: ";
	print(arr, n);
	cout << "\nSetelah disorting ZA: ";
	sortZA(n, arr);
	print(arr, n);
	cout << "\nSetelah disorting AZ: ";
	sortAZ(n, arr);
	print(arr, n);
}

void sortZA(int n, string arr[]) {
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


void sortAZ(int n, string arr[]) {
	int i, j, min;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] > arr[min]) {
				min = j;
			}
			swap(arr[j], arr[min]);
		}
	}
}

void print(string arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	} 
}
