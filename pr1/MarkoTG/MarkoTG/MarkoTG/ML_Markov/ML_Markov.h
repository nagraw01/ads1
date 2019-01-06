#ifndef ML_MARKOV_H
#define ML_MARKOV_H

#include "../IVector/IVector.cpp"
#include "../IMarkov/IMarkov.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>



template<class T>
class ML_Markov_Node
{
public:
	ML_Markov_Node<T>* getRandom();
	void addNew(ML_Markov_Node<T>*);
	bool info_equal(T);

	T info;
	IVector<ML_Markov_Node<T>*> v;
	ML_Markov_Node<T> *next, *prev;
};

template<class T>
class ML_Markov :public IMarkov<T>
{
public:

	ML_Markov() //: start(NULL), tails(NULL)    // constructor
	{
		start = NULL; tails = NULL;
	}

	void add(T, T);
	void generate(int);
	ML_Markov_Node<T>* find_node(T);
	ML_Markov_Node<T>* find_node(int);
	bool empty();
	int size();
	ML_Markov_Node<T>* insert(T);

	~ML_Markov() {} //destru
private:
	ML_Markov_Node<T> *start, *tails;
};

#endif




