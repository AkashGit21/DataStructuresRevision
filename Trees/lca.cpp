
void Tree::lcaUtil(int cur, int src,int dep){
	dp[cur][0]=src;
	depth[cur]=dep;
	
	for(int i=1;i<=LOGSIZE;i++)
		dp[cur][i]=dp[ dp[cur][i-1] ][i-1];
	for(int child:G[cur]){
		if(child==src) continue;
		lcaUtil(child,cur,dep+1);
	}
}

int Tree::lca(int u, int v, int root){
	dp.resize(SIZE,vector<int>(LOGSIZE+1,-1));
	depth.resize(numOfNodes+1,0);
	lcaUtil(root,-1,1);
	/*
	for(int i=1;i<=numOfNodes;i++){
		for(int j=0;j<=LOGSIZE;j++)
			cout<<dp[i][j]<<" ";
		cout<<"\n";
	}
	*/

	
		if(depth[u]<depth[v]) swap(u,v);
	//	cout<<"\n"<<u<<" "<<v;
		for(int i=LOGSIZE;i>=0;--i)
			if(dp[u][i]!=-1 && depth[dp[u][i]]>=depth[v]) u=dp[u][i];
	//	cout<<" "<<u<<" ";
		if(u==v) return u;
		for(int i=LOGSIZE;i>=0;--i)
			if(dp[u][i]!=dp[v][i])	u=dp[u][i], v=dp[v][i];
	//	cout<<u<<" "<<v;
		
	return dp[u][0];
}
