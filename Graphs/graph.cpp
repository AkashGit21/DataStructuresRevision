
class Graph{
	int numOfNodes,numOfVertices;
	vector<vector<int> > G;
	map<pair<int,int>,ll> edgeW;
public:
	void takeInput(){
		cin>>numOfNodes>>numOfVertices;
		G.resize(numOfNodes+1,vector<int>());

		int u,v; ll w;
		for(int i=0;i<numOfVertices;++i){
			cin>>u>>v;
			cin>>w;
			G[u].push_back(v);
			edgeW[{u,v}]=w;
		//	G[v].push_back(u);
		//	edgeW[{min(u,v),max(u,v)}]=w;
		}
	}
	void dagInput(){
		cin>>numOfNodes>>numOfVertices;
		G.resize(numOfNodes+1,vector<int>());

		int u,v; ll weight;
		for(int i=0;i<numOfVertices;++i){
			cin>>u>>v>>weight;
			G[u].push_back(v);
			edgeW[{u,v}]=weight;
		}
	}
	
	void dfsUtil(int startingNode,int source,vector<bool> &visited);
	int dfs(int startingNode);
	
	vector<int> bfs(int startingNode);
	vector<int> reconstructPathFromBFS(vector<int> prev,
			int startingNode, int endingNode);
	int bfsOnGrid(int startingRow, int startingCol);
	
	void tSortUtil(int node, vector<bool> &vis,
	vector<int> &order);
	vector<int> topologicalSort();
	vector<vector<ll> > dagShortestPath();
	vector<int> getPath(vector<vector<ll> > dist,
	int startingNode, int endingNode);

	vector<vector<ll> > lazyDijkstra(int startingNode);

	vector<ll> bellmanFord(int startingNode);
};
#include "dfs.cpp"
#include "bfs.cpp"
#include "topSort.cpp"
#include "getPath.cpp"
#include "dijkstra.cpp"
#include "bellmanFord.cpp"