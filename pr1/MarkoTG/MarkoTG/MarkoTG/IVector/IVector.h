#ifndef IVECTOR_H
#define IVECTOR_H


using namespace std;

template<class T>
class IVector {
	T* arr;  // pointer to the first element of this vector
	int capacity; // number of elements arr can hold (i.e. size of underlying array)
	int n;        // size of this vec

				  // Increases the capacity of the underlying array to be sz. If sz
				  // is smaller than the current capacity then nothing is done.

public:

	// create an empty vector
	IVector() : capacity(10), n(0) { arr = new T[capacity]; }

	//returns the no. of elements currently in the vec
	int size() const { return n; }

	//increase capacity of array
	void increase_capacity(int);

	//adds the new elemnts to the end f the vec
	void push_back(T x);

	void set(int, T);

	void print_vector();

	T get(int) const;

	T& operator[](int);
	//const T& operator[](int);

	//destruc
	~IVector() { delete[] arr; }

}; // class IVector

#endif