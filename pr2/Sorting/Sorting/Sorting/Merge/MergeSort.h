#ifndef MERGESORT_H
#define MERGESORT_H


#include "../ISort/ISort.h"

class MergeSort :public ISort {
	
public:
	void sort(std::vector<int>& vector);

	std::vector<int> merge_sort(std::vector<int>& vec);
	std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right);

};

#endif

