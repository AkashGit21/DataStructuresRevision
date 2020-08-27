#include <bits/stdc++.h>
using namespace std;

#include "Graphs/graph.cpp"
#include "Trees/tree.cpp"
#include "Grid/grid.cpp"

int main(){
	Graph G1; int startingNode=1, endingNode=3;
	G1.takeInput();
	/*cout<<"\nDFS: ";	
	int numOfComponents = G1.dfs(startingNode);
	cout<<"\nNumber of Connected Components: "<<numOfComponents;
	*/
	/*
	cout<<"\nBFS: ";
	vector<int> prev = G1.bfs(startingNode);
	cout<<"\nPath: ";
	//To construct minimum distance path from S to E in
	// unweighted graph
	vector<int> path = G1.reconstructPathFromBFS(prev,
		startingNode, endingNode);
	for(int node:path) cout<<" "<<node;
	*/

	/*Grid G;
	G.takeInput();
	cout<<"Distance: "<<G.bfsOnGrid(1,1);
	*/

	cout<<"Topological Sort: ";
	G1.topologicalSort();

	return 0;
}