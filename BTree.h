#ifndef BTREE_H
#define BTREE_H
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
namespace csci331
{
  class BTree
  {
  public:
    Key* ROOT;
    static int MAX_SIZE;
    int        T_Size;
    int        int_or_string;
    string     in_file, out_file;

    BTREE(int i_or_s, int Size, string InFile, string OutFile)
    {
      int_or_string = i_or_s;
      MAX_SIZE      = Size;
      in_file       = InFile;
      out_file      = OutFile;
      T_Size        = 1;
    }




    insert()
    {

    }

    remove()
    {

    }


    Print_All()
    {

    }

    Modify_Record()
    {

    }

    Verify()
    {

    }


    Rebuild()
    {

    }

    Search()
    {

    }

    Return_Size()
    {

    }
  }
}
