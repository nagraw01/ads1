#include "AdjMatrix.h"

using namespace std;
#define MAX 20

AdjacencyMatrix::AdjacencyMatrix(int n)
{
	this->n = n;
	visited = new bool[n];
	adj = new int*[n];
	for (int i = 0; i < n; i++)
	{
		adj[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			adj[i][j] = 0;
		}
	}
}
/*
* Adding Edge to Graph
*/
void AdjacencyMatrix::add_edge(int origin, int destin)
{
	if (origin > n || destin > n || origin < 0 || destin < 0)
	{
		cout << "Invalid edge!\n";
	}
	else
	{
		adj[origin - 1][destin - 1] = 1;
	}
}
/*
* Print the graph
*/
void AdjacencyMatrix::display()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << adj[i][j] << "  ";
		cout << endl;
	}
}