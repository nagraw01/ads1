#ifndef SHELLSORT_H
#define SHELLSORT_H


#include "../ISort/ISort.h"

class ShellSort :public ISort {

public:
	void sort(std::vector<int>& vector);
};

#endif

