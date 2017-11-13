#ifndef EXEC_H
#define EXEC_H
#include <iostream>  // provides istream and ostream
#include <fstream> // input from file
#include <sstream>
#include <string.h> // provides strncmp()
#include <string>

namespace csci331_project1
{
  class Exec
  {
    public:

      Exec(){InputFile = 'x'; RunFile = 'y'; PointerFile = 'z';}

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
