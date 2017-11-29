// Anthony Bloch
// CSCI 301 Section 1
// Project 5
// Due date: 3-2-2017
// This is the main program for a Ulist class represented 
// by an unordered list of characters linked by pointers. Each node contains a word 
// and pointers to the next and previous nodes.
// The program prompts the user for a line of input. '#' is treated as a backspace.
// The program then outputs the users input with any characters followed by '#' omitted.
// '#' can stack, so "##" will delete two characters. 
// file name: Ulist_program.cpp
//
#include <cstdlib>  
#include <iostream>  // provides istream and ostream
#include <fstream> // input from file
#include <string.h> // provides strncmp()
#include <ctype.h> // provides isalpha() and toupper()
#include "List.cpp"
using namespace std;
using namespace csci301_ulist;

int main()
{
	char ch;
	Ulist u;
	cout << "Please enter a string of characters (# can be used for backspacing):" << endl;
	cin.get(ch);
	while (ch >= ' ')
	{
		if (ch == '#')
			u.remove_last();
		else
			u.append(ch);
		cin.get(ch);
	}
	cout << "You entered: " << u << endl;

	return 0;

}
