#include <iostream>

using namespace std;

int main() {
    int x = 100, y = 130, z;
	int *ptrX, *ptrY;
	ptrX = &x;
	ptrY = &y;
	z = *ptrX;
	//nilai x,y
	cout << "nilai x \t= "<< x << ", nilai y    \t= "<<y << "\n"
		 << "alamat x \t= " << &x << ", alamat y  \t= " << &y << "\n"
		 << "isi ptrX \t= " << ptrX << ", value ptrX \t= " << *ptrX << "\n"
		 << "isi ptrY \t= " << ptrY << ", value ptrY \t= " << *ptrY << "\n"
		 << "nilai z \t= " << z << ", yaitu nilai x\t= " << x << "\n"
		 << "mengubah isi nilai x dan y...\nX = "; cin >> x;
	cout << "Y = "; cin >> y;
	cout << "isi ptrX \t= " << ptrX << ", value ptrX \t= "<< *ptrX << "\n"
		 << "isi ptrY \t= " << ptrY << ", value ptrY \t= " << *ptrY << "\n"
		 << "dst...";
}
