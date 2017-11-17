#ifndef REPLACE
#define REPLACE
#include <iostream>  // provides istream and ostream
#include <fstream> // input from file
#include <sstream>
#include <string.h> // provides strncmp()
#include <string>

namespace csci331_project1
{
  class Replace
  {
    public:
	int key_type;
		// what is signified by key_type...
		// input file format / output file sorted by
		// 0 integers/integers
		// 1 strings/strings
		// 2 integers-strings/integers
		// 3 integers-strings/strings
		// 4 strings-integers/integers
		// 5 strings-integers/strings
      Replace(int k){key_type=k; InputFile = 'x'; RunFile = 'y'; PointerFile = 'z';}

      void run();
      void setFileNames();
      //void getFiles();

    private:
      std::string InputFile;
      std::string RunFile;
      std::string PointerFile;

  };
}
#endif
