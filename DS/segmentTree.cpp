
class SegmentTree {
  vector<int> st, A;
  int n;
  int left(int p){ return p<<1; }
  int right(int p){ return p<<1 + 1; }

  void build(int p, int L, int R) {
    if(L==R) st[p]=A[L];
    else {
      build( left(p), L, (L+R)/2 );
      build( right(p), (L+R)/2+1, R );
      int p1 = st[left(p)], p2=st[right(p)];
      st[p] = (p1<=p2)?p1:p2;
    }
  }

  int rmq(int p, int L,int R,int i,int j){
    if(i>R||j<L) return INT_MAX;
    if(L>=i && R<=j) return st[p];

    int p1 = rmq(left(p), L, (L+R)/2, i, j);
    int p2 = rmq(right(p), (L+R)/2+1, R, i, j);

    return (p1<=p2)?p1:p2;
  }

  int update(int p,int L,int R,int i,int v){
    if(L>i||R<i) return INT_MAX;
    if(L==R && i==L) {
      A[p] = v;
      st[p] = v;
      return v;
    }

    int p1 = rmq(left(p), L, (L+R)/2, i, v);
    int p2 = rmq(right(p), (L+R)/2+1, R, i, v);
    return (p1<=p2)?p1:p2;
  }

  public:
  SegmentTree(const vector<int> &_A){
    A=_A; n=(int)A.size();
    st.assign(4*n,0);
    build(1,0,n-1);
  }
  int rmq(int i, int j){
    return rmq(1,0,n-1,i,j);
  }
};