// Anthony Bloch
// CSCI 301: Section 1
// Project 2: Ordered List Class
// Due datae: 1.31.2017
// This is the header file for the ordered list class
// File name: List_header.h

// CLASS PROVIDED: List; a container class for ordered multisets
// of items.
//
// TYPEDEF and MEMBER CONSTANTS for the List class:
//   static const size_t CAPACITY = 30;
//     List::CAPACITY is the maximum number of items that a List
//     can hold.
//
//   typedef int Item;
//     List::Item is the data type of the items in a List. It may
//     be any of the C++ built-in types (int, char, etc.) or a
//     class with a default constructor, an assignment operator,
//     and operators to test for equality (==) and inequality (!
//     =).
//
// CONSTRUCTOR for the List class:
//   List( )
//     Postcondition: The List has been initialized as an empty
//     List.
//
// MODIFICATION MEMBER FUNCTIONS for the List class:
//   void make_empty ( )
//     Postcondition: The List has been re-initialized to be
//     empty.
//
//   void insert ( const Item& entry )
//     Precondition: size() < CAPACITY
//     Postcondition: A new copy of entry has been added to the
//     List.
//
//   void remove ( const Item& target )
//     Postcondition: If the List contained target, then one copy
//     of target has been removed from the List; otherwise, the
//     List is unchanged.
//
// CONSTANT MEMBER FUNCTIONS for the List class:
//   size_t size( ) const
//     Postcondition: The return value is the number of items in
//     the List.
//
//   size_t occurrences ( const Item& target ) const
//     Postcondition: The return value is the number of times
//     target is in the List.
//
// FRIEND FUNCTION for the Bag class:
//   friend ostream& operator << ( ostream& out_s, const Bag& b )
//     Postcondition: The contents of the Bag b have been written
//     to the output stream out_s.
//
//   friend List operator + ( const List& l1, const List& l2);
//     Precondition: l1.size() + l2.size() <= CAPACITY.
//     Postcondition: The List returned is the union of l1 and
//     l2.
//
// VALUE SEMANTICS for the List class:
//   Assignment and the copy constructor may be used with List
//   objects.

#ifndef LIST_H
#define LIST_H
#include <cstdlib>  // provides size_t
#include <iostream> // provides istream and ostream

namespace csci301_list
{
	class List
	{
	public:

		//TYPEDEF and MEMBER CONSTANT
		static const size_t CAPACITY = 30;	// maximum size of any List
		typedef int Item; 				//What can go in a List
										//CONSTRUCTOR
		List() { used = 0; }				// Inline

											//MODIFICATION MEMBER FUNCTIONS
		void make_empty() { used = 0; } 	// Inline
											////NO SEMICOLON ON THE LINE ABOVE???
		void insert(const Item& entry);
		void remove(const Item& target);
		void operator += (const List& addend);

		// CONSTANT MEMBER FUNCTIONS
		size_t size() const { return used; } //Inline
		size_t search(const Item& target) const;
		size_t element_value(const size_t& element) const;

		//FRIEND FUNCTIONS
		friend std::ostream& operator << (std::ostream& out_s, const List& l);
		friend List operator + (const List& l1, const List& l2);

	private:

		Item data[CAPACITY]; 		//An array of Items
		size_t used; 			//How many hold List elements
	};
}

#endif
#pragma once
