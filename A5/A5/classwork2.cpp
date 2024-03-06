#include <iostream>
using namespace std;

void mySwap(int &, int &);

int maincc() {
	cout << "Before mySwap\n";
	int a = 1, b = 2;
	cout << "a = " << a << " b = " << b << endl;
	cout << "After mySwap\n";
	mySwap(a, b);
	cout << "a = " << a << " b = " << b;
	return 0;
}

void mySwap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}