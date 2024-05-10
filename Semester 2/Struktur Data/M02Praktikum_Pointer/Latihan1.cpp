#include <iostream>

using namespace std;

    int main() {
	int x =100;
	int *pointer;
	pointer = &x;

	int y = *pointer;

	cout << "nilai x = " << x << ", dengan alamat " << &x << "\n"
		 << "nilai alamat pointer = " << pointer << "\n"
		 << "nilai yg ditunjuk pointer = " << *pointer << "\n"
		 << "nilai y = " << y << "\n\n";


}
