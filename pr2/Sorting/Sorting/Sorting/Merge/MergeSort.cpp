
#include "MergeSort.h"


void MergeSort::sort(std::vector<int>& v) {
	/*if (v.size() < 2) {
		throw std::out_of_range("out of range");
	}*/
	//sortl(v, 0, v.size() - 1);
	v = merge_sort(v);
}


std::vector<int> MergeSort::merge_sort(std::vector<int>& vec)
{  
    // Termination condition: List is completely sorted if it  
    // only contains a single element.  
    if(vec.size() == 1)  
    {  
        return vec;  
    }  
  
    // Determine the location of the middle element in the vector  
    std::vector<int>::iterator middle = vec.begin() + (vec.size() / 2);  
  
	std::vector<int> left(vec.begin(), middle);
	std::vector<int> right(middle, vec.end());
  
    // Perform a merge sort on the two smaller vectors  
    left = merge_sort(left);  
    right = merge_sort(right);  
  
    return merge(left, right);  
}


std::vector<int> MergeSort::merge(const std::vector<int>& left, const std::vector<int>& right)
{
	// Fill the resultant vector with sorted results from both vectors  
	std::vector<int> result;
	unsigned left_it = 0, right_it = 0;

	while (left_it < left.size() && right_it < right.size())
	{
		// If the left value is smaller than the right it goes next  
		// into the resultant vector  
		if (left[left_it] < right[right_it])
		{
			result.push_back(left[left_it]);
			left_it++;
		}
		else
		{
			result.push_back(right[right_it]);
			right_it++;
		}
	}

	// Push the remaining data from both vectors onto the resultant  
	while (left_it < left.size())
	{
		result.push_back(left[left_it]);
		left_it++;
	}

	while (right_it < right.size())
	{
		result.push_back(right[right_it]);
		right_it++;
	}

	return result;
}