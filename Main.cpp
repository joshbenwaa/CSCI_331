// CSCI331 Project 1
// Anthony Bloch
// CSCI 301: Section 1
// Project 2: Ordered List Class
// Due datae: 1.31.2017
// This is the main program file that uses the ordered list class
// File name: List_program.cpp

// This is an interactive test program for the List class as
// provided by List_header.h. The program responds to commands
// from the user to exercise three instances of the List class,
// and it assumes that those commands are correct as described
// in the menu() function.

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "List.cpp"
using namespace std;
using namespace csci301_list;

const int LISTS = 4; // The number(-1) of Lists the program manipulates

					 // Prototypes for functions in this program:

void menu();
// POSTCONDITION: A menu of commands and intructions for their
// use has been written to cout.

int main()
{
	char command;		// Each command letter
	int v;			// Each value in a command
	int n, n1, n2, n3; 	// List indexes in commands

	List l[LISTS]; 		// An array of Lists
	for (int i = 1; i<4; ++i)
		l[i].make_empty();
	menu();			// Show the menu
	do
	{
		cout << "--> ";	// Issue a prompt
		cin >> command;	// Read a command letter
		switch (command)// Carry out the command
		{
		case 'e': cin >> n;
			l[n].make_empty();
			break;
		case 'i': cin >> v >> n;
			l[n].insert(v);
			break;
		case 'r': cin >> v >> n;
			l[n].remove(v);
			break;
		case 's': cin >> n;
			cout << "List " << setw(1) << n << " contains " << setw(1) << l[n].size() << " item(s)." << endl;
			break;
		case 'o': 	cin >> v >> n;
			if (l[n].search(v) == 1)
				cout << "List " << setw(1) << n << " contains the value " << setw(1) << v << "." << endl;
			else
				cout << "List " << setw(1) << n << " does not contain the value " << setw(1) << v << "." << endl;
			break;
		case 'u': cin >> n1 >> n2 >> n3;
			l[n3] = l[n1] + l[n2];
			break;

		case 'd': cin >> v >> n;
			if (v <= l[n].size())
				cout << "The value of item number " << v << " in List " << n << " is " << setw(1) << l[n].element_value(v) << "." << endl;
			else
				cout << "List " << setw(1) << n << " does not have " << setw(1) << v << " item(s).\n";
			break;
					else
						cout << "List " << setw(1) << n << " contains " << setw(1) << l[n].size() << " item(s)." << endl;
						break;
		case 'w': cin >> n;
			cout << "List " << setw(1) << n << ": " << l[n] << endl;
			break;

		case 'h': menu();
			break;

		default:; // Null statement for an incorrect command
		}
	} while (command != 'q');

	return EXIT_SUCCESS;
}

void menu()
{
	cout << endl;
	cout << "This program responds to commands the user enters to" << endl;
	cout << "manipulate " << setw(1) << LISTS - 1 << " Lists (multisets),"
		<< "  which are initially" << endl;
	cout << "empty. In the following commands, v is any integer, and" << endl;
	cout << "n , n1, n2, and n3 are numbers of Lists; they may only be" << endl;
	cout << "integers from 1 to " << setw(1) << LISTS - 1 << '.' << endl << endl;
	cout << "  e n   -- Re-initialize List n to be empty." << endl;
	cout << "  i v n -- Insert the value v into List n." << endl;
	cout << "  r v n -- Remove the value v from List n." << endl;
	cout << "  s n   -- Report the size of List n." << endl;
	cout << "  o v n -- Report whether or not the value v" << endl
		<< "           occurs in List n." << endl;
	cout << "  u n1 n2 n3 -- Form the union of List n1 and List n2" << endl
		<< "                and put the union in List n3." << endl;
	cout << "  d v n -- Display the value of item v in List n." << endl;
	cout << "  w n -- Write out the contents of List n." << endl;
	cout << "  h -- See this menu." << endl;
	cout << "  q -- Quit the program." << endl << endl;
}

