#include <cstdlib>
#include <iostream>  // provides istream and ostream
#include <fstream> // input from file
#include <sstream>
#include <string.h> // provides strncmp()
#include "Replace.h"
#include "Kway.h" //Change this to .cpp for UNIX

using namespace std;
using namespace csci331_project1;

int main()
{
	int k;
	Kway P2;
	cout << "What sort of file is being sorted?";
	cin >> k;
  Replace P1(k);
  P1.setFileNames();
  P1.run();
  P2.Get_Inputs();
  P2.sort_and_create();
  return 0;
}
