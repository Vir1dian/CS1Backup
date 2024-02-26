// *******************************************************************************
// Assignment 2A: Areas of Rectangles
// Author: Gavin Torrecampo
// Description: This program prompts the user to enter the length and width
// of two rectangles. The program should tell the user which rectangle has 
// the greater area, or if the areas are the same.
// Status: Complete
// Date: February 6, 2024
// ********************************************************************************
#include<iostream>
using namespace std;

int main1() {
	float l1, w1, l2, w2;
	cout << "Enter the length of rectangle 1: " << endl;
	cin >> l1;
	cout << "Enter the width of rectangle 1: " << endl;
	cin >> w1;
	cout << "Enter the length of rectangle 2: " << endl;
	cin >> l2;
	cout << "Enter the width of rectangle 2: " << endl;
	cin >> w2;
	if (l1 * w1 > l2 * w2)
		cout << "Rectangle 1 has a larger area (" << l1 * w1 << ") than rectangle 2 (" << l2 * w2 << ")\n";
	else if (l1 * w1 < l2 * w2)
		cout << "Rectangle 2 has a larger area (" << l2 * w2 << ") than rectangle 1 (" << l1 * w1 << ")\n";
	else
		cout << "Rectangle 1 and rectangle 2 have equal areas (" << l2 * w2 << ")\n";
	return 0;
}
