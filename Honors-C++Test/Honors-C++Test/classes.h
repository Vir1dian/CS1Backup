#pragma once
using namespace std;

const int NUM_CATEGORY = 11, NUM_TYPE = 5, NUM_TEST_ITEMS = 38;
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
	/* // Still learning how constructors work
	Settings(int test_size, int difficulty, string categories[NUM_CATEGORY], string types[NUM_TYPE]) {
		m_test_size = test_size;
		m_difficulty = difficulty;
		for (int i = 0; i < NUM_CATEGORY; i++)
			m_categories[i] = categories[i];
		for (int i = 0; i < NUM_TYPE; i++)
			m_types[i] = types[i];
	}
	*/

	void select_settings();
	void show_settings();
	void reset_settings();
};

class Test_Item {
public:
	int m_number = 1;
	int m_type = 1;
	int m_difficulty = 1;
	int m_categories[NUM_CATEGORY] = {0};
	string m_question = "";
	string m_answers = "";
	string m_solution = "";

	/*
	Test_Item(int number, int type, int difficulty, int categories[NUM_CATEGORY], string question, string answers, string solution) {
		m_number = number;
		m_type = type;
		m_difficulty = difficulty;
		for (int i = 0; i < NUM_CATEGORY; i++)
			m_categories[i] = categories[i];
		m_question = question;
		m_answers = answers;
		m_solution = solution;
	}
	*/

	string get_type_name();
	string get_difficulty_name();
	string get_category_name(int index);

	// Function shuffle() creates a Test_Item_Shuffled object from this object if type is not "FIB" or "TOF"
	// Test_Item_Shuffled shuffle(); 
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