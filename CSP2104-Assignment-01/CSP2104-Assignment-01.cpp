#include <iostream>

using namespace std;

struct Word 
{
	string name;
	string type;
	string definition;
};

int main()
{
	int userInput = 0;
	//const string DEFAULT_DICTIONARY_NAME = "dictionary_2023S1.txt";
	const string DEFAULT_DICTIONARY_NAME = "dictionary_test.txt";

	while (userInput != 6)
	{
		cout << "Welcome to the Dictionary" << endl;
		cout << "Press 1 to load the default Dictionary file" << endl;
		cout << "Press 2 to enter a specified Dictionary filename" << endl;
		cout << "Press 3 to search for a word" << endl;
		cout << "Press 4 to find all words containing more than three 'z' characters" << endl;
		cout << "Press 5 to add a word to the Dictionary" << endl;
		cout << "Press 6 to exit" << endl;

		cin >> userInput;

		switch (userInput)
		{
		case 1:
			cout << "Loading default dictionary..." << endl;
			LoadDictionary(DEFAULT_DICTIONARY_NAME);
			break;
		case 2:
			cout << "Enter filename: " << endl;			
			break;
		case 3:
			cout << "Enter word: " << endl;
			break;
		case 4:
			cout << "Displaying all words containing more than three 'z' characters: " << endl;
			break;
		case 5:
			cout << "Enter word: " << endl;
			break;
		case 6:
			cout << "Goodbye" << endl;
			break;
		default:
			break;
		}
	}
}

void LoadDictionary(string filename)
{
	// code to load dictionary file into STL vector
}

void SearchForWord(string targetWord)
{
	// code to search STL vector for target word
}

void FindThreeZs()
{
	// code to find word with three 'z' characters in STL vector
}

void AddWordToDictionary(Word addWord)
{
	// code to add word to STL vector
}