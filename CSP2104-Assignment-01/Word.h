#pragma once

#include <string>

/* James Boyd, Student ID: 10629572, 7/3/2023
A structure to store the details of a word from a dictionary file provided 
by the user. The structure has three properties, all of type String: name, type
and definition. There are no methods. */
struct Word
{
	std::string name, type, definition;
};