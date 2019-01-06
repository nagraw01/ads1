

#include "RadixSort.h"


void RadixSort::sort(std::vector<int>& vec) {
	int n = vec.size(), i, j, k, factor;
	const int radix = 10;
	const int digits = 10;
	
	std::queue<int> queues[radix];
	for (i = 0, factor = 1; i<digits; factor *= radix, i++) {

		for (j = 0; j<n; j++) {
			queues[(vec[j] / factor) % radix].push(vec[j]);
		}
		for (j = k = 0; j < radix; j++) {
			while (!queues[j].empty()) {
				
				//assign the first value of queue
				vec[k++] = queues[j].front();
				
				queues[j].pop();

			}
		}
	}
}
