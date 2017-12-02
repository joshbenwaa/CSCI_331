#include <cstdlib>
#include <iostream>
#include <string>
#include "List.h"
using namespace std;
using namespace csci331;

int main()
{
	int entry_i;
	string entry_s;
	int int_or_string;
	cout << "Would you like to sort by integers (enter number > 0) or by strings (enter number <1)?";
	cin >> int_or_string;
	List l(int_or_string);
	char ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		cout << "Please enter an integer to insert:";
		cin >> entry_i;
		cout << "Please enter a string to insert:";
		cin >> entry_s;
		l.insert(entry_i, entry_s);
		cout << "Would you like to continue (y/n)?";
		cin >> ch;
	}
	cout << "The length of the list is " << l.length() << endl;
	l.print(cout);
	cin >> ch;

	return 0;
}