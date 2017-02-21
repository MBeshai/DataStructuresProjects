#ifndef INTERVALHEAP_H
#define INTERVALHEAP_H


#include "Food.h"
#include "Node.h"
#include <iostream>
using namespace std;

class IntervalHeap {
	public:
		IntervalHeap();
	
		void insert(Food* x);
		Food* deleteMin();
		Food* deleteMax();
		~IntervalHeap();
		Node* getRoot();
	private:
		Node* m_pRoot;

};

#endif