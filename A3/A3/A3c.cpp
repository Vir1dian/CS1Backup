// *******************************************************************************
// Assignment 2C: Geometry Calculator
// Author: Gavin Torrecampo
// Description: This program offers a menu of 4 choices: calculate area of circle,
// calculate area of rectangle, calculate area of triangle, and quit.
// Date: February 7, 2024
// ********************************************************************************
#include<iostream>
#include<iomanip>
using namespace std;

int main3() {
	int input = 1;
	while (input != 4) {
		cout << "\nGeometry Calculator\n";
		cout << "1. Calculate the Area of a Circle\n";
		cout << "2. Calculate the Area of a Rectangle\n";
		cout << "3. Calculate the Area of a Triangle\n";
		cout << "4. Quit\n";
		cout << "Enter your choice (1-4) . . .\n";
		cin >> input;
		switch (input) {
			case 1:
				float radius;
				cout << "\n(1) Area of Circle, \nEnter a radius . . .\n";
				cin >> radius;
				if (radius >= 0) 
					cout << "* Area of your circle: " << radius * 3.14 << endl;
				else
					cout << "Invalid input (cannot be a negative number).\n";
				break;
			case 2:
				float length;
				float width;
				cout << "\n(2) Area of Rectangle, \nEnter a length . . .\n";
				cin >> length;
				cout << "Enter a width . . .\n";
				cin >> width;
				if (length >= 0 && width >= 0)
					cout << "* Area of your rectangle: " << length * width << endl;
				else
					cout << "Invalid input (cannot be a negative number).\n";
				break;
			case 3:
				float base;
				float height;
				cout << "\n(3) Area of Triangle, \nEnter a base . . .\n";
				cin >> base;
				cout << "Enter a height . . .\n";
				cin >> height;
				if (base >= 0 && height >= 0)
					cout << "* Area of your rectangle: " << base * height / 2 << endl;
				else
					cout << "Invalid input (cannot be a negative number).\n";
				break;
			case 4:
				cout << "\nYou have exited from Geometry Calculator.\n";
				break;
			default:
				cout << "\nInvalid number (must be 1-4). Try again.\n";
				break;
		}
	}
	return 0;
}