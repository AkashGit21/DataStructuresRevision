

class FenwickTree{
  vector<int> ft;
  int LSOne(int s) {return s&(-s); }
  
  public:
  FenwickTree(int n) {
    ft.assign(n+1,0);
  }
  int rsq(int b){
    int sum=0;
    for(;b;b-=LSOne(b)) sum+=ft[b];
    return sum;
  }

  int rsq(int a, int b) {
    return rsq(b) - (a==1 ? 0:rsq(a-1));
  }

  void adjust(int k, int v) {
    for(;k<(int)ft.size();k+=LSOne(k)) ft[k]+=v;
  }

};