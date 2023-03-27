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
void PrintWordDetails(vector<Word>* Dictionary, int index)
{
	if (index < 0)
	{
		cout << "Word not found" << endl;
	}
	else
	{
		Word word = (*Dictionary)[index];
		cout << "Word: " << word.name << endl;
		cout << "Type: ";
		if (word.type == "n")
		{
			cout << "[noun]" << endl;
		}
		else if (word.type == "v")
		{
			cout << "[verb]" << endl;
		}
		else if (word.type == "adv")
		{
			cout << "[adverb]" << endl;
		}
		else if (word.type == "adj")
		{
			cout << "[adjective]" << endl;
		}
		else if (word.type == "prep")
		{
			cout << "[preposition]" << endl;
		}
		else if (word.type == "misc")
		{
			cout << "[miscellaneous]" << endl;
		}
		else if (word.type == "pn")
		{
			cout << "[proper noun]" << endl;
		}
		else if (word.type == "n_and_v")
		{
			cout << "[noun and verb]" << endl;
		}
		else
		{
			cout << "[unknown]" << endl;
		}
		cout << "Definition: " << word.definition << endl;
	}	
}

/* A function to load the contents of a .txt file into the vector as objects of type Word
.txt file should be in format:
<word>
word name
word type
word definition
</word> 
etc */
bool LoadDictionary(vector<Word> *Dictionary, string filename)
{
	Dictionary->clear();
	fstream FileReader;
	FileReader.open(filename, ios::in);
	if (!FileReader) {
		return false;
	}
	else {
		cout << "Loading file \"" << filename << "\"..." << endl;
		while (!FileReader.eof())
		{
			string line;
			getline(FileReader, line);
			if (line == "<word>")
			{
				Word newWord;
				getline(FileReader, newWord.name);
				getline(FileReader, newWord.definition);
				getline(FileReader, newWord.type);
				Dictionary->push_back(newWord);
			}
		}		
		FileReader.close();
		return true;
	}
}

/* A function to search for a user-entered word in the dictionary vector. The function then
uses a binary search algorithm to search for the word in the dictionary. If a match 
is found, the word's information is printed to the console. The function returns a 
boolean so it can be used within other functions (e.g. the AddWord() function that
checks whether a word to be added already exists within the dictionary) */
int SearchForWord(vector<Word>* Dictionary, string targetWord)
{
	for (int i = 0; i < targetWord.length(); i++)
	{
		targetWord[i] = tolower(targetWord[i]); // Converting search target to all lower case for case-insensitive searches
	}
	int lowerBound = 0;
	int upperBound = Dictionary->size();
	int mid = 0;
	bool found = false;

	while (lowerBound < upperBound)
	{
		mid = (upperBound + lowerBound) / 2;
		string midWord = (*Dictionary)[mid].name;
		if (!isalpha(midWord[0])) // Extra check needed because some words in the provided dictionary file start with a "-" character
		{
			midWord = midWord.substr(1, -1);
		}
		int comparison = (midWord.compare(targetWord));
		if (comparison == 0)
		{
			return mid;
		}
		else if (comparison < 0)
		{
			lowerBound = mid + 1;
		}
		else
		{
			upperBound = mid;
		}
	}

	if (!found)
	{
		return -1;
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
		}
		if (zCounter > 2)
		{
			PrintWordDetails(Dictionary, i);
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
		int wordTypeChoice;
		Word wordToAdd;
		wordToAdd.name = addWord;

		cout << "Choose a word type:" << endl;
		cout << "1: Noun  2: Verb  3: Adverb  4: Adjective  5: Preposition  6: Miscellaneous  7: Proper Noun  8: Noun and Verb" << endl;
		cin >> wordTypeChoice;
		switch (wordTypeChoice)
		{
			case 1:
				wordToAdd.type = "n";
				break;
			case 2:
				wordToAdd.type = "v";
				break;
			case 3:
				wordToAdd.type = "adv";
				break;
			case 4:
				wordToAdd.type = "adj";
				break;
			case 5:
				wordToAdd.type = "prep";
				break;
			case 6:
				wordToAdd.type = "misc";
				break;
			case 7:
				wordToAdd.type = "pn";
				break;
			case 8:
				wordToAdd.type = "n_and_v";
				break;
			default:
				break;
		}
		cout << "Enter a definition:" << endl;
		cin >> wordToAdd.definition; // TODO: Capture entire line, not just single string token
		Dictionary->push_back(wordToAdd);
		// TODO: Add code to save the dictionary file with a user-provided filename
	}
	else
	{
		cout << "ERROR: Word exists, elevated privileges required to edit existing words" << endl;
		return;
	}
}

