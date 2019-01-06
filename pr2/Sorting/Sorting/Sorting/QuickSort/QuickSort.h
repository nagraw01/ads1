#ifndef QUICKSORT_H
#define QUICKSORT_H


#include "../ISort/ISort.h"

class QuickSort :public ISort {
	
public:
	void sort(std::vector<int>&);

	void swap(int&, int&);

	void qksort(std::vector<int>&, int);
	void qksort(std::vector<int>&, int, int);
};

#endif
