#include "ML_Markov.h"


template<class T>
ML_Markov_Node<T>* ML_Markov_Node<T>::getRandom()
{
	int iSecret;
	srand(time(NULL));            // check if the corresponding vector is empty
								  //cout << v.size() << endl;
	iSecret = rand() % v.size();
	return v[iSecret];
}//
 ///////
 ////////

template<class T>
void ML_Markov_Node<T>::addNew(ML_Markov_Node<T>* t)
{
	v.push_back(t);
}//
 ///////
 ////////


template<class T>
void ML_Markov<T>::add(T t1, T t2)
{
	
	ML_Markov_Node<T>* node1 = find_node(t1);
	
	if (node1 == NULL) {
		
		node1 = insert(t1);
		
	}

	ML_Markov_Node<T>* node2 = find_node(t2);
	
	if (node2 == NULL) {
		
		node2 = insert(t2);

	}
	
	node1->addNew(node2);

}//
 ///////
 ////////

template<class T>
void ML_Markov<T>::generate(int len)
{
	int iSecret = 0;
	IVector<T> retV;

	srand(time(NULL));            // check if the corresponding vector is empty

	iSecret = rand() % (size());

	ML_Markov_Node<T> *tmp = find_node(iSecret);
	retV.push_back(tmp->info);

	for (int i = 0; i < len - 1; i++) {

		tmp = tmp->getRandom();

		retV.push_back(tmp->info);
		//tmp = find_node(loopy);

		if (tmp->next == NULL) tmp = start;
	}
	retV.print_vector();

}//
 ///////
 ////////

template<class T>
ML_Markov_Node<T>* ML_Markov<T>::find_node(T t)
{
	ML_Markov_Node<T> *s;
	if (empty())return NULL;
	else {
		s = start;
		while (s != NULL) {
		
			if (s->info_equal(t)) {
				
				return s;
			}
		
			s = s->next;
		}
		return s;
	}


}//
 ///////
 ////////

template<class T>
ML_Markov_Node<T>* ML_Markov<T>::find_node(int in)
{
	
	ML_Markov_Node<T> *s;

	s = start;
	for (int i = 0; i < in; ++i) {
		s = s->next;
	}
	return s;
}//
 ///////
 ////////

template<class T>
bool ML_Markov<T>::empty()
{
	if (start == NULL)return 1;
	else return 0;

}//
 ///////
 ////////

template<class T>
ML_Markov_Node<T>* ML_Markov<T>::insert(T value)
{
	ML_Markov_Node<T> *s, *temp;
	temp = new(ML_Markov_Node<T>);
	temp->info = value;
	temp->next = NULL;
	if (empty())
	{
		temp->prev = NULL;
		start = temp;
		tails = temp;
		return start;
	}
	else
	{
		s = tails;
		s->next = temp;
		temp->prev = s;
		tails = temp;
		return tails;
	}

}//
 ///////
 ////////

template<class T>
int ML_Markov<T>::size()
{

	 ML_Markov_Node<T> *s;
	int size = 0;
	s = start;
	while (s->next != NULL) {
	
		s = s->next;
		++size;
	}

	return ++size;

}//
 ///////
 ////////

template<class T>
bool ML_Markov_Node<T>::info_equal(T t)
{
	//const T& a = info;
	//const T& b = t;
	//puts("eq");
	//if (a == b)return 1;
	//else return 0;
	return !info.compare(t);

}//
 ///////
 ////////