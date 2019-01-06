// C++ Implementation of Kosaraju's algorithm to print all SCCs
#include "GraphAnal.h"


#define A1 -1
#define A2 -2
using namespace std;


GraphAnal::GraphAnal(int V)
{
	this->V = V;
	adj = new list<int>[V];

	this->index = 0;
}

void GraphAnal::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

GraphAnal GraphAnal::getTranspose()
{
	GraphAnal g(V);
	for (int v = 0; v < V; v++)
	{

		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			g.adj[*i].push_back(v);
		}
	}
	return g;
}

void GraphAnal::addEdge(int v, int w)
{
	adj[v].push_back(w); 
}

void GraphAnal::processFill(int v, bool visited[], stack<int> &Stack)
{

	visited[v] = true;

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			processFill(*i, visited, Stack);


	Stack.push(v);
}

void GraphAnal::displayStrong()
{
	stack<int> Stack;

	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			processFill(i, visited, Stack);

	// reversed graph
	GraphAnal gr = getTranspose();

	// vertices marked not visited for 2nd DFS
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// stack process
	while (Stack.empty() == false)
	{

		int v = Stack.top();
		Stack.pop();

	
		if (visited[v] == false)
		{
			gr.DFSUtil(v, visited);
			cout << endl;
		}
	}
}


/////////////
//////////////


int GraphAnal::recurseCycle(int v, bool visited[], int* cycleVert, bool *recStack)
{
	if (visited[v] == false)
	{

		visited[v] = true;
		recStack[v] = true;


		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			if (!visited[*i])
			{
				int result = recurseCycle(*i, visited, cycleVert, recStack);
				if (result == A1)
					return A1;
				else if (result != A2) {
					cycleVert[index++] = v;
					if (result == v)
						return A1;
					else
						return result;
				}
			}
			else if (recStack[*i]) {
				return false;
			}

		}

	}
	recStack[v] = false;  
	return false;
}

bool GraphAnal::isCyclic(int *cycleVertices)
{

	bool *visited = new bool[V];
	bool *recStack = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
		recStack[i] = false;
	}

	for (int i = 0; i < V; i++)
		if (recurseCycle(i, visited, cycleVertices, recStack))
			return true;

	return false;
}

///////////////
//////////////


void GraphAnal::recurseTopoSort(int v, bool visited[],
	stack<int> &Stack)
{

	visited[v] = true;

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			recurseTopoSort(*i, visited, Stack);

	Stack.push(v);
}


void GraphAnal::topologicalSort()
{
	stack<int> Stack;


	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;


	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			recurseTopoSort(i, visited, Stack);


	while (Stack.empty() == false)
	{
		cout << Stack.top() << " ";
		Stack.pop();
	}
}