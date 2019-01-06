
#include "CombSort.h"



void CombSort::sort(std::vector<int>& vec) {
	
	// Initialize gap
	int n = vec.size();
	int gap = n, j, k, temp;

	// Initialize swapped as true to make sure that
	// loop runs
	bool swapped = true;

	// Keep running while gap is more than 1 and last
	// iteration caused a swap
	while (gap = int(gap / 1.3))
	{
		for (j = n - 1; j >= gap; j--) {
			k = j - gap;
			if (vec[j] < vec[k]) {
				temp = vec[k];
				vec[k] = vec[j];
				vec[j] = temp;
			}
		}
	}

	// Initialize swapped as false so that we can
	// check if swap happened or not
	//swapped = false;

	// Compare all elements with current gap
	for (int i = 0; i<n - 1 && swapped; i++)
	{
		for (j = n - 1, swapped = false; j > i; j--) {
			if (vec[j - 1] > vec[j])
			{
				temp = vec[j];
				vec[j] = vec[j - 1];
				vec[j - 1] = temp;
				swapped = true;
			}
		}
	}
}
