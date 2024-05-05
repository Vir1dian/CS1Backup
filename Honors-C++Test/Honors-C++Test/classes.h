#pragma once
using namespace std;

const int NUM_CATEGORY = 11, NUM_TYPE = 5, NUM_TEST_ITEMS = 38;
const string all_categories[NUM_CATEGORY] =
{ "Introduction/Other", "Making Decisions", "Loops", "Files",
	"Binary/Hexadecimal", "Functions", "Arrays", "Text Files",
	"C Strings/String", "Structures", "Binary Files" };
const string all_types[NUM_TYPE] = { "Conceptual", "Debugging", "Comparison", "FIB", "TOF" };

class Settings {
public:
	int m_test_size = 20;
	int m_difficulty = 1;
	int m_categories[NUM_CATEGORY] = { 0 };
	int m_types[NUM_TYPE] = { 0 };

	void select_settings();
	void show_settings();
	void reset_settings();
};

class Test_Item {
public:
	int m_number = 0;
	int m_type = 1;
	int m_difficulty = 1;
	int m_categories[NUM_CATEGORY] = {0};
	string m_question = "";
	string m_answers = "";
	string m_solution = "";

	string get_type_name() const;
	string get_difficulty_name() const;
	string get_category_name(int index) const;
};

// This class is used to enable multiple-choice answers to be shuffled when added to a test object
class Test_Item_Shuffled : public Test_Item {
public:
	char m_answers_shuffled[4]; // Random sequence of chars A - D
	char m_solution_shuffled;

	// Function shuffle() reshuffles the m_answers_shuffled array and reassigns m_solution_shuffled;
	// void shuffle(); 
};
// If the questions in the filtered pool is less than the size of the test, then other random questions are used to fill the empty space.
