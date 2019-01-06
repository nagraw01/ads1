#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H


#include "../ISort/ISort.h"

class SelectionSort :public ISort {

public:
	void sort(std::vector<int>& vector);
};

#endif