bool CheckForValidInput(int min, int max, int userInput)
{
	if (userInput > min && userInput <= max) {
		return true;
	}
	else {
		return false;
	}
}
#pragma endregion FUNCTIONS

int main()
{
	vector<Word> Dictionary;
	bool running = true;
	bool fileLoaded = false;
	int userInput = 0;
	//const string DEFAULT_DICTIONARY_NAME = "dictionary_2023S1.txt";
	const string DEFAULT_DICTIONARY_NAME = "dictionary_test.txt";

	cout << "Welcome to the Dictionary" << endl;

	while (running)
	{
		if (!fileLoaded)
		{
			cout << endl;
			cout << "Press 1 to load the default Dictionary file" << endl;
			cout << "Press 2 to enter a specified Dictionary filename" << endl;
			cout << "Press 3 to exit" << endl;
			cout << endl;

			// Filters out non-integer input. TODO: Limit it to between 1 and 3
			while (!(cin >> userInput))
			{
				cin.clear();
				string temp;
				cin >> temp; // Creating a temp variable to store the invalid input without using it
				cout << "ERROR: Please enter an integer between 1 and 3" << endl;
				cout << endl;
			}

			switch (userInput)
			{
			case 1: // Load default dictionary .txt file into vector<Word> data structure
			{
				if (LoadDictionary(&Dictionary, DEFAULT_DICTIONARY_NAME))
				{
					fileLoaded = true;
					cout << "File loaded successfully" << endl;
				}
				break;
			}
			case 2: // Load a user-specified .txt file into vector<Word> data structure
			{
				string filename;
				cout << "Enter filename: " << endl;
				cin >> filename;
				if (!LoadDictionary(&Dictionary, filename))
				{
					cout << "ERROR: File not found" << endl;
				}
				else
				{
					fileLoaded = true;
					cout << "File loaded successfully" << endl;
				}
				break;
			}
			case 3:
			{
				cout << "Goodbye" << endl;
				running = false;
				break;
			}
			default:
				break;
			}
		}

		else
		{
			cout << endl;
			cout << "Press 1 to search for a word" << endl;
			cout << "Press 2 to find all words containing more than three 'z' characters" << endl;
			cout << "Press 3 to add a word to the Dictionary" << endl;
			cout << "Press 4 to load a different Dictionary file" << endl;
			cout << "Press 5 to exit" << endl;
			cout << endl;

			cin >> userInput;
			/*if (cin.fail())
			{
				cout << "Please enter a valid integer between 1 and 6" << endl;
				cin.clear();
				cin >> userInput;
			}*/

			switch (userInput)
			{
			case 1: // User is prompted to search for a word in the dictionary
			{
				string targetWord;
				cout << "Enter word:" << endl;
				cin >> targetWord;
				int printIndex = SearchForWord(&Dictionary, targetWord);
				PrintWordDetails(&Dictionary, printIndex);
				break;
			}
			case 2: // Displays any/all words in the dictionary containing more than three 'z' characters
			{
				cout << "Displaying all words containing more than three 'z' characters: " << endl;
				FindThreeZs(&Dictionary);
				break;
			}
			case 3: // User is prompted to add a word to the dictionary
			{
				string addWord;
				cout << "Enter word: " << endl;
				cin >> addWord;
				AddWordToDictionary(&Dictionary, addWord);
				break;
			}
			case 4: // User can return to the initial menu to load a different dictionary file
			{
				fileLoaded = false;
				break;
			}
			case 5: // User chooses to exit the program
			{
				cout << "Goodbye" << endl;
				running = false;
				break;
			}
			default:
				break;
			}
		}
	}
}

