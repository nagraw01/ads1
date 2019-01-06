#ifndef SKIPLIST_MARKOV_H
#define SKIPLIST_MARKOV_H

#include "../IVector/IVector.cpp"
#include "../IMarkov/IMarkov.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

const int maxLevel = 5;

template<class T>
class SkipList_Markov_Node
{
public:
	T getRandom();
	void addNew(T t);

	T info;
	IVector<T> v;
	
	SkipList_Markov_Node<T> **next;
};

template<class T>
class SkipList_Markov :public IMarkov<T>
{
public:

	SkipList_Markov();

	void add(T, T);
	void generate(int);
	
	bool isempty();
	
	void insert(T, T);
	SkipList_Markov_Node<T>* find_node(T);

	void probabilise1();
	int probabilise2();

	//void printSkipList();

	~SkipList_Markov() {} //destru
private:
	SkipList_Markov_Node<T> *root[maxLevel];
	//SkipList_Markov_Node<T> *prev;
	//int prevLevel = 0;
	//IVector<T> preinfo;

	int prob[maxLevel];
};

#endif




