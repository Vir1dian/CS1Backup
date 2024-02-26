// *******************************************************************************
// Assignment 4A: Characters for the ASCII Codes
// Author: Gavin Torrecampo
// Description: This program uses a loop to display ASCII characters for codes 
// 0-127. 16 characters are displayed per line.
// Status: Complete
// Date: February 12, 2024
// ********************************************************************************
#include <iostream>
using namespace std;

int main1() {
	for (int i = 0; i <= 127; i++) {
		cout << char(i);
		if (i % 16 == 0)
			cout << endl;
	}
	return 0;
}