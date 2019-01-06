
#include "Test.h"

using namespace std;

int main() {

	ifstream file("filename.txt");
	string word;
	IVector<string> ws;
	Test<string> test1;

	while (file >> word) {
		ws.push_back(word);
	}

	cout << endl << "Vector string created" << endl;
	
	//after string vector created..start of data struc creation
	test1.menuDisplay();

	//looping the values in vector into data struc
	//DLL_Markov<string> ds;
	for (int i = 0; i < ws.size()-1;i++) {
		test1.mark->add(ws[i],ws[i+1]);
	}
	
	// training done

	puts("enter the length of string to be generated");
	int len; 
	cin >> len;
	test1.mark->generate(len);

	return 0;
}

template<class T>
void Test<T>::menuDisplay()
{
	int choice;
	cout << endl << "----------------------------" << endl;
	cout << endl << "Operations Menu" << endl;
	cout << endl << "----------------------------" << endl;
	cout << "1. doubly linked list markov" << endl;
	cout << "2. multi linked list markov" << endl;
	cout << "3. skip list markov" << endl;
	cout << "4. quit" << endl;
	cout << "enter your choice : ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		mark = new DLL_Markov<T>;
		break;
	case 2:
		mark = new ML_Markov<T>;
		break;
	case 3:
		mark = new SkipList_Markov<T>;
		break;
	case 4:
		exit(1);
	default:
		cout << "wrong choice" << endl;
	}
}