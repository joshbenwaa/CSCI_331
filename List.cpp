// Anthony Bloch
// CSCI 301: Section 1
// Project 2: Ordered List Class
// Due datae: 1.31.2017
// File name: List_implementation.cpp
//
// CLASS IMPLEMENTED: List (See List_header.h for documentation.)
//
// INVARIANT for the List implementation:
//   1. The member variable used holds the number of items in the
//      List.
//   2. For an empty List, we do not care what is stored in any 
//      positions of the array data[]. The Items in a non-empty //      List are stored in positions data[0] through data[used-
//      1], and we do not care about the contents of the
//      remaining positions.

#include <cassert> 	//Provides assert()
#include <cstdlib> 	//Provides size_t
#include <iostream>
#include <iomanip>	// Provides setw()
#include <fstream>
#include "List.h"
using namespace std;

namespace csci301_list
{

	// The default constructor is an inline function.

	void List::insert(const Item& entry)
		// Uses cassert.
	{
		assert(size() < CAPACITY);

		size_t i = 0, j = 0;
		while (i<used)
		{
			if (data[i] == entry)
				break; // List remains unchanged
			else if (data[i]>entry)
			{
				while (used - j>i) // loop used to shift all
								   // items above the location
								   // of the inserted item up one
				{
					data[used - j] = data[used - j - 1];
					++j;
				}
				data[i] = entry; // item is inserted
				++used;
				break;
			}
			else
				++i;
		}
		if (i == used) // if item is larger than all current
					   // items, it is simply added to the end
					   // of the List
		{
			data[i] = entry;
			++used;
		}
	}

	// make_empty () is an inline function.

	void List::remove(const Item& target)
		// Uses cstdlib.
	{
		size_t index, mid, high = used, low = 0;
		if (used == 0) // no items to remove
			return;
		else if (used == 1) // if only 1 item in List, make
							// empty if that item is equal to
							// the target
			if (target == data[0])
			{
				used = 0;
				return;
			}
			else
				return;
		else // use binary search to find the item (if it's in
			 // the List)
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (target<data[mid])
					high = mid - 1;
				else if (target == data[mid])
				{
					index = mid;
					for (index; index<used; ++index)
						// shift items above removed item down
						data[index] = data[index + 1];
					--used;
					break;
				}
				else
					low = mid + 1;
			}
		return;
	}

	//size() is an inline function.

	size_t List::search(const Item& target) const
		// Uses cstdlib.
	{
		size_t answer = 0, mid, high = used, low = 0;
		if (used == 0)// nothing in the List
			answer = 0;
		else if (used == 1)//only one item in the List
			if (target == data[0])
				answer = 1;
			else
				answer = 0;
		else // binary search to find item if it's in the List
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (target<data[mid])
					high = mid - 1;
				else if (target == data[mid])
				{
					answer = 1;
					break;
				}
				else
					low = mid + 1;
			}
		return answer;
	}


	size_t List::element_value(const size_t& element) const
	{
		if (element <= 0)
			return 0;
		else
			return data[element - 1];
	}

	ostream& operator << (ostream& out_s, const List& l)
		// Uses iomanip.
	{
		out_s << "{ ";
		if (l.used > 1)
			for (int i = 0; i<l.used - 1; ++i)
				out_s << setw(1) << l.data[i] << ", ";
		if (l.used >0)
			out_s << setw(1) << l.data[l.used - 1] << ' ';
		out_s << "}";

		return out_s;
	}

	List operator + (const List& l1, const List& l2)
		// Uses cassert.
	{
		List answer;

		assert(l1.size() + l2.size() <= List::CAPACITY);

		size_t i = 0, j = 0;
		while (i<l1.size() && j<l2.size()) // checks for
										   // duplicates in the
										   // two addend Lists
		{
			if (l1.data[i] == l2.data[j])
			{
				answer.data[answer.used] = l1.data[i];
				++i;
				++j;
			}
			else if (l1.data[i]<l2.data[j])
			{
				answer.data[answer.used] = l1.data[i];
				++i;
			}
			else
			{
				answer.data[answer.used] = l2.data[j];
				++j;
			}
			++answer.used;
		}
		if (i<l1.size())
			while (i<l1.size())
			{
				answer.data[answer.used] = l1.data[i];
				++i;
				++answer.used;
			}
		else if (j<l2.size())
			while (j<l2.size())
			{
				answer.data[answer.used] = l2.data[j];
				++j;
				++answer.used;
			}
		else
			answer = answer;
		return answer;
	}
}
