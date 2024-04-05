// *******************************************************************************
// Assignment 6A: Largest/Smallest Array Values
// Author: Gavin Torrecampo
// Description: This program lets the user enter 10 values into an array, then 
// determines the largest and smallest array values from them.
// Status: Complete
// Date: March 22, 2024
// *******************************************************************************

#include<iostream>
using namespace std;

int main1() {
	const int SIZE = 10;
	int num, max, min;
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++) {
		cout << "\n(" << i+1 << ") Enter a number . . . ";
		cin >> num;
		arr[i] = num;
		if (i == 0) 
			max = num, min = num;
		max = arr[i] >= max ? arr[i] : max;
		min = arr[i] <= min ? arr[i] : min;
	}
	cout << "\nYour largest number is: " << max;
	cout << "\nYour smallest number is: " << min;
	return 0;
}