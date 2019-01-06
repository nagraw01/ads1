
#include "HeapSort.h"


void HeapSort::sort(std::vector<int>& A) {
	
	int n = A.size() - 1;
	buildHeap(A, n);
	for (int i = n; i >= 1; i--) // Remove last element from heap
	{
		swap(A[0], A[i]);
		heapify(A, 1, i); // Heapify reduced heap
	}
}//end of sort enter
///////////


void HeapSort::heapify(std::vector<int>& A, int i, int n)
{
	int largest;
	int l = 2 * i;
	int r = (2 * i) + 1;

	if ((l <= n) && (A[l - 1] > A[i - 1]))
		largest = l;
	else
		largest = i;

	if ((r <= n) && (A[r - 1] > A[largest - 1]))
		largest = r;

	if (largest != i)
	{
		swap(A[i - 1], A[largest - 1]);
		heapify(A, largest, n);
	}
}//
////////////

void HeapSort::buildHeap(std::vector<int>& A, int n)
{
	for (int i = n / 2; i >= 1; i--)
	{
		heapify(A, i, n);
	}
}//
/////////

void HeapSort::swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}//end of swap
//////////
///////////