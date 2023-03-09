#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Word.h"

using namespace std;

struct Word 
{
	string name;
	string type;
	string definition;
};

#pragma region FUNCTIONS

void LoadDictionary(vector<Word> vector, string filename)
{
	// code to load dictionary file into STL vector
	vector.clear();
	fstream FileReader;
	FileReader.open(filename, ios::in);
	if (!FileReader) {
		cout << "Error opening the file" << endl;
	}
	else {
		cout << "File opened successfully" << endl;
		string blank;
		getline(FileReader, blank);
		getline(FileReader, blank);
		while (!FileReader.eof())
		{
			//Word newWord;
			//getline(FileReader, blank);
			//getline(FileReader, newWord.name);
			//// code to read into vector
			//Word newWord;
			//vector.push_back(newWord);
		}		
		FileReader.close();
	}
}

Word ParseWord(string dictionaryData)
{
	Word newWord;

}

void SearchForWord(string targetWord)
{
	// code to search STL vector for target word
	string x;
	//getline(cin, x, '/n');
}

void FindThreeZs()
{
	// code to find word with three 'z' characters in STL vector
}

void AddWordToDictionary(Word addWord)
{
	// code to add word to STL vector
}

void PrintWordDetails(Word word)
{
	cout << word.name << endl;
	cout << word.definition << endl;
	cout << word.type << endl;
}
#pragma endregion FUNCTIONS

int main()
{
	vector<Word> Dictionary;
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

		cin >> userInput; // TODO: Filter out non-integer input

		switch (userInput)
		{
		case 1:
			cout << "Loading default dictionary..." << endl;
			LoadDictionary(Dictionary, DEFAULT_DICTIONARY_NAME);
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

