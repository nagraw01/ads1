#pragma once


using namespace std;
#include <string>
#include <queue>
#include <iostream>

#define MAXS (107*15+10)
#define MAXC 26

class AhoChorasick {

public:
	
	int out[MAXS];

	int f[MAXS];

	int g[MAXS][MAXC];

	int buildMatchingMachine(vector<string> arr, int k)
	{
	
		memset(out, 0, sizeof out);

		
		memset(g, -1, sizeof g);

		int states = 1;

		
		for (int i = 0; i < k; ++i)
		{
			const string &word = arr[i];
		
			int currentState = 0;

		
			for (int j = 0; j < word.size(); ++j)
			{
				int ch = word[j] - 'A';

			
				if (g[currentState][ch] == -1)
					g[currentState][ch] = states++;

				currentState = g[currentState][ch];
			}

			
			out[currentState] |= (1 << i);
		}


		for (int ch = 0; ch < MAXC; ++ch)
			if (g[0][ch] == -1)
				g[0][ch] = 0;


		memset(f, -1, sizeof f);

	
		queue<int> q;


		for (int ch = 0; ch < MAXC; ++ch)
		{

			if (g[0][ch] != 0)
			{
				f[g[0][ch]] = 0;
				q.push(g[0][ch]);
			}
		}


		while (q.size())
		{
		
			int state = q.front();
			q.pop();


			for (int ch = 0; ch < MAXC; ++ch)
			{
	
				if (g[state][ch] != -1)
				{
				
					int failure = f[state];
					cout << "b7::" << failure << endl;
					
					while (g[failure][ch] == -1)
						failure = f[failure];

					cout << "b8::" << failure << endl;
					failure = g[failure][ch];
					f[g[state][ch]] = failure;

					
					out[g[state][ch]] |= out[failure];

					q.push(g[state][ch]);
				}
			}
		}

		return states;
	}


	int findNextState(int currentState, char nextInput)
	{
		int answer = currentState;
		int ch = nextInput - 'A';

		while (g[answer][ch] == -1)
			answer = f[answer];

		return g[answer][ch];
	}


	void searchWords(vector<string> arr, int k, string text)
	{

		buildMatchingMachine(arr, k);
		cout << "build done" << endl;

		int currentState = 0;


		for (int i = 0; i < text.size(); ++i)
		{
			
			currentState = findNextState(currentState, text[i]);

	
			if (out[currentState] == 0)
				continue;

			for (int j = 0; j < k; ++j)
			{
				if (out[currentState] & (1 << j))
				{
					cout << "Pattern " << arr[j] << " found from "
						<< i - arr[j].size() + 1 << " to " << i << endl;
				}
			}
		}
	}

};

