#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "../ISORT/ISort.h"

class BubbleSort :public ISort {
public:
	void sort(std::vector<int>& vector);
};

#endif


