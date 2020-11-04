#include <bits/stdc++.h>
#define ll long long
#define pil pair<int,ll>
#define piil pair<pair<int,int>,ll>
#define INF 1e18 + 2
#define SIZE 100002
#define LOGSIZE log2(SIZE)
#define MOD 1000000007
using namespace std;

#include "Graphs/graph.cpp"
#include "Trees/tree.cpp"
#include "Grid/grid.cpp"
#include "Algorithms/algo.cpp"
#include "Mathematical/Maths.cpp"

int main(){
	/*Graph G1; int startingNode=1, endingNode=5;
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

	cout<<"Topological Sort: ";
	G1.topologicalSort();
	
	G1.dagInput();
	cout<<"\nSSSP on DAG: ";
	vector<vector<ll> > dist = G1.dagShortestPath();
	cout<<"\nPath: ";
	vector<int> path = G1.getPath(dist, startingNode,
		endingNode);
	for(int tmp:path) cout<<tmp<<" ";
	
	cout<<"Dijkstra's Path: ";
	vector<vector<ll> > dist = G1.lazyDijkstra(startingNode);
	vector<int> path = G1.getPath(dist,startingNode,endingNode);
	for(int tmp:path)
		cout<<tmp<<" ";
	
	vector<ll> dist = G1.bellmanFord(startingNode);

	//vector<vector<ll> > dp = G1.floydWarshall();
	
	cout<<"\nBridges: ";
	vector<pair<int,int> > bridges =
	G1.findBridges();
	
	cout<<"\nArticulation Points: ";
	G1.findArticulationPoints();
	
	cout<<"Strongly Connected Components: ";
	cout<<G1.stronglyConnectedComponents()<<"\n";
	
	G1.adjMatInput();
	cout<<"Travelling Salesman Problem: ";
	G1.getPathTSP(0);
	
	G1.dagInput();
	G1.eulerPath();
	*/
	Graph G1;
	G1.adjMatInput();
	cout<<"Max Flow : "<<G1.edmondsKarp(0,5)<<"\n";


	//vector<vector<int> > mst = G1.primsMST();
	//cout<<"\nDFS of MST: "; 

	
	// Tree t1;
	// t1.takeInput();
	// cout<<"\nLCA:"<<t1.lca(6,9,1);
	
	// Maths mt;
	// mt.seive();

	// Algo a1;
	// vector<int> v{2,5,3,7,11,8,10,13,6};
	// cout<<"LIS: "<<a1.LIS(v)<<"\n";
	
	// Grid G;
	// G.takeInput();
	// cout<<"Distance: "<<G.bfsOnGrid(1,1);
	

	return 0;
}