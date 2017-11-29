// Anthony Bloch
// CSCI 301 Section 1
// Project 5
// Due date: 3-2-2017
// This is the header file for a Ulist (unordered list) class represented by 
// a list of nodes linked by pointers. Each node contains a character (ch) and
// pointers to the next and previous nodes (next and prev).
// The class itself only contains the pointers pointing to the first and last nodes (first and last).
// file name: Ulist_header.h
//
// Constructor for Ulist class
// 	Ulist()
//		Postcondition: The Ulist has been initialized as 
//		an empty List with first and last both NULL
// Destructor for Ulist class
// 	~Ulist()
// 		Postcondition: all memory allocated by the Ulist
// 		has been given back
// Modification member functions for the Ulist class
//	append(Item& entry)
//		Postcondition: entry has been added on as a new node on the end of the Ulist
//	remove_last()
//		Postcondition: the last node has been removed and last now points to the second to last node
//		whose next pointer is NULL. If the Ulist is empty or only contains one item, the Ulist is now
//		empty, and first and last are both NULL.
//
// Constant member functions for the Ulist class
//	empty()
//		Postcondition: 1 is returned if the Ulist is empty. Otherwise 0 is returned.
//
// friend function for the Ulist class
// 		std::ostream& operator << (std::ostream& out_s, const Ulist& u);
// 			Postcondition: The contents of the Ulist u
// 			have been written to the output stream out_s

#ifndef ULIST_H
#define ULIST_H

#include <cstdlib>
#include <iostream>  // istream and ostream
#include <string.h> // string functions
#include <fstream> //read from file

namespace csci301_ulist
{
	class Ulist
	{
	public:
		typedef int Item;

		// constructor
		Ulist() { first = NULL; last = NULL; } // inline

											   // destructor
		~Ulist();

		// modification member functions
		void append(const Item& entry);
		void remove_last();

		// constant member functions
		int empty() const { if (first == NULL&&last == NULL)return 1; else return 0; }; //inline

																						// friend function
		friend std::ostream& operator << (std::ostream& out_s, const Ulist& u);

	private:
		// data members
		struct Node
		{
			Item ch; //an array of Words
			Node *next;
			Node *prev;
		};
		Node *first;
		Node *last;

		// private function
		Node* get_node(const Item& entry, Node* link_prev, Node* link_next);
	};
}
#endif
