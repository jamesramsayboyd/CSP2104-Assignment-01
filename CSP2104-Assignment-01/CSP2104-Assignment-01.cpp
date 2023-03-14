#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Word.h"

using namespace std;

struct Word 
{
	string name;
	string definition;
	string type;
};

#pragma region FUNCTIONS

void LoadDictionary(vector<Word> Dictionary, string filename)
{
	Dictionary.clear();
	fstream FileReader;
	FileReader.open(filename, ios::in);
	if (!FileReader) {
		cout << "Error opening the file" << endl;
	}
	else {
		cout << "File opened successfully" << endl;
		string skipLine; // used to skip a line from the file (e.g. <word>, </word>, etc)
		getline(FileReader, skipLine);
		getline(FileReader, skipLine);
		while (!FileReader.eof())
		{
			getline(FileReader, skipLine);
			Word newWord;
			getline(FileReader, newWord.name);
			getline(FileReader, newWord.definition);
			getline(FileReader, newWord.type);
			getline(FileReader, skipLine);
			Dictionary.push_back(newWord);
		}		
		FileReader.close();
	}
}

void SearchForWord(vector<Word> Dictionary)
{
	string targetWord;
	cout << "Enter word: " << endl;
	cin >> targetWord;
	for (int i = 0; i < Dictionary.size(); i++)
	{
		int comparison = Dictionary[i].name.compare(targetWord);
		if (comparison == 0)
		{
			cout << "Word found: " << endl;
			PrintWordDetails(Dictionary[i]);
			break;
		}
		cout << "Word not found" << endl;
	}
}

void FindThreeZs(vector<Word> Dictionary)
{
	// code to find word with three 'z' characters in STL vector
	for (int i = 0; i < Dictionary.size(); i++)
	{
		/*if (strcmp(Dictionary[i].name), "zz")
		{
			cout << "Word found;" << endl;
			PrintWordDetails(Dictionary[i]);
		}*/
	}
}

void AddWordToDictionary(Word addWord)
{
	// code to add word to STL vector
}

void PrintWordDetails(Word word)
{
	cout << "Word: " << word.name << endl;
	cout << "Type: " << word.type << endl;
	cout << "Definition: " << word.definition << endl;
	cout << endl;
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
			SearchForWord(Dictionary);
			break;
		case 4:
			cout << "Displaying all words containing more than three 'z' characters: " << endl;
			FindThreeZs(Dictionary);
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

