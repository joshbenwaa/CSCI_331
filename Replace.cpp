#include <cstdlib>
#include <iostream>  // provides istream and ostream
#include <fstream> // input from file
#include <sstream>
#include <string.h> // provides strncmp()
#include "Replace.h"
#include "Heap.cpp"
using namespace std;

namespace csci331_project1
{
  void Replace::run()
  {
    	string s_temp, s_last_output;
   	int data, i_temp, i_last_output, len;
  	int max = 8;
  	int initialize = 0;
  	Heap<string> s_buf(0,8);
	Heap<int> i_buf(0,8);
	Heap<int> buf(0,8);
  	bool flag=true;
  	bool success;
  	bool switching = false;
    ifstream in_file;
  	ofstream out_file, pointer_out_file;
    in_file.open(InputFile.c_str());
  	out_file.open(RunFile.c_str());
  	pointer_out_file.open(PointerFile.c_str());
	if(key_type==0)
		in_file >> i_temp;
	else
	{
		in_file>>s_temp;
		if(key_type==3||key_type==4)
		{
			len=s_temp.size()/2;
			for(int i=0; i<len; i++)
				swap(s_temp[i],s_temp[i+len]);
		}
				
	}
  	while (!in_file.eof())
  	{
  		if (initialize < max) // initially filling the buffer
  		{
  			if (initialize == 0)
  			{
  				data = out_file.tellp(); // output pointer pointer to run
  				pointer_out_file << data << endl;
  			}
  			if(key_type==0)
				success = i_buf.insert(i_temp, flag);
			else
				success = s_buf.insert(s_temp, flag);
  			++initialize;
  		}
  		else
  		{
  			if (switching) // if the active heap was just emptied...
  			{
				if(key_type==0)
  					if (i_last_output < i_temp) // check to see if it's possible to send input straight to output
  						out_file << i_temp << ' ';			
  					else
  					{
  						switching = false; // no longer switching
  						flag = !flag; // change active heap
  						out_file << endl; // new run
  						data = out_file.tellp(); // output pointer to new run
  						pointer_out_file << data << endl;
  						i_last_output = i_buf.remove_root(flag);
  						out_file << i_last_output << ' ';
  						if (i_last_output < i_temp) // check if input is to be added to active heap
  						{
  							success = i_buf.insert(i_temp, flag);
  						}
  						else
  						{
  							success = i_buf.insert(i_temp, !flag);
  						}
  					}
				else
					if (s_last_output < s_temp) // check to see if it's possible to send input straight to output
						if(key_type==3||key_type==5)
						{
							len=s_temp.size()/2;
							for(int i=0; i<len; i++)
								swap(s_temp[i],s_temp[i+len]);
							out_file << s_temp << ' ';
							for(int i=0; i<len; i++)
								swap(s_temp[i],s_temp[i+len]);
						}
						else
							out_file << s_temp << ' ';
  					else
  					{
  						switching = false; // no longer switching
  						flag = !flag; // change active heap
  						out_file << endl; // new run
  						data = out_file.tellp(); // output pointer to new run
  						pointer_out_file << data << endl;
  						s_last_output = s_buf.remove_root(flag);
						if(key_type==3||key_type==5)
						{
							len=s_last_output.size()/2;
							for(int i=0; i<len; i++)
								swap(s_last_output[i],s_last_output[i+len]);
							out_file << s_last_output << ' ';
							for(int i=0; i<len; i++)
								swap(s_last_output[i],s_last_output[i+len]);
						}
						else
							out_file << s_last_output << ' ';
  						if (s_last_output < s_temp) // check if input is to be added to active heap
  						{
  							success = s_buf.insert(s_temp, flag);
  						}
  						else
  						{
  							success = s_buf.insert(s_temp, !flag);
  						}
  					}
  			}
  			else
  			{
				if(key_type==0)
				{
  					i_last_output = i_buf.remove_root(flag);
  					out_file << i_last_output << ' '; // output next entry in run
  					if (i_last_output < i_temp) // check if new input is to be added to active heap
  					{
  						success = i_buf.insert(i_temp, flag);
  					}
  					else
  					{
  						success = i_buf.insert(i_temp, !flag);
  						if (i_buf.size(flag) < 1) // check if active heap just became empty
  							switching = true;
  					}
				}
				else
				{
  					s_last_output = s_buf.remove_root(flag);
					if(key_type==3||key_type==5)
					{
						len=s_last_output.size()/2;
						for(int i=0; i<len; i++)
							swap(s_last_output[i],s_last_output[i+len]);
						out_file << s_last_output << ' ';
						for(int i=0; i<len; i++)
							swap(s_last_output[i],s_last_output[i+len]);
					}
					else
						out_file << s_last_output << ' ';
  					if (s_last_output < s_temp) // check if new input is to be added to active heap
  					{
  						success = s_buf.insert(s_temp, flag);
  					}
  					else
  					{
  						success = s_buf.insert(s_temp, !flag);
  						if (s_buf.size(flag) < 1) // check if active heap just became empty
  							switching = true;
  					}
				}
  			}
  		}
		if(key_type==0)
			in_file >> i_temp;
		else
		{
			in_file>>s_temp;
			if(key_type==3||key_type==4)
			{
				len=s_temp.size()/2;
				for(int i=0; i<len; i++)
					swap(s_temp[i],s_temp[i+len]);
			}
					
		}
  	}
  	in_file.close();
  	while (i_buf.size(flag) > 0||s_buf.size(flag)>0) // finish active heap
  	{
		if(key_type==0)
		{
  			i_last_output = i_buf.remove_root(flag);
  			out_file << i_last_output << ' ';
		}
		else
			s_last_output = s_buf.remove_root(flag);
			if(key_type==3||key_type==5)
			{
				len=s_last_output.size()/2;
				for(int i=0; i<len; i++)
					swap(s_last_output[i],s_last_output[i+len]);
				out_file << s_last_output << ' ';
				for(int i=0; i<len; i++)
					swap(s_last_output[i],s_last_output[i+len]);
			}
			else
				out_file << s_last_output << ' ';		
  	}
  	flag = !flag;
  	out_file << endl; // new run
  	data = out_file.tellp(); // output pointer to new run
  	pointer_out_file << data << endl;
  	while (buf.size(flag) > 0||s_buf.size(flag)>0) // finish what had been pending heap
  	{
		if(key_type==0)
		{
  			i_last_output = i_buf.remove_root(flag);
  			out_file << i_last_output << ' ';
		}
		else
			s_last_output = s_buf.remove_root(flag);
			if(key_type==3||key_type==5)
			{
				len=s_last_output.size()/2;
				for(int i=0; i<len; i++)
					swap(s_last_output[i],s_last_output[i+len]);
				out_file << s_last_output << ' ';
				for(int i=0; i<len; i++)
					swap(s_last_output[i],s_last_output[i+len]);
			}
			else
				out_file << s_last_output << ' ';
  	}
  	out_file.close();
  	pointer_out_file.close();
  }

  void Replace::setFileNames()
  {
    string IF, RF, PF;
    cout << "Please enter input file: ";
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
