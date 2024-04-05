#pragma once
using namespace std;

const int NUM_CATEGORY = 11, NUM_TYPE = 5, NUM_TEST_ITEMS = 3;
const string all_categories[NUM_CATEGORY] =
{ "Introduction/Other", "Making Decisions", "Loops", "Files",
	"Binary/Hexadecimal", "Functions", "Arrays", "Text Files",
	"C Strings/String", "Structures", "Binary Files" };
const string all_types[NUM_TYPE] = { "Conceptual", "Debugging", "Comparison", "FIB", "TOF" };

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

struct Test_Item {
	int number;
	string type;
	string difficulty;
	string categories[NUM_CATEGORY];
	string question;
	string answers;
	string solution;
};

// If the questions in the filtered pool is less than the size of the test, then other random questions are used to fill the empty space.