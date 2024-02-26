// *******************************************************************************
// Assignment 4C: Using Files--Numeric Processing
// Author: Gavin Torrecampo
// Description: This program opens a .txt file containing a list of random numbers,
// reads the numbers from the file, then calculates and displays: A) number of 
// numbers in the file, B) sum of all the numbers, C) average of all the numbers.
// Status: Complete
// Date: February 16, 2024
// ********************************************************************************
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main3() {
	ifstream infile;
	string line;
	int count = 0, sum = 0;
	float average = 0;
	infile.open("numbers.txt");
	if (infile.good()) {
		while (getline(infile, line)) {
			if (line.length() == 0)
				continue;
			count++;
			sum += stoi(line);
			// cout << count << " " << line << " " << sum << endl;
		}
		infile.close();
		average = float(sum) / count;
	}
	else {
		cout << "Error" << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Counted numbers in numbers.txt: " << count << endl;
	cout << "Sum of numbers in numbers.txt: " << sum << endl;
	cout << "Average of numbers in numbers.txt: " << average << endl;
	return 0;
}