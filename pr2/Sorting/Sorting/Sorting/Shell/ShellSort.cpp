
#include "ShellSort.h"


void ShellSort::sort(std::vector<int>& vec) {
	int n = vec.size(), i, j, k, ht, h;
	int arr[20]; //incremental array for the value of h

				 //setting values of h in the array
	for (h = 1, i = 0; h < n; i++) {
		arr[i] = h;
		h = 3 * h + 1;
	}

	for (i--; i >= 0; i--) {
		h = arr[i];

		//loop on subarrays of one value of h
		for (ht = h; ht < 2*h; ht++) {

			//insertion sort on each sub-array 
			for (j = ht; j < n; j += h) {
				int temp = vec[j];
				for (k = j; k - h >= 0 && temp < vec[k - h]; k -= h) {
					vec[k] = vec[k - h];
				}
				vec[k] = temp;
			}
		}
	}
}
