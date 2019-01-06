#pragma once

#include <iostream>
#include <cstdlib>

class AdjacencyMatrix
{
private:
	int n;
	int **adj;
	bool *visited;
public:
	
	AdjacencyMatrix(int n);
	
	void add_edge(int origin, int destin);

	void display();
};
