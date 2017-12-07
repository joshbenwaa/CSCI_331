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
	char ch;
	bool flag = true;
	cout << "Would you like to sort by integers (enter number > 0) \n or by strings (enter number <1)?";
	cin >> int_or_string;
	List l(int_or_string);
	while (flag)
	{
        cout<< " i = insert \n r = remove \n p = print \n s = search \n o = ordered print \n b = bottom , t = top \n";
		cout << "Please enter a command:";
		cin >> ch;
		if (ch == 'i') // insert
		{
			cout << "Please enter an integer to insert:";
			cin >> entry_i;
			cout << "Please enter a string to insert:";
			cin >> entry_s;
			l.insert(entry_i, entry_s, NULL, NULL);
		}
		else if (ch == 'r') // remove
		{
			cout << "Please enter an integer to remove:";
			cin >> entry_i;
			cout << "Please enter a string to remove:";
			cin >> entry_s;
			l.remove(entry_i, entry_s);
		}
		else if (ch == 'l') // length
			cout << "The length of the list is " << l.length() << endl;
		else if (ch == 'p') // print
			l.print(cout);
		else if (ch == 'o') // ordered print
			l.print_sequence(cout);
		else if (ch == 's') //search
		{
			cout << "Please enter an integer to search:";
			cin >> entry_i;
			cout << "Please enter a string to search:";
			cin >> entry_s;
			l.external_search(entry_i, entry_s);
		}
		else if (ch == 'b') // bottom
			cout << l.low_key_int() << ' ' << l.low_key_string() << endl;
		else if (ch == 't') // top
			cout << l.high_key_int() << ' ' << l.high_key_string() << endl;
		else
			flag = false;

	}
	return 0;
}
