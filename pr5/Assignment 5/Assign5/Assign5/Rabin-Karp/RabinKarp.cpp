#pragma once

#include<stdio.h>
#include<string.h>
#include <iostream>


//number of characters in alphabet
#define d 256

using namespace std;
/*
q -> A prime number
*/
class RabinKarp {

	int q = 101;
public:
	void search(char *pat, char *txt)
	{
		int M = strlen(pat);
		int N = strlen(txt);

		int i, j;
		int p = 0; 
		int t = 0; 
		int h = 1;

		for (i = 0; i < M - 1; i++)
			h = (h*d) % q;

		for (i = 0; i < M; i++)
		{
			p = (d*p + pat[i]) % q;
			t = (d*t + txt[i]) % q;
		}


		for (i = 0; i <= N - M; i++)
		{

			if (p == t)
			{
				for (j = 0; j < M; j++)
				{
					if (txt[i + j] != pat[j])
						break;
				}

				if (j == M)
					printf("Pattern found at index %d \n", i);
			}

			
			if (i < N - M)
			{
				t = (d*(t - txt[i] * h) + txt[i + M]) % q;

				
				if (t < 0)
					t = (t + q);
			}
			
		}
	}
};
