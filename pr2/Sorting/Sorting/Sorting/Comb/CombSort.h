#ifndef COMBSORT_H
#define COMBSORT_H


#include "../ISort/ISort.h"

class CombSort :public ISort {
public:
	void sort(std::vector<int>& vector);
};

#endif
