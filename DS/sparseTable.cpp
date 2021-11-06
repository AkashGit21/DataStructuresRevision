

class SparseTable{
private:
  vector<int> _A;
  vector<vector<int> > SpT;

public:
  SparseTable(int n, int A[]){  // constructor as well as pre-processing routine
    _A.resize(n);
    int log_two_n = log(n)+1;
    SpT.resize(n,vector<int>(log_two_n));

    for(int i=0;i<n;i++){
      _A[i] = A[i];
      SpT[i][0] = i; // RMQ of sub-array starting at index i + length 2^0=1
    }
  
    for(int j=1; (1<<j)<=n; j++){
      for(int i=0;i+(1<<j)-1<n;i++){
        if(_A[SpT[i][j-1]] < _A[SpT[i+(1<<(j-1))]][j-1])
          SpT[i][j] = SpT[i][j-1];
        else
          SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
      }
    }
  }

  int query(int i, int j){
    int k = (int)floor(log((double)j-i+1)/log(2.0));
    if(_A[SpT[i][k]] <= _A[SpT[j-(1<<k)+1][k]]) return SpT[i][k];
    else return SpT[j-(1<<k)+1][k];
  }

};