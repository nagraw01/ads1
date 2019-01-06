#ifndef ISORT_H
#define ISORT_H

#include <vector>

struct ISort {
	ISort() {}
	~ISort() {}
	void bar(std::vector<int>& vector)
	{
		sort(vector);
	}
	virtual void sort(std::vector<int>& vector) = 0;
};

#endif
