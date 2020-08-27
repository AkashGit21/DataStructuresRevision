#include <bits/stdc++.h>
using namespace std;

#include "Graphs/graph.cpp"
#include "Trees/tree.cpp"

int main(){
	Graph G1;
	G1.takeInput();
	cout<<"\nDFS: ";	int numOfComponents = G1.dfs(1);
	cout<<"\nNumber of Connected Components: "<<numOfComponents;
	return 0;
}