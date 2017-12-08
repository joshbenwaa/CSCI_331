#include "Node.h" //jake
#ifndef BTREE_H
#define BTREE_H
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
  class BTree
  {
  private:
	  int order;
	  Node* ROOT;
  public:
	  /*
    //Node* ROOT; //Pointer to the root node of the B+Tree, Eldest Parent
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
	*/
    BTree();
	  
    BTree(int o);
	  
    ~BPTree();
	  
    void print();

    void insert(int record);
	  
    bool modify(int key, int record);
	  
    int search(int key);

    bool remove(int key);
	  
    bool verify();

    void rebuild();
};

#endif
