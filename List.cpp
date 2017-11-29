// Anthony Bloch
// CSCI 301 Section 1
// Project 5
// Due date: 3-2-2017
// This is the implementation file for a Ulist class 
// represented by an unordered list linked by pointers. Each node contains a 
// character and pointers to the next and previous nodes. 
// file name: Ulist_implementation.cpp
//
// INVARIANT for the Ulist implementation:
//   1. The characters in the Ulist are stored in a linked list in
//      in the order that they are added to the Ulist.
//   2. The member variable first points to the first node in
//      the linked list. When the list is empty, first is NULL.
//	The member variable last points to the last node in
//	the linked list. When the list is empty, last is NULL.

#include <cstdlib>
#include <iostream>
#include <cassert>
#include <fstream>
#include <string.h>
#include "List.h"
using namespace std;

namespace csci301_ulist
{
	// default constructor inline

	// Destructor
	Ulist::~Ulist()
	{
		Node* temp;
		while (first != NULL) // delete all memory used by Ulist
		{
			temp = first;
			first = first->next;
			delete temp;
		}
	}

	void Ulist::append(const Item& entry)
	{
		if (empty() == 1) // Ulist is empty
		{
			first = get_node(entry, NULL, NULL);
			last = first;
		}
		else	      // Ulist already contains one or more nodes
		{
			last->next = get_node(entry, last, NULL);
			last = last->next;
		}

	}

	void Ulist::remove_last()
	{
		Node *temp = last;
		if (empty() == 1) // do nothing if Ulist is empty
			;
		else if (first->next == NULL&&last->prev == NULL) // if only one node, remove it
		{
			last = NULL;
			first = NULL;
			delete temp;
		}
		else		// remove the last node
		{
			last = last->prev;
			last->next = NULL;
			delete temp;
		}
	}

	ostream& operator << (ostream& out_s, const Ulist& u)
	{
		Ulist::Node *cursor = u.first;
		while (cursor != NULL)
		{
			out_s << cursor->ch;
			cursor = cursor->next;
		}
		out_s << endl;
		return out_s;
	}

	Ulist::Node* Ulist::get_node(const Item& entry, Node* link_prev, Node* link_next)
	{
		Node *temp;
		temp = new Node;
		temp->ch = entry;
		temp->next = link_next;
		temp->prev = link_prev;
		return temp;
	}
}

