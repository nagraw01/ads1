
#include "QuickSort.h"


void QuickSort::sort(std::vector<int>& A) {
	qksort(A, A.size());
}//end of enter sort
///////////


void QuickSort::qksort(std::vector<int>& A, int n)
{
	int i, max;
	
	//if (n < 2)return;
	for (i = 1, max = 0; i < n;i++) {
		if (A[max] < A[i] )max = i;
	}
	swap(A[n - 1], A[max]);
	qksort(A, 0, n - 2);

}//end of qsort 2 args
/////////////

void QuickSort::qksort(std::vector<int>& A, int first, int last)
{
	int l = first + 1, u = last;

	swap(A[first], A[(first + last) / 2]);

	int p = A[first];

	//partitioning
	while (l<=u) {
		while (p >= A[l]) l++;
		while (p < A[u]) u--;
		if (l < u) swap(A[l++],A[u--]);
		else l++;
	}
	swap(A[u], A[first]);

	if (first < u - 1) qksort(A, first, u - 1);
	
	if (u+1 < last) qksort(A, u + 1, last);

}//end of qsort 3 args
/////////////

void QuickSort::swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}