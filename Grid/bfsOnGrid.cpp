
void Grid::exploreNeighbors(int r,int c,
	vector<vector<bool> > &vis, queue<int> &qR,
	queue<int> &qC, int &ninl){
	int dr[]={-1,1,0,0}, dc[]={0,0,1,-1};

	for(int i=0;i<4;i++){
		int nR=r+dr[i], nC=c+dc[i];
		//Check for Invalid Points
		if(nR<0 || nC<0 || nR>=R || nC>=C) continue;
		// If cell is a Wall
		if(G[nR][nC]=='#' || vis[nR][nC]) continue;
		
		qR.push(nR); qC.push(nC);
		vis[nR][nC]=true;
		ninl++;
	}
}

int Grid::bfsOnGrid(int stRow, int stCol){
	queue<int> qR,qC;
	vector<vector<bool> > visited(R,vector<bool>(C,false));
	qR.push(stRow); qC.push(stCol);
	visited[stRow][stCol]=true;

	int moveCount=0, nodesLeftInLayer=1,
	nodesInNextLayer=0;
	bool reachedEnd=false;

	while(!qR.empty()){
		stRow=qR.front(); stCol = qC.front();
		qR.pop(); qC.pop();
		if(G[stRow][stCol]=='E'){
			reachedEnd=true;
			break;
		}
		exploreNeighbors(stRow,stCol,visited,
			qR,qC,nodesInNextLayer);
		nodesLeftInLayer--;

		if(nodesLeftInLayer==0){
			nodesLeftInLayer=nodesInNextLayer;
			nodesInNextLayer=0;
			moveCount++;
		}
	}
	if(reachedEnd)	return moveCount;
	else return -1;
}