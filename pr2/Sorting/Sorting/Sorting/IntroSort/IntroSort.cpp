
#include "IntroSort.h"


void IntroSort::sort(std::vector<int>& vec) {
	
	int n = vec.size();
	_introsort(vec, n);
}//end of sort enter
/////////


void IntroSort::introsort_r(std::vector<int>& a, int first, int last, int depth) {
	
	while (last - first > 0) {
		if (depth == 0)
			_heapsort(a, first, last - first + 1);
		else {
			int pivot;
			if (_isSorted(a, last))
				break;
			pivot = _partition(a, first, last);
			introsort_r(a, pivot + 1, last, depth - 1);
			last = pivot - 1;
		}
	}
}

void IntroSort::_introsort(std::vector<int>& a, int n) {
	introsort_r(a, 0, n - 1, (int(2 * log(double(n)))));
	_insertion(a, n);
}

int IntroSort::_partition(std::vector<int>& a, int first, int last) {
	
	int pivot, mid = (first + last) / 2;

	pivot = a[first] > a[mid] ? first : mid;

	if (a[pivot] > a[last])
		pivot = last;

	_swap(&a[pivot], &a[first]);
	pivot = first;

	while (first < last) {
		if (a[first] <= a[last])
			_swap(&a[pivot++], &a[first]);
		++first;
	}

	_swap(&a[pivot], &a[last]);
	return pivot;
}

void IntroSort::_insertion(std::vector<int>& a, int n) {
	
	int i;
	for (i = 1; i < n; i++) {
		int j, save = a[i];
		for (j = i; j >= 1 && a[j - 1] > save; j--)
			a[j] = a[j - 1];
		a[j] = save;
	}
}

void IntroSort::_swap(int *a, int *b) {
	int save = *a;
	*a = *b;
	*b = save;
}
void IntroSort::_doheap(std::vector<int>& a, int begin, int end) {
	int save = a[begin];
	while (begin <= end / 2) {
		int k = 2 * begin;
		while (k < end && a[k] <a[k + 1])
			++k;
		if (save >= a[k])
			break;
		a[begin] = a[k];
		begin = k;
	}
	a[begin] = save;
}

void IntroSort::_heapsort(std::vector<int>& a, int begin, int end) {
	
	int i;
	for (int i = (end - 1) / 2; i >= begin; i--) {
		_doheap(a, i, end - 1);
	}
	for (i = end - 1; i>begin; i--) {
		_swap(&a[i], &a[begin]);
		_doheap(a, begin, i - 1);
	}
}
bool IntroSort::_isSorted(std::vector<int>& a, int end) {
	for (int i = 0; i<end; i++) {
		if (a[i] > a[i + 1]) {
			return false;
		}
		else {
			return true;
		}
	}
	return true;
}
