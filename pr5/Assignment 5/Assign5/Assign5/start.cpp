#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include<vector>

#include "Rabin-Karp/RabinKarp.cpp"
#include "KnuthMoris/KnuthMoris.cpp"
#include "BoyerMoore/BoyerMoore.cpp"

#include "AhoChorasick/AhoChorasick.cpp"
#include "Bitoriented/Bitoriented.cpp"

#include "SuffTree/SuffTree.cpp"

#include "WINSTOPWATCH/WindowsStopwatch.h" 

using namespace std;

int main(){

	cout << "Please wait, reading files...." << endl;
	
	RabinKarp *rk = new RabinKarp();
	KnuthMoris *km = new KnuthMoris();
	BoyerMoore *bm = new BoyerMoore();
	
	AhoChorasick *ac = new AhoChorasick();
	Bitoriented *bo = new Bitoriented();

	SuffTree *st = new SuffTree();

	WindowsStopwatch *watch = new WindowsStopwatch();
	
	char txt[] = "ABCBCABACDABABCABCB";
	char pat[] = "ABC";
	
	vector<string> patArr;

	char* cTxt;
	char* cPat;
	std::string text;

	std::ifstream file("T.txt");
	std::string word;

	file >> word;
	
	file.close();

	text = word;
	cTxt = &word[0];

	printf("T read\n");


	/////////T.text read
	std::ifstream file2("P.txt");
	std::string word2;

	while (file2 >> word2) {

		patArr.push_back(word2);
	}
	file2.close();
	printf("P read\n");



	
	//Part 1
	for (int j = 0; j < patArr.size(); j++) {
		
		cout << "Pattern String::: " << patArr[j] << endl;
		cPat = &patArr[j][0];
		printf("\n");

		watch->start();
		rk->search(cPat, cTxt);
		watch->stop();
		std::cout << "Time of Rabin Karp algo run: " << (j+1) << ":::: " << watch->getTime() << "ms" <<std::endl;
		
		printf("\n");
		watch->start();
		km->KMPSearch(cPat, cTxt);
		watch->stop();
		std::cout << "Time of Knuth Morris algo run: " << (j + 1) << ":::: " << watch->getTime() << "ms" << std::endl;

		printf("\n");
		watch->start();
		bm->search(cTxt, cPat);
		watch->stop();
		std::cout << "Time of Boyer Moore algo run: " << (j + 1) << ":::: " << watch->getTime() << "ms" << std::endl;
		printf("\n\n\n");
		
	}



	//Part 2
	printf("\nBitap(ShiftAnd) Algorithm is going to take some time. Please wait....\n\n");
	long totalTime = 0;
	for (int j = 0; j < patArr.size(); j++) {
		string sPattest = patArr[j];
		cout << "Pattern String::: " << sPattest << endl;

		watch->start();
		bo->shiftAnd(sPattest, text);
		watch->stop();
		totalTime += watch->getTime();
		printf("\n");
	}
	std::cout << "Total Time of Bit Oriented algo run: " << totalTime << "ms" << std::endl;

	printf("\n\n");
	watch->start();
	ac->searchWords(patArr, patArr.size(), text);
	watch->stop();
	std::cout << "Total Time of Aho Corasick algo run: " << watch->getTime() << "ms" << std::endl;

	
	
	//Part3	
	st->text = cTxt;
	watch->start();
	st->buildSuffixTree();
	watch->stop();
	std::cout << "Preprocessing time: " << watch->getTime() << "ms" << std::endl;
	
	watch->start();
	for (int j = 0; j < patArr.size(); j++) {
		
	        cout << patArr[j] << endl;
			cPat = &patArr[j][0];
			
			st->checkForSubString(cPat);

			
		}

	watch->stop();
	std::cout << "Search time: " << watch->getTime() << "ms" << std::endl;
	return 0;
}
