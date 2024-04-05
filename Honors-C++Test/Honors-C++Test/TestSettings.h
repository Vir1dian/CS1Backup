#pragma once
#include <iomanip>
using namespace std;

const int NUM_CATEGORY = 11, NUM_TYPE = 5;

class Settings {

private:
	int m_test_size;
	int m_difficulty;
	string m_categories[NUM_CATEGORY];
	string m_types[NUM_TYPE];

public:
	void select_settings();
	void show_settings();
	void reset_settings();

};

// If the questions in the filtered pool is less than the size of the test, then other random questions are used to fill the empty space.