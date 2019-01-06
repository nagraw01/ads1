#pragma once

#include <iostream>
#include <list>
#include <stack>
using namespace std;

class GraphAnal
{
	int V;  

	int index;

	void processFill(int v, bool visited[], stack<int> &Stack);

	void DFSUtil(int v, bool visited[]);

public:

	list<int> *adj;

	GraphAnal(int V);
	void addEdge(int v, int w);
	void displayStrong();
	GraphAnal getTranspose();

	int recurseCycle(int v, bool visited[], int *cycleVertices, bool *rs);
	bool isCyclic(int *cycleVertices);

	void recurseTopoSort(int v, bool visited[], stack<int> &Stack);
	void topologicalSort();
};
