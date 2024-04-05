#include<iostream>
using namespace std;

const int SIZE = 10;

double average(const int array[]);
double average(const double array[]);

int mainc() {
	// Part 1
	cout << "*** PART 1 ***";
	int num, count_5 = 0;
	int numbers[SIZE];
	cout << "\nEnter the number 5 at least two times . . . \n";
	for (int i = 0; i < SIZE; i++) {
		cout << "(" << i + 1 << ")Enter a number: ";
		cin >> num;
		if (num == 5) {
			count_5++;
		}
		numbers[i] = num;
	}
	cout << "\n";
	for (int i = SIZE - 1; i >= 0; i--)
		cout << numbers[i] << " ";
	cout << "\nNumber of 5's in array: " << count_5;

	// Part 2
	cout << "\n\n*** PART 2 ***\n";
	int array_int[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
	double array_double[SIZE] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.10 };

	cout << "Average of int array: " << average(array_int) << endl;
	cout << "Average of double array: " << average(array_double) << endl;

	return 0;
}

double average(const int array[]) {
	double sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += array[i];
	}
	return (sum/SIZE);
}

double average(const double array[]) {
	double sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += array[i];
	}
	return sum / SIZE;
}