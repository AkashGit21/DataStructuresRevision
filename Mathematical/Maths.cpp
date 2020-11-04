class Maths{
public:
	vector<bool> isPrime;
	vector<int> primes;
	ll fac[SIZE], inv[SIZE];

	ll powMod(ll a, ll b){
		ll res=1LL;
		while(b){
			if(b&1) res=(res*a)%MOD;
			a=(a*a)%MOD;
			b>>=1;
		}
		return res;
	}

	void getFactorial(){
		fac[0]=inv[0]=1LL;
		for(int i=1;i<SIZE;i++){
			fac[i] = (fac[i-1]*i)%MOD;
			inv[i] = (inv[i-1]*powMod(i,MOD-2))%MOD;
		}
	}

	void seive(){
		isPrime.resize(SIZE,true);
		isPrime[0]=isPrime[1]=false;

		for(ll i=2;i*i<SIZE;i++){
			if(!isPrime[i]) continue;
			for(ll j=i*i;j<SIZE;j+=i){
				isPrime[j]=false;
			}
		}
		for(int i=2;i<SIZE;i++)
			if(isPrime[i])	primes.push_back(i);		
	}

	
};
