#ifndef INTROSORT_H
#define INTROSORT_H


#include "../ISort/ISort.h"

class IntroSort :public ISort {

public:
	void sort(std::vector<int>& vector);
	void introsort_r(std::vector<int>&, int first, int last, int depth);
	void _introsort(std::vector<int>&, int n);
	int _partition(std::vector<int>&, int first, int last);
	void _insertion(std::vector<int>&, int n);
	void _swap(int *a, int *b);
	void _doheap(std::vector<int>&, int begin, int end);
	void _heapsort(std::vector<int>&, int begin, int end);
	bool _isSorted(std::vector<int>&, int end);
};

#endif

