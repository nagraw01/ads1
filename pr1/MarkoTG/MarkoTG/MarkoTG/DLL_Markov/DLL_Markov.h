#ifndef DLL_MARKOV_H
#define DLL_MARKOV_H

#include "../IVector/IVector.cpp"
#include "../IMarkov/IMarkov.h"
#include <stdlib.h>
#include <time.h>//srand and rand
#include <string.h>



template<class T>
class DLL_Markov_Node
{
public:
	T getRandom();
	void addNew(T t);
	bool info_equal(T);

	T info;
	IVector<T> v;
	DLL_Markov_Node<T> *next, *prev;
};

template<class T>
class DLL_Markov:public IMarkov<T>
{
public:

	DLL_Markov() //: start(NULL), tails(NULL)    // constructor
	{
		start = NULL; tails = NULL;
	}

	void add(T, T);
	void generate(int);
	DLL_Markov_Node<T>* find_node(T);
	DLL_Markov_Node<T>* find_node(int);
	bool empty();
	int size();
	DLL_Markov_Node<T>* insert(T);

	~DLL_Markov() {} //destru
private:
	DLL_Markov_Node<T> *start, *tails;
};

#endif



