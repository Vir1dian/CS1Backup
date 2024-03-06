// *******************************************************************************
// Assignment 5C: Lowest Score Drop
// Author: Gavin Torrecampo
// Description: This program calculates the average of a group of test scores,
// where the lowest score in the group is dropped. It uses the functions: 
// getScore, calcAverage, and findLowest.
// Status: Complete
// Date: February 28, 2024
// *******************************************************************************
#include <iostream>
using namespace std;

void getScore(int &);
void calcAverage(int, int, int, int, int);
int findLowest(int, int, int, int, int);

int main3() {
	int score1, score2, score3, score4, score5;
	getScore(score1);
	getScore(score2);
	getScore(score3);
	getScore(score4);
	getScore(score5);
	calcAverage(score1, score2, score3, score4, score5);
	return 0;
}

void getScore(int &score) {
	cout << "Enter a score BETWEEN 1-100 . . . \n";
	cin >> score;
	while (score < 0 || score > 100) {
		cout << "Score is NOT BETWEEN 1-100, try again . . . \n";
		cin >> score;
	}
}
void calcAverage(int a, int b, int c, int d, int e) {
	int sum = a + b + c + d + e - findLowest(a, b, c, d, e);
	float average = sum / 4.0;
	cout << average << endl;
}
int findLowest(int a, int b, int c, int d, int e) {
	int low = a <= b ? a : b;
	low = low <= c ? low : c;
	low = low <= d ? low : d;
	low = low <= e ? low : e;
	// cout << "Dropped score: " << low << endl;
	return low;
}