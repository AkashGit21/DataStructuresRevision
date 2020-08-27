
class Grid{
	vector<string> G;
	int R,C;
public:	
	void takeInput(){
		cin>>R>>C;
		string S;
		for(int i=0;i<R;++i){
			cin>>S; 
			G.push_back(S);
		}
	}
	void exploreNeighbors(int row, int col,
		vector<vector<bool> > &vis,
		queue<int> &qR,queue<int> &qC, int &ninl);
	int bfsOnGrid(int startingRow,int startingCol);
};
#include "bfsOnGrid.cpp"