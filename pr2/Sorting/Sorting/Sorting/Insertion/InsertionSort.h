#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H


#include "../ISort/ISort.h"

class InsertionSort :public ISort {
public:
	void sort(std::vector<int>& vector);
};

#endif

