#include <iostream>
#include <iomanip>
#include <array>
#include "TestSettings.h"
using namespace std;

class Item {
public:
	string question;

};
class Item_Conceptual : public Item {
	string answers[4];
};


struct Test {
	Item question;
};

int main() {
	const int NUM_CATEGORY = 11, NUM_TYPE = 5;
	int test_size, difficulty, confirm;
	string categories[NUM_CATEGORY], types[NUM_TYPE];

	cout << "\n*** C++ Test by Gavin Torrecampo ***\n";
	do {
		set_settings(test_size, difficulty, categories, types);
		show_settings(test_size, difficulty, categories, types);
		cout << "\n* Confirm settings? (0 no, 1 yes) *\n";
		cin >> confirm;
	} while (confirm != 1);



	return 0;
}