// Replacement Selection Implementation

#include <cstdlib>
#include <iostream>
#include <cassert>
#include <fstream>
#include <string.h>
#include "ReplacementSelection.h"
using namespace std;

namespace csci331_project1
{
	template<class H>
	bool Heap<H>::insert(H entry, bool left_or_right)
	{
		bool success = true; //tracks if entry is successfully insterted
		string temp;
		int temp_size, current_size, offset, sign;
		bool flag = true; // tracks if entry is in correct position within the heap
		if (size_left + size_right >= MAX) // check if buffer is full
			success = false;
		else
		{
			if (left_or_right == true) // check if entry is being added to left or right heap
			{
				current_size = size_left; // pointer to entry in heap
				size_left++;
				offset = 0;
				sign = 1;
			}
			else
			{
				current_size = size_right;
				size_right++;
				offset = MAX - 1;
				sign = -1;
			}
			temp_size = current_size;
			buffer[offset + sign*current_size] = entry; // place entry at bottom of heap
			while (temp_size > 0 && flag) // while entry not in proper place...
			{
				if (buffer[offset + sign*temp_size] < buffer[offset + sign*(temp_size - 1) / 2]) // checks if entry is smaller than parent
				{
					temp = buffer[offset + sign*temp_size]; // swap entry and parent
					buffer[offset + sign*temp_size] = buffer[offset + sign*(temp_size - 1) / 2];
					temp_size = (temp_size - 1) / 2; // change pointer to entry to check against its new parent
					buffer[offset + sign*temp_size] = temp;
				}
				else
					flag = false; // entry is in correct place in heap
			}
		}
		/*cout << "updated heap from insert: ";
		for (int i = 0; i < 8; i++)
			cout << buffer[i] << " ";
		cout << endl;*/
		return success;
	}

	template<class H>
	H Heap<H>::remove_root(bool left_or_right)
	{
		string temp, lower;
		int sign, offset, current_size;
		int temp_size = 0; // tracks location of largest element as it is percolated down
		bool flag = true;
		if (((left_or_right==false)&&(size_right<1)) || ((left_or_right==true)&&(size_left<1))) // check if desired heap is empty
			temp = -1;
		else
		{
			if (left_or_right == true) // check if removing root from left or right heap
			{
				offset = 0;
				sign = 1;
				size_left--;
				current_size = size_left;

			}
			else
			{
				offset = MAX - 1;
				sign = -1;
				size_right--;
				current_size = size_right; // tracks number of items in current heap

			}
			temp = buffer[offset]; // pull up lowest item in heap to root and percolate down
			buffer[offset] = buffer[offset+sign*current_size];
			while (flag)
			{
				if (2 * temp_size + 2 <= current_size - 1) // checks if current node has two children
				{
					if (buffer[offset + sign*(2 * temp_size + 1)] < buffer[offset + sign*(2 * temp_size + 2)]) // checks which child is less
						if (buffer[offset + sign*temp_size] < buffer[offset + sign*(2 * temp_size + 1)]) // checks if node is less than lesser child
							flag = false;
						else
						{
							lower = buffer[offset + sign*(2 * temp_size + 1)]; // swap parent with lesser child and check it against its new children
							buffer[offset + sign*(2 * temp_size + 1)] = buffer[offset + sign*temp_size];
							buffer[offset + sign*temp_size] = lower;
							temp_size = 2 * temp_size + 1;
						}
					else
						if (buffer[offset + sign*temp_size] < buffer[offset + sign*(2 * temp_size + 2)])// checks if node is less than lesser child
							flag = false;
						else
						{
							lower = buffer[offset + sign*(2 * temp_size + 2)]; // swap parent with lesser child and check it against its new children
							buffer[offset + sign * (2 * temp_size + 2)] = buffer[offset + sign*temp_size];
							buffer[offset + sign*temp_size] = lower;
							temp_size = 2 * temp_size + 2;
						}
				}
				else if (2 * temp_size + 1 <= current_size - 1) // checks if current node has one child
				{
					if (buffer[offset + sign*temp_size] < buffer[offset + sign * (2 * temp_size + 1)])
						flag = false;
					else
					{
						lower = buffer[offset + sign * (2 * temp_size + 1)];// swap parent with child
						buffer[offset + sign * (2 * temp_size + 1)] = buffer[offset + sign*temp_size];
						buffer[offset + sign*temp_size] = lower;
						//temp_size = 2 * temp_size + 1;
						flag = false;
					}
				}
				else
					flag = false;
			}
			/*cout << "Updated heap from remove: ";
			for (int i = 0; i < 8; i++)
				cout << buffer[i] << " ";
			cout << endl;*/
		}
		return temp;
	}

	template<class H>
	int Heap<H>::size(bool left_or_right)
	{
		if (left_or_right)
			return size_left;
		else
			return size_right;
	}
}
