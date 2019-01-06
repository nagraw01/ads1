
#include "CountingSort.h"


void CountingSort::sort(std::vector<int>& vec) {
	int largest = vec[0], n = vec.size(), i;
	int *temp = new int[n];
	
	//loop to create the counter array
	for (i = 1; i<n; i++) {
		if (largest < vec[i]) {
			largest = vec[i];
		}

	}
	
	int* count = new int[largest+1];
	
	for (i = 0; i <= largest;i++) {
		count[i] = 0;
	}

	for (i = 0; i <n; i++) {
		count[vec[i]]++;
	}

	for (i = 1; i <= largest; i++) {
		count[i] = count[i-1] +count[i];
	}

	//order the numbers
	for (i = n-1; i >= 0; i--) {
		temp[count[vec[i]] - 1] = vec[i];
		count[vec[i]]--;
	}

	//transfer
	for (i = 0; i < n; i++) {
		vec[i] = temp[i];
	}
}
