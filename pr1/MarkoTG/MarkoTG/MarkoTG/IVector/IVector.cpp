#pragma once

#include "IVector.h"
#include<string>
#include <cstdio>

//using namespace std;

template<class T>
void IVector<T>::increase_capacity(int sz) {
	if (sz <= capacity) return;

	T* new_arr = new T[sz];   // allocate a new array on the free store

	for (int i = 0; i < capacity; ++i) { // copy old vector into new one
		new_arr[i] = arr[i];
	}
	capacity = sz;                      // set the new capacity

	delete[] arr;                       // delete the old vector
	arr = new_arr;
}

template<class T>
void IVector<T>::push_back(T x) {
	if (n >= capacity) increase_capacity(2 * capacity);
	arr[n] = x;
	++n;
}

template<class T>
void IVector<T>::set(int i, T val) {
	if (i < 0 || i >= n) puts("range error");
	arr[i] = val;
}

template<class T>
T IVector<T>::get(int i) const {
	if (i < 0 || i >= n) puts("range error");
	return arr[i];
}

template<class T>
void IVector<T>::print_vector() {
	for (int i = 0; i<n; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class T>
T& IVector<T>::operator[](int i) {
	if (i < 0 || i >= n) puts("range error");
	return arr[i];
}

//template<class T>
//const T& IVector<T>::operator[](int i) {
//	if (i < 0 || i >= n) puts("range error");
//	return arr[i];
//}
