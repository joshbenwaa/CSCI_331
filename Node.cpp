//Jake and Justin
#include <vector>
#include "Node.h"


    // Default constructor
Node()
{
    int order = 6;               // default size, order generally refers to the number of children a node can have
    bool leaf = false;          // Not a leaf
    std::vector<int> Keys;     // key vector
}

//inserts the keys and records  for the file
void Node::insert(int key, int record)
{
	if(isLeaf())
	{
	if(getSize()+1 < order)
	{
		Keys.push_back(key);
		Records.push_back(record);
	}
	else
	{

	}
};

  // This function checks if the b+tree is full and returns true or false accordingly
bool Node::isFull()
{
    if(Keys.size() + 1 >= order)    // if size is greater than order
        return true;
    else
        return false;
}

  //determines if leaf is node
bool Node::isLeaf()
{
    return leaf;
}

 // returns node size
int Node::getSize()
{
    return (int)Keys.size();
}

    //returns the key of  the entry record
int Node::getEntry(int index)
{
    if(0 <= index && index <= order)
        return Keys[index];
    else
        return -1;      // entry can't be found
}

// deletes entry
void Node::deleteEntry(int index)
{
	Keys.erase(Keys.begin() +  index);
	Records.erase(Records.begin() + index);
}

    // deletes key
void Node::deleteKey(int k)
{
	for(int i = 0; i < order; i++)
	{
		if(Keys[i] == k)
		{
			Keys.erase(Keys.begin() + i);
			Records.erase(Records.begin() + i);
			return;
		}
	}
}

    // Returns first key of node
int Node::getFront()
{
	return Records.front();
}

    // Returns first key address of node
vector<int>* Node::getFrontAddr()
{
	return &Records;
}

    // Deletes the first key
void Node:: popFront()
{
	Records.erase(Records.begin());
}

// points to left sibling
Node* Node::getLeftSibling()
{
    return backward;
}



   // Print positions of records
void Node::printInfo()
{
    vector<int>::iterator position;

    if(isLeaf())
        for(position = Records.begin() != position; position++)
            cout << Records[position] << " ";
    cout << endl;
}

// points to right sibling
Node* Node::getRightSibling()
{
    return forward;
}
