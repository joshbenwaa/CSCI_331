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
    Key* ROOT; //Pointer to the root node of the B+Tree, Eldest Parent
    int        T_Size;
    int        int_or_string; //Integer for holding user choice for either integer or string manipulation
    string     in_file, out_file; //input and output file (string) names
   static int MAXBLOCKSIZE = 6; //Maximum number of records/keys that can be stored in a block

   struct Block //structure for blocks, make up leaf nodes of tree, holds records in the form of a list
   {
       bool leaf; //true if block is a leaf node, false if not


   };

    BTREE(int i_or_s, int Size, string InFile, string OutFile)
    {
      int_or_string = i_or_s; //Integer for holding user choice for either integer or string manipulation
      MAX_SIZE      = Size;
      in_file       = InFile; //File of input data
      out_file      = OutFile; //Output file
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
