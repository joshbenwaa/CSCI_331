#include <cstdlib>
#include <iostream>  // provides istream and ostream
#include <fstream> // input from file
#include <sstream>
#include <string.h> // provides strncmp()
#include "Replace.cpp" //Change this to .cpp for Unix, .h for windows
#include "Kway.cpp" //Change this to .cpp for UNIX, .h for windows

using namespace std;
using namespace csci331_project1;

int main()
{
	int k;
	// what is signified by key_type...
	// input file format / output file sorted by
	// 0 integers/integers
	// 1 strings/strings
	// 2 integers-strings/integers
	// 3 integers-strings/strings
	// 4 strings-integers/integers
	// 5 strings-integers/strings
	cout << "What sort of file is being sorted?";
	cout << "\n0 -> Integers   1 -> Strings\n2 -> Pairs(Int,String) sorted by Integers     3 -> Pairs(Int,String) sorted by Strings\n4 -> Pairs(Strings,Ints) sorted by Integers   5 -> Pairs(Strings,Ints) sorted by Strings\nEnter Value: ";
	cin >> k;
	Replace P1(k);
	Kway P2(k);
	P1.setFileNames();
	P1.run();
	P2.Get_Inputs(P1.RunFile);
	P2.sort_and_create();
  return 0;
}
