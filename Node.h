//jake
#ifndef _NODE
#define _NODE

#include <vector>
using std::vector;

class Node
{
private:
    bool leaf;              // leaf status
	  vector<Node*> Index;    // index pointers
	  Node* leftNode;         // points to leaf node

	  vector<int> Records;    // records pointed to by the leaf nodes

	  Node* forward;          // points to next node
	  Node* backward;         // points to previous node
	  int order;              // Tree order

public:
    // default constructor
    Node();

    //inserts the keys and records  for the file
    virtual void insert(int key, int record);

    //This function checks if the b+tree is full and returns true or false accordingly
    bool isFull();

    //determines if leaf is node
    bool isLeaf();
    
    //pointer where node should split
    Node* Split(int key);

    // returns node size
    int getSize();
    
    //returns the key of  the entry record
    int getEntry(int index);

    // deletes entry
    virtual void deleteEntry(int index);

    // deletes key
    virtual void deleteKey(int key);

    // Returns first key of node
	  int getFront();

    // Returns first key address of node
	  vector<int>* getFrontAddr();

    // Deletes the first key
	  void popFront();
    
    // points to left sibling
    Node* getLeftSibling();

    // Print positions of records
	  void printInfo();

    // points to right sibling
    Node* getRightSibling();
};
#endif
