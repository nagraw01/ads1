
#include "SelectionSort.h"


void SelectionSort::sort(std::vector<int>& vec) {

	int index_min, temp;
	int n = vec.size();

	for (int i = 0; i < n - 1; i++)
	{
		index_min = i; //set min to the current index

		for (int j = i + 1; j < n; j++)
		{

			if (vec[j] < vec[index_min])
				index_min = j;
			//min will keep track of the index that min is in
		}

		//if min no longer equals i than a smaller value must have been found, so do a swap
		if (index_min != i)
		{
			temp = vec[i];
			vec[i] = vec[index_min];
			vec[index_min] = temp;
		}
	}
}
