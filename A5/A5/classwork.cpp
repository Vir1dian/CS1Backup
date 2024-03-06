#include <iostream>
using namespace std;

int add(int, int);
int subtract(int, int);
int multiply(int, int);
void display(int);
void displayfriend(string name = "Tyler");

int mainc() {
	// display(add(3, 2));
	// display(subtract(3, 2));
	// display(multiply(3, 2));
	displayfriend();
	displayfriend("Arjun");
	displayfriend("Khoi");
	displayfriend("Kaylien");
	return 0;
}

int add(int a, int b) {
	return a + b;
}
int subtract(int a, int b) {
	return a - b;
}
int multiply(int a, int b) {
	return a * b;
}
void display(int a) {
	cout << a << endl;
}
void displayfriend(string name) {
	cout << name << endl;
}
