#include <cstdlib>
#include <iostream>  // provides istream and ostream
#include <fstream> // input from file
#include <sstream>
#include <string.h> // provides strncmp()
#include "Exec.cpp"

using namespace std;
using namespace csci331_project1;

int main()
{
  Exec P1;
  P1.setFileNames();
  P1.run_Replacement();
  P1.run_Kway();
  return 0;
}
