#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <queue>
#include <list>

#include "../ISort/ISort.h"
class RadixSort :public ISort {

public:
	void sort(std::vector<int>& vector);
};

#endif

