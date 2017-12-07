#include "Node.h"


    // Default constructor
Node::Node()
{
    int order = 6;              // default size 
    bool leaf = false;          // Not a leaf
    vector<int> Keys;           // key vector
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
		// something is wrong
	}
	}
	else
	{
		//not leaf insertion
	}
}

  // This function checks if the b+tree is full and returns true or false accordingly  
bool Node::isFull()
{
    if(Keys.size() + 1 >= order)    /**< If the size is greater than order */
        return true;
    else
        return false;
}

  //determines if leaf is node
bool Node::isLeaf()
{
    return leaf;    /**< Return boolean value if its a leaf or not */
}

 // returns node size
int Node::getSize()
{
    return (int)Keys.size();  /**< Returns size of the vector */
}

    //returns the key of  the entry record
int Node::getEntry(int index)
{
    if(0 <= index && index <= order)
        return Keys[index];
    else
        return -1;      /**< If could not find the entry */
}

// deletes entry
void Node::deleteEntry(int index)
{
	Keys.erase(Keys.begin() +  index);
	Records.erase(Records.begin() + index);
	// BTree must account for the changes
	// as well as prevent nodes of 0 size
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
	// BTree must account for the changes
	// as well as prevent nodes of 0 size
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
    vector<int>::iterator nodePos;

    if(isLeaf())
        for(nodePos = Records.begin() != nodePos; nodePos++)
            cout << Records[nodePos] << " ";
    cout << endl;
}

// points to right sibling
Node* Node::getRightSibling()
{
    return forward;
}
