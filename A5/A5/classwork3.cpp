#include<iostream>
using namespace std;

int getProfit(string);
void findLowest(int, int, int, int, int&, string&);
void findHighest(int, int, int, int, int&, string&);

int main() {
	int east = getProfit("East");
	int west = getProfit("West");
	int north = getProfit("North");
	int south = getProfit("South");
	int highest, lowest;
	string hregion, lregion;
	findLowest(east, west, north, south, lowest, lregion);
	findHighest(east, west, north, south, highest, hregion);
	cout << "The region with the highest profit is " << hregion << " at $" << highest << ".\n";
	if (lowest < 0)
		cout << "The " << lregion << " lost $" << lowest * -1 << ".\n";
	else 
		cout << "The region with the lowest profit is " << lregion << " at $" << lowest << ".\n";
	return 0;
}

int getProfit(string region) {
	cout << "Enter reported profit from " << region << " .\n";
	int numAcc;
	cin >> numAcc;
	return numAcc;
}

void findLowest(int a, int b, int c, int d, int &lowest, string &lregion) {
	lowest = a;
	lregion = "East";
	if (lowest > b) {
		lowest = b;
		lregion = "West";
	}
	if (lowest > c) {
		lowest = c;
		lregion = "North";
	}
	if (lowest > d) {
		lowest = d;
		lregion = "South";
	}
}

void findHighest(int a, int b, int c, int d, int& highest, string& hregion) {
	highest = a;
	hregion = "East";
	if (highest < b) {
		highest = b;
		hregion = "West";
	}
	if (highest < c) {
		highest = c;
		hregion = "North";
	}
	if (highest < d) {
		highest = d;
		hregion = "South";
	}
}