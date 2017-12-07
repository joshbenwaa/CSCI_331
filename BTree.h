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

 struct Node //structure for keys, copied from List.h/replace or interchange with block
		{
			int value_i; //Key value
			string value_s; //set to null if just key node
			Node* ancestor;
			Node* child;
			//Node* prev_sibling;
			//Node* next_sibling;
			Node* prev_sequence;
			Node* next_sequence;
			bool ROOT; // true if node is the root of the b+tree
		};

   struct Block //structure for blocks, made up leaf nodes of tree, holds records in the form of a list
   {
       //bool leaf; //true if block is a leaf node
       Node* parent; //pointer to the parent node of the block
       Block* next_sibling; // sibling block(node) to the right
       Block*  prev_sequence; // sibling block(node) to the left
       int BlockSize;//Number of records currently stored in the block, restricted to my MAXBLOCKSIZE

   };
   struct record
   {
       string record[];
       int key;
    };

    BTREE(int i_or_s, int Size, string InFile, string OutFile)
    {
      int_or_string = i_or_s; //Integer for holding user choice for either integer or string manipulation
      MAX_SIZE      = Size;
      in_file       = InFile; //File of input data
      out_file      = OutFile; //Output file
    }


    insert(const int record)///jake
    {
    	int middle;       // middle value of the node 
    	Node* newNode;      // pointer to new Node 
    	Node* parentNode;   // pointer to parent
	
	
    	newNode = ROOT;     // newNode points to root
    	newNode -> insert(record, record);      // insert records into root

    	if(newNode->isFull())  // check against node overfill
    	{
        	Node* leftNode = new Node();    // create new node to left
        	middle = newNode->getSize()/2;       // find the middle of the node
		int nPos = 0;                   // starting position of the node
        	for(; nPos != middle; nPos++)        
        	{
            		leftNode->insert(newNode->getFront(), newNode->getFront()); // copy values from front of node
            		newNode->popFront();        // Pop off of current vector
       	 	}
		Node* newParentNode = new Node();  // new parent node
		parentNode = newParentNode;            // point new parent here
        	parentNode->insert(newNode->getFront(),newNode->getFront());  //Copy to old parent node
    	}
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
