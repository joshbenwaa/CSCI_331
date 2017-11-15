#include <cstdlib>
#include <iostream>  // provides istream and ostream
#include <fstream> // input from file
#include <sstream>
#include <string.h> // provides strncmp()
#include "Exec.h"
#include "Heap.h"
using namespace std;

namespace csci331_project1
{
  void Exec::run()
  {
    string temp, last_output;
    int data;
  	int max = 8;
  	int initialize = 0;
  	Heap<string> buf;
  	bool flag=true;
  	bool success;
  	bool switching = false;
    ifstream in_file;
  	ofstream out_file, pointer_out_file;
    in_file.open(InputFile.c_str());
  	out_file.open(RunFile.c_str());
  	pointer_out_file.open(PointerFile.c_str());
  	in_file >> temp;
  	while (!in_file.eof())
  	{
  		if (initialize < max) // initially filling the buffer
  		{
  			if (initialize == 0)
  			{
  				data = out_file.tellp(); // output pointer pointer to run
  				pointer_out_file << data << endl;
  			}
  			success = buf.insert(temp, flag);
  			++initialize;
  		}
  		else
  		{
  			if (switching) // if the active heap was just emptied...
  			{
  				if (last_output < temp) // check to see if it's possible to send input straight to output
  					out_file << temp << ' ';
  				else
  				{
  					switching = false; // no longer switching
  					flag = !flag; // change active heap
  					out_file << endl; // new run
  					data = out_file.tellp(); // output pointer to new run
  					pointer_out_file << data << endl;
  					last_output = buf.remove_root(flag);
  					out_file << last_output << ' ';
  					if (last_output < temp) // check if input is to be added to active heap
  					{
  						success = buf.insert(temp, flag);
  					}
  					else
  					{
  						success = buf.insert(temp, !flag);
  					}
  				}
  			}
  			else
  			{
  				last_output = buf.remove_root(flag);
  				out_file << last_output << ' '; // output next entry in run
  				if (last_output < temp) // check if new input is to be added to active heap
  				{
  					success = buf.insert(temp, flag);
  				}
  				else
  				{
  					success = buf.insert(temp, !flag);
  					if (buf.size(flag) < 1) // check if active heap just became empty
  						switching = true;
  				}
  			}
  		}
  		in_file >> temp;
  	}
  	in_file.close();
  	while (buf.size(flag) > 0) // finish active heap
  	{
  		last_output = buf.remove_root(flag);
  		out_file << last_output << ' ';
  	}
  	flag = !flag;
  	out_file << endl; // new run
  	data = out_file.tellp(); // output pointer to new run
  	pointer_out_file << data << endl;
  	while (buf.size(flag) > 0) // finish what had been pending heap
  	{
  		last_output = buf.remove_root(flag);
  		out_file << last_output << ' ';
  	}
  	out_file.close();
  	pointer_out_file.close();
  }

  void Exec::setFileNames()
  {
    string IF, RF, PF;
    cout << "Pleas enter input file: ";
    cin >> IF;
    cout << endl << "Run File:  ";
    cin >> RF;
    cout << endl << "Pointer File: ";
    cin >> PF;
    InputFile = IF;
    RunFile = RF;
    PointerFile = PF;
  }

  /*void Exec::getFiles()
  {
    cout << "IF: " << InputFile << endl
         << "RF: " << RunFile << endl
         << "PF: " << PointerFile << endl;
  }*/
}
