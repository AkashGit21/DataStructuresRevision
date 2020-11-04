
bool Graph::bfsEdmonds(vector<vector<ll> > residualG, int s, int t, vector<int> &par){
	visited.clear();
	visited.resize(numOfNodes,false);
	queue<int> q;
	q.push(s);
	visited[s]=true;
	par[s] = -1;

	while(!q.empty()){
		int u=q.front();q.pop();
		//cout<<u<<" ";
		for(int v=0;v<numOfNodes;++v){
			if( (!visited[v]) && residualG[u][v]>0){
				q.push(v);
				par[v]=u;
				visited[v]=true;
			}
		}
	}
	return (visited[t]==true);
}

ll Graph::edmondsKarp(int s, int t){

	vector<vector<ll> > residualG;
	residualG.resize(numOfNodes,vector<ll>(numOfNodes,0));

	for(int i=0;i<numOfNodes;++i)
		for(int j=0;j<numOfNodes;++j) 
			residualG[i][j] = G[i][j];

	vector<int> par; par.resize(numOfNodes);
	ll maxFlow=0;

	int cnt=0;
	while( bfsEdmonds(residualG,s,t,par) ){
		ll pathFlow = LONG_MAX;
		for(int v=t;v!=s;v=par[v]){
			int u=par[v];
			pathFlow = min(pathFlow, residualG[u][v]);
		}

		for(int v=t;v!=s;v=par[v]){
			int u=par[v];
			printf("\nEdge %2d->%2d | flow = %9lld | capacity = %9lld |",
				u,v,pathFlow,residualG[u][v]);
			residualG[u][v] -= pathFlow;
			//residualG[v][u] += pathFlow;
		}
		maxFlow += pathFlow;
		cout<<"\n";
	}
	return maxFlow;
}
