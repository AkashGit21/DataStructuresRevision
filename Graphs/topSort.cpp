void Graph::tSortUtil(int node,vector<bool> &vis,
	vector<int> &order){
	vis[node]=true;
	for(int child:G[node]){
		if(vis[child]) continue;
		tSortUtil(child,vis,order);
	}
	order.push_back(node);
}

vector<int> Graph::topologicalSort(){
	vector<int> order;
	vector<bool> visited(numOfNodes+1,false);

	for(int i=1;i<=numOfNodes;i++){
		if(visited[i]) continue;
		tSortUtil(i,visited,order);
	}
	reverse(order.begin(), order.end());
	for(int tmp:order) cout<<" "<<tmp;
	return order;
}

vector<vector<ll> > Graph::dagShortestPath(){
	vector<int> order = topologicalSort();
	vector<ll> prev(numOfNodes+1,-1);
	vector<ll> dist(numOfNodes+1,1e18+1);
	dist[order[0]]=0LL;
	for(int i=0;i<order.size();i++){
		for(int child:G[order[i] ]){
			ll newDist = dist[order[i]] + 
				edgeW[{order[i],child}];
			if(newDist<dist[child]){
				prev[child]=order[i];
				dist[child]=newDist;
			}
		}
	}
	for(int i=1;i<=numOfNodes;i++)
		cout<<i<<" "<<dist[i]<<"\n";
	return {dist,prev};
}

vector<int> Graph::getPath(vector<vector<ll> > dist,
	int startingNode, int endingNode){	
	vector<int> path;
	while(endingNode!=-1){
		//cout<<endingNode<<"\n";
		path.push_back(endingNode);
		endingNode = dist[1][endingNode];		
	}	
	reverse(path.begin(),path.end());
	if(path[0]!=startingNode) return {-1};
	else return path;
}