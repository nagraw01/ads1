#include "SkipList_Markov.h"


template<class T>
T SkipList_Markov_Node<T>::getRandom()
{
	
	int iSecret;
	srand(time(NULL));            // check if the corresponding vector is empty
	
	iSecret = rand() % v.size();
	
	return v[iSecret];
}//
 ///////
 ////////

template<class T>
void SkipList_Markov_Node<T>::addNew(T t)
{
	v.push_back(t);
}//
 ///////
 ////////


template<class T>
void SkipList_Markov<T>::add(T t1, T t2)
{
	probabilise1();
		
	insert(t1, t2);
	
}//
 ///////
 ////////

template<class T>
void SkipList_Markov<T>::generate(int len)
{

	int iSecret = 0;
	IVector<T> retV;

	SkipList_Markov_Node<T> *tmp = root[0];

	//pushing the first random element
	retV.push_back(tmp->info);

	//pushing the elements in the vector of the nodes
	for (int i = 0; i < len - 1; i++) {

		T loopy = tmp->getRandom();


		retV.push_back(loopy);
		tmp = find_node(loopy);

		if (tmp == 0) tmp = root[0];
	}
	
	//printing final string
	retV.print_vector();

}//
 ///////
 ////////

template<class T>
bool SkipList_Markov<T>::isempty()
{
	return root[0] == 0;

}//
 ///////
 ////////

template<class T>
void SkipList_Markov<T>::insert(T key, T elem)
{
	SkipList_Markov_Node<T>* curr[maxLevel];
	SkipList_Markov_Node<T>* prev[maxLevel];
	SkipList_Markov_Node<T>* newNode;

	int lvl, i;

	curr[maxLevel - 1] = root[maxLevel - 1];
	
	prev[maxLevel - 1] = 0;


	for (lvl = maxLevel - 1; lvl >= 0; lvl--) {

		//compare when the key is bigger than the info and move down to next level
		while (curr[lvl] && curr[lvl]->info.compare(key) < 0) {
	
			prev[lvl] = curr[lvl];
			curr[lvl] = *(curr[lvl]->next + lvl);
		}
		
		//check for the case when its the same key
		if (curr[lvl] && curr[lvl]->info.compare(key) == 0) {
			
			//adding in the vector if the node was already there
			curr[lvl]->addNew(elem);
		
			return;
		}
		
		if (lvl > 0) {

			if (prev[lvl] == 0) {

				curr[lvl - 1] = root[lvl - 1];
				prev[lvl - 1] = 0;
			}
			else {

				curr[lvl - 1] = *(prev[lvl]->next + (lvl - 1));
				prev[lvl - 1] = prev[lvl];
			}
		}
	}

	//random level chosen based on a probibalistic random function 
	lvl = probabilise2();
	newNode = new SkipList_Markov_Node<T>;
	newNode->addNew(elem);
	newNode->next = new SkipList_Markov_Node<T>* [sizeof(SkipList_Markov_Node<T>*) * (lvl + 1)];
	newNode->info = key;
	
	for (i = 0; i <= lvl; i++) {
		*(newNode->next + i) = curr[i]; //setting the next poiinter array
		
		//setting the values in the pointers of previous arrays
		if (prev[i] == 0) root[i] = newNode; 
		else *(prev[i]->next + i) = newNode;
	}
}//
// ///////
// ////////


//constructor
template<class T>
SkipList_Markov<T>::SkipList_Markov()
{
	for (int i = 0; i < maxLevel; i++) {
		root[i] = 0;
	}
}//
 ///////
 ////////


template<class T>
void SkipList_Markov<T>::probabilise1()
{
	prob[maxLevel - 1] = (2 << (maxLevel - 1)) - 1;
	for (int i = maxLevel -2, j=0; i >= 0; i--, j++) {
		prob[i] = prob[i + 1] - (2 << j);
	}

}//
 ///////
 ////////


template<class T>
int SkipList_Markov<T>::probabilise2()
{
	// gives r random values upto 16 and hence giving a probabilistic outcome
	int i, r = rand() % (prob[maxLevel - 1] + 1);
	
	for (i = 1; i < maxLevel; i++) {

		if (r < prob[i]) {
			
			return (i - 1);
		}
	}
	return (i - 1);

}//
 ///////
 ////////


template<class T>
SkipList_Markov_Node<T>* SkipList_Markov<T>::find_node(T key)
{
	if (isempty())return 0;
	SkipList_Markov_Node<T>* prev;
	SkipList_Markov_Node<T>* curr;

	int lvl;

	for (lvl = maxLevel - 1; lvl >= 0 && !root[lvl]; lvl--);
	
	
	prev = curr = root[lvl];
	while (true) {

		if (key.compare(curr->info) == 0) {
			return curr;
		}//
		
		else if (key.compare(curr->info) < 0 ) {
			if (lvl == 0)return 0;
			else if (curr == root[lvl])curr = root[--lvl];
			else curr = *(prev->next + --lvl);
		}//

		else {
			prev = curr;
			if (*(curr->next + lvl) != 0) curr = *(curr->next + lvl);
			else {
				for (lvl--; lvl >= 0 && *(curr->next + lvl) == 0; lvl--);
				if (lvl >= 0) curr = *(curr->next + lvl);
				else return 0;
			}
		}//
	}//end of while

}//
 ///////
 ////////

