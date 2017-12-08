/*BTree.cpp holds the implementation of B+tree methods */
#include "BTree.h"
#include "Node.h"
using namespace std;

namespace csci331_project2

BPTree()
{
    ROOT = new Node();
}
/*
BPTree::BPTree(int o)
{
    ROOT = new Node();
}
*/
BPTree::BPTree(vector<int> n, int o)
{
    ROOT = new Node();
}

/*BPTree::~BPTree()
{

}
*/

void BPTree::insert(int record)
{
    int middle;              // middle value of node
    Node* newNode;          //pointer to new node
    Node* parentNode;      // pointer to parent

    newNode = ROOT;     //point to root
    newNode -> insert(record, record);      //insert record

    if(newNode->isFull())  // check for node overfill
    {
        Node* leftNode = new Node();    // point to new left node
        middle = newNode->getSize()/2;       // calculate middle value of node

        for(int position = 0; position != middle; position++)
        {
            leftNode->insert(newNode->getFront(), newNode->getFront()); //copy values
            newNode->popFront();        // pop off of vector
        }
		    Node* newParentNode = new Node();  // new parent node
		    parentNode = newParentNode;            // point to old parent
        parentNode->insert(newNode->getFront(),newNode->getFront());  // copy to old parent
    }
}

bool BPTree::modify(int key, int record)
{
    bool found = false;
    int temp;

    while(!found)
    {
        temp = BPTree.search(key);
        if(temp == NULL)
            return false;
        else
            for(int i = 0; i < Node.Records.size(); i++)
            {
                if(Node.Records[i] == key)
                    Node.Records[i] = key;
            }
}

int BPTree::search(int key)
{
    int check;
    check = root->getSize();

    for(int i = 0; i < root->getSize(); i++)
    {
       if(key ==  root->getEntry(i))
        return i;
    }
    root = root->getNext();
    return search(key);

    return -1; //failed
}

bool BPTree::remove(int key)
{
    int temp;

    while(!found)
    {
        temp = BPTree.search(key);
        if(temp == NULL)
            return false;
        else
            for(int i = 0; i < Node.Records.size(); i++)
            {
                if(Node.Records[i] == key)
                    Node.Records.erase(Node.Records.begin()+i);
            }
}

bool BPTree::verify()
{
    int check;
    check = root->getSize();

    if(check == 0 || check > order)
        return false;
    else
        return true;
}

void BPTree::rebuild()
{

}
