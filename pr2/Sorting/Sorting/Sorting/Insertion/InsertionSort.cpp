#include "InsertionSort.h"

void InsertionSort::sort(std::vector<int>& vec) {

	for (int i = 1, j; i<vec.size(); i++) {
		int temp = vec[i];
		for (j = i; j>0 && vec[j - 1]>temp; j--) {
			vec[j] = vec[j - 1];
		}
		vec[j] = temp;
	}
}
