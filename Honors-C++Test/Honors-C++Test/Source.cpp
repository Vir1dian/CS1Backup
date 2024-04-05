#include <iostream>
#include <iomanip>
#include <fstream>
#include "TestSettings.h"
using namespace std;

int main() {
	Settings my_settings;
	int confirm;

	cout << "\n*** C++ Test by Gavin Torrecampo ***\n";
	do {
		my_settings.select_settings();
		my_settings.show_settings();
		cout << "\n* Confirm settings? (0 no, 1 yes) *\n";
		cin >> confirm;
	} while (confirm != 1);



	return 0;
}