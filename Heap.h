// Replacement Selection Header

#ifndef HEAP_H
#define HEAP_H

#include <cstdlib>
#include <iostream>  // istream and ostream
#include <string.h> // string functions
#include <fstream> //read from file

namespace csci331_project1
{
		template<class H>
		class Heap
		{
			public:
				static const int MAX = 8; // maximum size of buffer vector

				// Constructor
				Heap() { size_left = 0; size_right = 0; } // Inline

				//modification member functions
				bool insert(H entry, bool left_or_right);
				H remove_root(bool left_or_right);
				int size(bool left_or_right);

			private:
				H buffer[MAX];
				int size_left;
				int size_right;
		};

}
#endif
