
class UnionFind{
  vector<int> par, rank, sz;
  int sets=0;

  public:
  UnionFind(int N) {
    rank.assign(N,0);
    par.assign(N,0);
    sz.assign(N,1);
    sets = N;
    for(int i=0;i<N;i++) par[i]=i;
  }

  int findSet(int i) {
    return (par[i]==i)?i:(par[i]=findSet(par[i]));
  }
  
  bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
  }

  int numDisjointSets() {
    return sets;
  }

  int sizeOfSet(int i) {
    return sz[i];
  }

  void unionSet(int i, int j) {
    if(!isSameSet(i,j)) {
      int x = findSet(i), y= findSet(j);
      if(rank[x]>rank[y]){
        par[y]=x;
        sz[x]+=sz[y];
      }
      else{
        par[x]=y;
        sz[y]+=sz[x];
        if(rank[x]==rank[y]) rank[y]++;
      }
      sets--;
    }
  }

};