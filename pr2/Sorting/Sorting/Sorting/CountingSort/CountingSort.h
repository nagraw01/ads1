#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H


#include "../ISort/ISort.h"

class CountingSort :public ISort {

public:
	
	void sort(std::vector<int>& vector);
};

#endif

