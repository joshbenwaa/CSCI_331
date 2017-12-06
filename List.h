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
			Key* ancestor;
			Key* child;
			Key* prev_sibling;
			Key* next_sibling;
			Key* prev_sequence;
			Key* next_sequence;
		};
		int int_or_string; // >0 for sorting by integer, <1 for sorting by string
		Key* first;
		Key* last;
		Key* first_sequence;
		Key* last_sequence;

		List(int i_or_s) { int_or_string = i_or_s; first = NULL; last = NULL; first_sequence = NULL, last_sequence = NULL; }

		Key* get_key(int entry_i, string entry_s, Key* ancestor_link, Key* child_link, Key* prev_link, Key* next_link, Key* prev_sequence_link, Key* next_sequence_link)
		{
			Key *temp;
			temp = new Key;
			temp->value_i = entry_i;
			temp->value_s = entry_s;
			temp->ancestor = ancestor_link;
			temp->child = child_link;
			temp->prev_sibling = prev_link;
			temp->next_sibling = next_link;
			temp->prev_sequence = prev_sequence_link;
			temp->next_sequence = next_sequence_link;
			return temp;
		}

		void insert(int entry_i, string entry_s, Key* ancestor_link, Key* child_link)
		{
			Key* prev;
			if (first == NULL&&last == NULL)
			{ // this is the first key being inserted in the list
				first = get_key(entry_i, entry_s, ancestor_link, child_link, NULL, NULL, NULL, NULL);
				last = first;
				first_sequence = first;
				last_sequence = first;
			}
			else if (int_or_string>0 && (entry_i < first->value_i || entry_i == first->value_i&&entry_s <= first->value_s) || int_or_string<1 && (entry_s < first->value_s || entry_s == first->value_s&&entry_i <= first->value_i))
			{ // the key is the first in the list
				first->prev_sibling = get_key(entry_i, entry_s, ancestor_link, child_link, NULL, first, last_sequence, NULL);
				first = first->prev_sibling;
				last_sequence->next_sequence = first;
				last_sequence = first;
			}
			else if (int_or_string>0 && (entry_i > last->value_i || entry_i == last->value_i&&entry_s >= last->value_s) || int_or_string<1 && (entry_s > last->value_s || entry_s == last->value_s&&entry_i >= last->value_i))
			{ // the key is the last in the list
				last->next_sibling = get_key(entry_i, entry_s, ancestor_link, child_link, last, NULL, last_sequence, NULL);
				last = last->next_sibling;
				last_sequence->next_sequence = last;
				last_sequence = last;
			}
			else
			{
				prev = first;
				while (int_or_string>0 && (entry_i > prev->value_i || entry_i == prev->value_i&&entry_s >= prev->value_s) || int_or_string<1 && (entry_s > prev->value_s || entry_s == prev->value_s&&entry_i >= prev->value_i))
					prev = prev->next_sibling;
				prev->prev_sibling->next_sibling = get_key(entry_i, entry_s, ancestor_link, child_link, prev->prev_sibling, prev->prev_sibling->next_sibling, last_sequence, NULL);
				prev->prev_sibling = prev->prev_sibling->next_sibling;
				last_sequence->next_sequence = prev->prev_sibling;
				last_sequence = prev->prev_sibling;
			}
		}

		Key* search(int entry_i, string entry_s)
		{
			Key* prev;
			prev = first;
			while (prev != NULL && (int_or_string>0 && (entry_i > prev->value_i || entry_i == prev->value_i&&entry_s > prev->value_s) || int_or_string<1 && (entry_s > prev->value_s || entry_s == prev->value_s&&entry_i > prev->value_i)))
				prev = prev->next_sibling;
			if (prev != NULL && (int_or_string > 0 && (entry_i != prev->value_i || entry_s != prev->value_s) || int_or_string < 1 && (entry_s != prev->value_s || entry_i != prev->value_i)))
				prev = NULL;
			return prev;
		}

		void external_search(int entry_i, string entry_s)
		{
			Key* temp = search(entry_i, entry_s);
			if (temp == NULL)
				cout << "That key is NOT in the list.\n";
			else
				cout << "That key is in the list.\n";
		}

		void remove(int entry_i, string entry_s)
		{
			Key* temp = search(entry_i, entry_s);
			if (temp == NULL)
				cout << "That key is NOT in the list.\n";
			else
			{
				if (temp->prev_sibling != NULL)
					temp->prev_sibling->next_sibling = temp->next_sibling;
				else // first element in list
					first = temp->next_sibling;
				if (temp->next_sibling != NULL)
					temp->next_sibling->prev_sibling = temp->prev_sibling;
				else // last element in list
					last = temp->prev_sibling;
				if (temp->prev_sequence != NULL)
					temp->prev_sequence->next_sequence = temp->next_sequence;
				else // first element in sequence list
					first_sequence = temp->next_sequence;
				if (temp->next_sequence != NULL)
					temp->next_sequence->prev_sequence = temp->prev_sequence;
				else // last element in sequence list
					last_sequence = temp->prev_sequence;
				delete temp;
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
			cout << endl;
		}

		void print_sequence(ostream& out_s)
		{
			Key *cursor;
			cursor = first_sequence;
			while (cursor != NULL)
			{
				out_s << cursor->value_i << ' ' << cursor->value_s << ' ';
				cursor = cursor->next_sequence;
			}
			cout << endl;
			cursor = last_sequence;
			while (cursor != NULL)
			{
				out_s << cursor->value_i << ' ' << cursor->value_s << ' ';
				cursor = cursor->prev_sequence;
			}
			cout << endl;

		}

		int low_key_int()
		{
			return first->value_i;
		}

		string low_key_string()
		{
			return first->value_s;
		}

		int high_key_int()
		{
			return last->value_i;
		}

		string high_key_string()
		{
			return last->value_s;
		}
	};
}
#endif
