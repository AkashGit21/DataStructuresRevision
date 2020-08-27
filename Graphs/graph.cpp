
class Graph{
	int numOfNodes,numOfVertices;
	vector<vector<int> > G;
public:
	void takeInput(){
		cin>>numOfNodes>>numOfVertices;
		G.resize(numOfNodes+1,vector<int>());

		int u,v;
		for(int i=0;i<numOfVertices;++i){
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
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
};
#include "dfs.cpp"
#include "bfs.cpp"
#include "topSort.cpp"