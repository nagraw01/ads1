#ifndef HELLO_H
#define HELLO_H

#include<vector>
#include<iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <istream>

#include "Insertion/InsertionSort.h"
#include "Selection/SelectionSort.h"
#include "Bubble/BubbleSort.h"
#include "Comb/CombSort.h"
#include "Shell/ShellSort.h"
#include "Heap/HeapSort.h"
#include "Merge/MergeSort.h"
#include "QuickSort/QuickSort.h"
#include "RadixSort/RadixSort.h"
#include "IntroSort/IntroSort.h"
#include "CountingSort/CountingSort.h"

#include "Winstopwatch/WindowsStopWatch.h"

class Hello {
public:
	//vector object with elements to be sorted
	std::vector<int> vec;
	
	//file object which opens in displaymenu1
	std::ifstream file;

	//WindowsStopwatch wat1;
	ISort* ins;

	//menu to choose the file
	void dispmenu1();

	//menu to choose the sorting type
	void dispmenu2();

	//create the vector to be processed for sorting
	void createVec(int);

	void printVector();
};

#endif


