#ifndef TEST_H
#define TEST_H

#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

//#include "../IVector/IVector.h" //.cpp already included with dll_markov and others

#include "../DLL_Markov/DLL_Markov.cpp"
#include "../ML_Markov/ML_Markov.cpp"
#include "../SkipList_Markov/SkipList_Markov.cpp"
#include "../IMarkov/IMarkov.h"

template<class T>
class Test {
public:
	IMarkov<T>* mark;
	
	//void readFile();
	void menuDisplay();

};

#endif

/*
1. clean and concise the code for each class, so as to do the big-O on add and generate methods
2. proper destru and constru for all classes


*/