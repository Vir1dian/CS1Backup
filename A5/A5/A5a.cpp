// *******************************************************************************
// Assignment 5A: Rectangle Area--Complete the program
// Author: Gavin Torrecampo
// Description: This program will ask the user to enter the width and length of a
// rectangle, and then display the rectangle's area. The program calls some 
// functions: getLength, getWidth, getArea, and displayData.
// Status: Complete
// Date: February 26, 2024
// *******************************************************************************
#include <iostream>
using namespace std;

int getLength();
int getWidth();
int getArea(int, int);
void displayData(int);

int main1() {
	displayData(getArea(getLength(), getWidth()));
	return 0;
}

int getLength() {
	int l;
	cout << "Enter the length of the rectangle\n";
	cin >> l;
	return l;
}
int getWidth() {
	int w;
	cout << "Enter the width of the rectangle\n";
	cin >> w;
	return w;
}
int getArea(int l, int w) {
	return l * w;
}
void displayData(int a) {
	cout << a;
}

