#include "Hello.h"

void Hello::printVector() {
	int n = vec.size();
	for (int i = 0; i < 10; ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}//end of print vector
/////////

void Hello::dispmenu1()
{
	int answer;

	std::cout << "Pick from file choices 1, 2, or 3, depending on what you want from the menu.\n";
	std::cout << "1. Ascending.txt" << std::endl;
	std::cout << "2. Descending.txt" << std::endl;
	std::cout << "3. Random.txt" << std::endl;
	std::cout << "Any other. Exit" << std::endl;

	std::cin >> answer;

	switch (answer)
	{
	case 1:
		file.open("../Sorting/Test_Assign2/ascending.txt");
		break;

	case 2:
		file.open("../Sorting/Test_Assign2/descending.txt");
		std::cout << "switch" << std::endl;
		break;

	case 3:
		file.open("../Sorting/Test_Assign2/random.txt");
		break;

	default:
		exit(0);
	}

}// end of file display menu
 /////////////
 ///////////////

void Hello::dispmenu2()
{
	int answer;

	std::cout << "Pick from sorting algorithm choices 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 depending on what you want from the menu.\n";
	std::cout << "1. Insertion Sort" << std::endl;
	std::cout << "2. Selection Sort" << std::endl;
	std::cout << "3. Bubble Sort" << std::endl;
	std::cout << "4. Comb Sort" << std::endl;
	std::cout << "5. Shell Sort" << std::endl;
	std::cout << "6. Heap Sort" << std::endl;
	std::cout << "7. Merge Sort" << std::endl;
	std::cout << "8. Quick Sort" << std::endl;
	std::cout << "9. Radix Sort" << std::endl;
	std::cout << "10. Intro Sort" << std::endl;
	std::cout << "11. Counting Sort" << std::endl;

	std::cout << "Any other. Exit" << std::endl;

	std::cin >> answer;

	switch (answer)
	{
	case 1:
		ins = new InsertionSort;
		break;

	case 2:
		ins = new SelectionSort;
		std::cout << "switch" << std::endl;
		break;

	case 3:
		ins = new BubbleSort;
		break;

	case 4:
		ins = new CombSort;
		break;

	case 5:
		ins = new ShellSort;
		std::cout << "switch" << std::endl;
		break;

	case 6:
		ins = new HeapSort;
		break;
	case 7:
		ins = new MergeSort;
		break;

	case 8:
		ins = new QuickSort;
		std::cout << "switch" << std::endl;
		break;

	case 9:
		ins = new RadixSort;
		break;
	case 10:
		ins = new IntroSort;
		break;

	case 11:
		ins = new CountingSort;
		std::cout << "switch" << std::endl;
		break;

	default:
		exit(0);
	}

}// end of file display menu
 /////////////
 ///////////////


void Hello::createVec(int i) {
	std::string line;
	int count = 0;
	std::cout << "createVec" << std::endl;
	
	//loop to read file line by line
	while (getline(file, line) && count < i)
	{
		//std::cout << "line loop" << std::endl;
		count++;
		std::stringstream linestream(line);
		std::string value;

		//loop to read line value by value
		while (getline(linestream, value, '-'))
		{
			//std::cout << "Value(" << value << ")\n";
			int val = atoi(value.c_str());
			vec.push_back(val);

		}//end of while value loop


	}//end of while line loop

}// end of create vector
 //////////////
 /////////////


int main(int argc, char * argv[]) {

	
	while (true) {
		Hello hel1;
		hel1.dispmenu1();
		hel1.dispmenu2();

		for (int i = 100; i<200000; i *= 2) {
			if (i > 100000)i = 100000;
			hel1.createVec(i);
			//hel1.printVector();
			
			WindowsStopwatch wat1;
			wat1.start();
			//hel1.wat1.start();
			hel1.ins->bar(hel1.vec);
			//hel1.wat1.stop();
			wat1.stop();
			std::cout << "getting time of algo run for first " << i << "0 elements..." << wat1.getTime() << std::endl;

			//hel1.printVector();
			

			//clearing vector to insert from begining 
			hel1.vec.clear();

			//clearing file to be read from the beginning
			hel1.file.clear();
			hel1.file.seekg(0, hel1.file.beg);

		}//for loop each iteration 


	}//while loop menu display

	return(0);

}// end of main

