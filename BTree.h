/*BPlusTree header file with method declarations */
#include "Node.h"
#ifndef BTREE_H
#define BTREE_H
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

namespace csci331_project2
{
		template<class B>
		class BPTree
        {
        public:
            int RRN; //relative record number, used/as for keys
            int key_type;

        BTree();//constructor

        private:
            int order;
            Node* ROOT;
		};

   /* BTree(int o);

    ~BPTree(); */

    void print();

    void insert(int record);

    bool modify(int key, int record);

    int search(int key);

    bool remove(int key);

    bool verify();

    void rebuild();
};

#endif
