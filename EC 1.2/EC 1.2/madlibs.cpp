#include <iostream>
using namespace std;
int main() {
	string instructor, name, food, number, adjective, color, animal;
	cout << "Enter the following...\n";
	cout << "The name of your instructor: ";
	cin >> instructor;
	cout << "Your name: ";
	cin >> name;
	cout << "A food: ";
	cin >> food;
	cout << "A number between 100 and 120: ";
	cin >> number;
	cout << "An adjective: ";
	cin >> adjective;
	cout << "A color: ";
	cin >> color;
	cout << "An animal: ";
	cin >> animal;
	cout << "Dear Instructor " << instructor << ",\n";
	cout << "I'm sorry that I am unable to turn in my homework at this time.";
	cout << " First, I ate a rotten " << food;
	cout << ", which made me turn " << color << " and\n";
	cout << "extremely ill. I came down with a fever of " << number;
	cout << ". Next, my " << adjective << " pet " << animal;
	cout << " must have smelled the remains\nof the " << food << " on my homework,";
	cout << " because he ate it. I am currently rewriting my homework and hope you ";
	cout << "accept it late.\n" << name;
	return 0;
}