#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main4() {
	ifstream fin;
	string line;
	fin.open("poem.txt");
	if (fin.good()) {
		while (getline(fin, line))
			cout << line << endl;
		fin.close();
	}
	else {
		cout << "Error" << endl;
		exit(EXIT_FAILURE);
	}
	return 0;
}