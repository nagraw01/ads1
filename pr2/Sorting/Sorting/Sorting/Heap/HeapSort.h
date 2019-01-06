#ifndef HEAPSORT_H
#define HEAPSORT_H


#include "../ISort/ISort.h"

class HeapSort :public ISort {

public:

	void sort(std::vector<int>& vector);
	void heapify(std::vector<int>&, int, int);
	void buildHeap(std::vector<int>&, int);
	void swap(int&, int&);
};

#endif

