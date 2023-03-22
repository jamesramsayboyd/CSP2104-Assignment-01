#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include "Word.h"

using namespace std;

struct Word 
{
	string name;
	string definition;
	string type;
};

#pragma region FUNCTIONS

/* A function that prints the details of a word (name, type, definition)
to the console in a nicely formatted manner. Used repeatedly throughout 
the program */
void PrintWordDetails(Word word)
{
	cout << "Word: " << word.name << endl;
	cout << "Type: " << word.type << endl; // Add code to turn word.type ('n', 'v') into "Noun", "Verb", etc
	cout << "Definition: " << word.definition << endl;
	cout << endl;
}

/* A function to load the contents of a .txt file into the vector as objects of type Word
.txt file should be in format:
<word>
word name
word type
word definition
</word> */
// TODO: Consider making bool return type for successful/unsuccessful load
void LoadDictionary(vector<Word> *Dictionary, string filename)
{
	//*Dictionary.clear();
	Dictionary->clear();
	fstream FileReader;
	FileReader.open(filename, ios::in);
	if (!FileReader) {
		cout << "Error opening the file" << endl;
		return;
	}
	else {
		cout << "File opened successfully" << endl;
		string skipLine; // used to skip a line from the file (e.g. <word>, </word>, etc)
		getline(FileReader, skipLine);
		getline(FileReader, skipLine); // skipping first two lines of dictionary.txt file
		// TODO: Find a way of reading until '<word>', creating Word object, ending at '</word>', repeat
		while (!FileReader.eof())
		{
			getline(FileReader, skipLine);
			Word newWord;
			getline(FileReader, newWord.name);
			getline(FileReader, newWord.definition);
			getline(FileReader, newWord.type);
			getline(FileReader, skipLine);
			Dictionary->push_back(newWord);
		}		
		FileReader.close();
	}
}

/* A function to search for a user-entered word in the dictionary vector.
The user is prompted to enter a string token as a search target. The function then
loops through the dictionary comparing the name property of each Word object to
the user's search target. If a match is found, the for loop breaks and the word's
information is printed to the console */
bool SearchForWord(vector<Word> *Dictionary, string targetWord)
{
	/*string targetWord;
	cout << "Enter word: " << endl;
	cin >> targetWord;*/
	for (int i = 0; i < Dictionary->size(); i++)
	{	
		int comparison = (*Dictionary)[i].name.compare(targetWord); // TODO: Make comparison case-insensitive
		if (comparison == 0)
		{
			cout << "Word found: " << endl;
			PrintWordDetails((*Dictionary)[i]);
			// Consider returning a boolean from the function to indicate a successful/unsuccessful search
			return true;
			break;
		}
		//cout << "Word not found" << endl; // TODO: Follow user messaging sequence
		return false;
	}
}

/* A function that uses nested for loops to iterate through each character of each word
When a 'z' character is found, the integer 'zCounter' is increased by 1. If zCounter
reaches 3 or greater, the word details are displayed.*/
void FindThreeZs(vector<Word> *Dictionary)
{
	for (int i = 0; i < Dictionary->size(); i++)
	{
		int zCounter = 0;
		for (int j = 0; j < (*Dictionary)[i].name.size(); j++)
		{
			if ((*Dictionary)[i].name[j] == 'z')
			{
				zCounter++;
			}
			if (zCounter > 2)
			{
				PrintWordDetails((*Dictionary)[i]);
			}
		}
	}
}

/* A function that allows the user to add a word to the dictionary. The user is prompted
to enter a word name, a word type (chosen from a pre-defined list) and a definition. If valid, 
the word is */
void AddWordToDictionary(vector<Word> *Dictionary, string addWord)
{
	if (!SearchForWord(Dictionary, addWord))
	{
		Word wordToAdd;
		wordToAdd.name = addWord;
		cout << "Choose a word type:" << endl; // TODO: Add code allowing user to choose from a predefined list (verb, noun, etc)
		cin >> wordToAdd.type;
		cout << "Enter a definition:" << endl;
		cin >> wordToAdd.definition; // TODO: Capture entire line, not just single string token
	}
	else
	{
		//cout << "Word already exists in dictionary" << endl;
		return;
	}
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
			case 1: // Load default dictionary .txt file into vector<Word> data structure
			{
				cout << "Loading default dictionary..." << endl;
				LoadDictionary(&Dictionary, DEFAULT_DICTIONARY_NAME);
				PrintWordDetails(Dictionary[0]);
				break;
			}
			case 2: // Load a user-specified .txt file into vector<Word> data structure
			{
				string filename;
				cout << "Enter filename: " << endl;
				LoadDictionary(&Dictionary, filename);
				cout << "Dictionary " << filename << " loaded" << endl;
				break;
				// TODO: Error trapping for file not found
			}
			case 3: // User is prompted to search for a word in the dictionary
			{
				string targetWord;
				cout << "Enter word:" << endl;
				cin >> targetWord;
				SearchForWord(&Dictionary, targetWord);
				break;
			}
			case 4: // Displays any/all words in the dictionary containing more than three 'z' characters
			{
				cout << "Displaying all words containing more than three 'z' characters: " << endl;
				FindThreeZs(&Dictionary);
				break;
			}
			case 5: // User is prompted to add a word to the dictionary
			{
				string addWord;
				cout << "Enter word: " << endl;
				cin >> addWord;
				AddWordToDictionary(&Dictionary, addWord);
				break;
			}
			case 6: // User chooses to exit the program
			{
				cout << "Goodbye" << endl;
				break;
			}
			default:
				break;
		}
	}
}

