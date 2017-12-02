#ifndef LIST_H
#define LIST_H
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

namespace csci331
{
	class List
	{
	public:
		struct Key
		{
			int value_i;
			string value_s;
			Key* prev_sibling;
			Key* next_sibling;
		};

		Key* first;
		Key* last;

		List() { first = NULL; last = NULL; }

		Key* get_key(int entry_i, string entry_s, Key* prev_link, Key* next_link)
		{
			Key *temp;
			temp = new Key;
			temp->value_i = entry_i;
			temp->value_s = entry_s;
			temp->prev_sibling = prev_link;
			temp->next_sibling = next_link;
			return temp;
		}

		void insert(int entry_i, string entry_s)
		{
			Key* prev;
			if (first == NULL&&last == NULL)
			{
				first = get_key(entry_i, entry_s, NULL, NULL);
				last = first;
			}
			else if (entry_i < first->value_i)
			{
				first->prev_sibling = get_key(entry_i, entry_s, NULL, first);
				first = first->prev_sibling;
			}
			else if (entry_i > last->value_i)
			{
				last->next_sibling = get_key(entry_i, entry_s, last, NULL);
				last = last->next_sibling;
			}
			else
			{
				prev = first;
				while (entry_i > prev->value_i)
					prev = prev->next_sibling;
				prev->prev_sibling->next_sibling = get_key(entry_i, entry_s, prev->prev_sibling, prev->prev_sibling->next_sibling);
				prev->prev_sibling = prev->prev_sibling->next_sibling;
			}
		}

		int length() const
		{
			Key *cursor;
			int length = 0;
			for (cursor = first; cursor != NULL; cursor = cursor->next_sibling)
				++length;
			return length;
		}

		void print(ostream& out_s)
		{
			Key *cursor;
			cursor = first;
			while (cursor != NULL)
			{
				out_s << cursor->value_i << ' ' << cursor->value_s << ' ';
				cursor = cursor->next_sibling;
			}
			cout << endl;
			cursor = last;
			while (cursor != NULL)
			{
				out_s << cursor->value_i << ' ' << cursor->value_s << ' ';
				cursor = cursor->prev_sibling;
			}
		}


	};
}
#endif