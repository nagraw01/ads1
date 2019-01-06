#ifndef SHELLSORT_H
#define SHELLSORT_H

//#include <iostream>
//#include <conio.h>
//#include <vector>

#include "ISort.h"

class ShellSort :public ISort {
	//int arr[MAX], n;
public:
	//void showdata();
	void sort(std::vector<int>& vector);
};

#endif

