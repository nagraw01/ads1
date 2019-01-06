
#include "BubbleSort.h"

void BubbleSort::sort(std::vector<int>& vec) {

	int n = vec.size(), temp;
	for (int i = 0; i<n - 1; i++) {
	
		for (int j = n - 1; j>i; j--) {
			if (vec[j] < vec[j - 1]) {
				temp = vec[j];
				vec[j] = vec[j - 1];
				vec[j - 1] = temp;
			}
		}
	}
}
