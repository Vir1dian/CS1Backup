#include<iostream>
#include<string>
using namespace std;
int main() {
	int my_num;
	cout << "Enter a number";
	cin >> my_num;
	int num = my_num;
	string roman = "";
	// 1000's and 100's
	for (int i = 0; i < num / 1000; i++) {
		roman += "M";
	}
	num = num % 1000;
	if (num / 900 == 1) {
		roman += "CM";
		num = num % 900;
	} else if (num / 400 == 1 && num / 500 != 1) {
		roman += "CD";
		num = num % 400;
	}
	if (num / 500 == 1) {
		roman += "D";
		num = num % 500;
	} 
	for (int i = 0; i < num / 100; i++) {
		roman += "C";
	}
	num = num % 100;
	// Hundreds and Tens
	if (num / 90 == 1) {
		roman += "XC";
		num = num % 90;
	}
	else if (num / 40 == 1 && num / 50 != 1) {
		roman += "XL";
		num = num % 40;
	}
	if (num / 50 == 1) {
		roman += "L";
		num = num % 50;
	}
	for (int i = 0; i < num / 10; i++) {
		roman += "X";
	}
	num = num % 10;
	// Tens and Ones
	if (num == 9) {
		roman += "IX";
		num = num % 9;
	}
	else if (num == 4) {
		roman += "IV";
		num = num % 4;
	}
	if (num / 5 == 1) {
		roman += "V";
		num = num % 5;
	}
	for (int i = 0; i < num; i++) {
		roman += "I";
	}
	cout << my_num << " in roman numerals: " << roman;
	/*
	string greeting;
	int n, count = 0;
	cout << "Enter a greeting\n";
	getline(cin, greeting);
	cout << "How many times?\n";
	cin >> n;
	cin.ignore();
	while (count < n) {
		cout << greeting << endl;
		count++;
	}
	*/
	return 0;
}