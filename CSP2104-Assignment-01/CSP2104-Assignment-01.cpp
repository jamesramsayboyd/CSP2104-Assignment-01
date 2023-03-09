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
	// code to load dictionary file into STL vector
	//string delimiter = ".'/n'";
	//string delimiter = ".\/n";
	Dictionary.clear();
	fstream FileReader;
	FileReader.open(filename, ios::in);
	if (!FileReader) {
		cout << "Error opening the file" << endl;
	}
	else {
		cout << "File opened successfully" << endl;
		string skip;
		getline(FileReader, skip);
		getline(FileReader, skip);
		while (!FileReader.eof())
		{
			//Word newWord;
			//getline(FileReader, skip);
			//getline(FileReader, newWord.name);
			//string definition;
			//// read multi-line definition into string
			//newWord.definition = definition;
			//getline(FileReader, newWord.type);
			//getline(FileReader, skip);
			//Dictionary.push_back(newWord);

			getline(FileReader, skip);
			Word newWord;
			newWord.name = "name";
			newWord.type = "type";
			newWord.definition = "definition";
			Dictionary.push_back(newWord);
		}		
		FileReader.close();
	}
}

//Word ParseWord(string dictionaryData)
//{
//	Word newWord;
//}

void SearchForWord(vector<Word> Dictionary, string targetWord)
{
	for (int i = 0; i < Dictionary.size(); i++)
	{
		/*if (strcmp(Dictionary[i].name), targetWord)
		{
			PrintWordDetails(Dictionary[i]);
			break;
		}*/
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
			cout << Dictionary[0].name << endl;
			for (int i = 0; i < Dictionary.size(); i++)
			{
				//PrintWordDetails(Dictionary[i]);
				cout << Dictionary[i].name << endl;
			}
			break;
		case 2:
			cout << "Enter filename: " << endl;			
			break;
		case 3:
			cout << "Enter word: " << endl;
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

