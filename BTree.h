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
    Node* ROOT; //Pointer to the root node of the B+Tree, Eldest Parent
    int        T_Size;
    int        int_or_string; //Integer for holding user choice for either integer or string manipulation
    string     in_file, out_file; //input and output file (string) names
   static int MAXBLOCKSIZE = 6; //Maximum number of records/keys that can be stored in a block

 struct Node //structure for keys, copied from List.h
		{
			int value_i;
			string value_s;
			Node* ancestor;
			Node* child;
			Node* prev_sibling;
			Node* next_sibling;
			Node* prev_sequence;
			Node* next_sequence;
		};

   struct Block //structure for blocks, make up leaf nodes of tree, holds records in the form of a list
   {
       bool leaf; //true if block is a leaf node
       bool ROOT; // true if block is the root of the b+tree
       Node* parent; //Parent node of the block
       Block* next_sibling; // sibling block(node) to the right
       Block*  prev_sequence; // sibling block(node) to the left

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
    l.insert(entry_i, entry_s, NULL, NULL); //same insert as the list main program
    }

    remove()
    {
    l.remove(entry_i, entry_s); //same insert as the list main program
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
