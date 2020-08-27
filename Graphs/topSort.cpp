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