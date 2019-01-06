#include "AdjMatrix/AdjMatrix.h"
#include "FindPack/FindPack.h"
#include "FindInclude/FindInclude.h"
#include "GraphAnal/GraphAnal.h";

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	
	//Enter the path of the directory to be processed with...FORWARD slashes...
	//example::: if the path is D:\abc\qwe\d where d is the directory to be processed.
	//then input the address as D:/abc/qwe/d
	//If there is no input, the program will run on the below Test directory

	printf("\n\n\n");

   string PATH = "./InstrSolProject1S17/";

	FindPack *fp = new FindPack();
	fp->readPackages(PATH);

	printf("\n\n\n");
	
	

	FindInclude *fi = new FindInclude();
	for (string package: fp->pack) {
		fi->set_map(package);
		
		string path1 = PATH + package + "/" + package + ".h";
		string path2 = PATH + package + "/" + package + ".cpp";

		fi->readFile(path1, package);
		fi->readFile(path2, package);
	}
	

	
	int pack_size = fp->pack.size();
	AdjacencyMatrix *am = new AdjacencyMatrix(pack_size);
	GraphAnal *g = new GraphAnal(pack_size);
	
	for (int i = 0; i < pack_size; i++) {
		
		
		vector<string> vec1 = fi->mymap[fp->pack[i]];
		for (string dest: vec1) {
			int j = 0;
			for (; j < pack_size && dest.compare(fp->pack[j]) != 0; j++);
			am->add_edge(i+1, j+1);
			g->addEdge(i,j);
		}
		
	}
	cout << "Adjacency matrix in order with the above printed packages:::"<< endl;
	am->display();

	printf("\n\n\n");

	cout << "Mapped file dependency are:::" << endl;
	fi->display_map();

	printf("\n\n\n");

	//////////
	cout << "Strongly connected components displayed using DFS::: \n";
	g->displayStrong();

	printf("\n\n\n");

	/////////
	int cycleVertices[4];
	for (int i = 0; i < 4; i++)
		cycleVertices[i] = -1;

	if (g->isCyclic(cycleVertices)) {
		cout << "Graph contains cycle:::" << endl;
		int x = 0;
		while (cycleVertices[x] != -1)
			cout << cycleVertices[x++] << " ";
	}
	else
		cout << "Graph doesn't contain cycle::::" << endl;
	
	printf("\n");
	///////////

	cout << "Following is a Topological Sort of the given graph \n";
	g->topologicalSort();
	
	return 0;
}

