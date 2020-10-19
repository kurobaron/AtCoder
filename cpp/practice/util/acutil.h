#include <vector>
#include <algorithm>
using namespace std;

namespace atcoder{
	struct UnionFind{
		UnionFind(long long n) : p(n),size(n,1),rank(n,1){
			for(long long i=0;i<n;++i) p.at(i) = i;
		}

		//xが属している木構造の根ノードを返す
		long long Root(long long x){
			return p.at(x)==x ? x : p.at(x) = Root(p.at(x));
		}
		
		//xが属している木構造とyが属している木構造を結合する
		void Unite(long long x, long long y){
			x = Root(x);
			y = Root(y);
			if(x==y) return;
			if(rank.at(x) < rank.at(y)){
				p.at(x) = y;
				size.at(y) += size.at(x);
			}
			else{
				p.at(y) = x;
				size.at(x) += size.at(y);
				if(rank.at(x)==rank.at(y)) ++rank.at(x);
			}
		}

		//xが属している木構造のノードの総数を返す
		long long Size(long long x){
			x = Root(x);
			return size.at(x);
		}

		//xが属している木構造の深さを返す
		long long Rank(long long x){
			x = Root(x);
			return rank.at(x);
		}

	private:
		vector<long long> p;
		vector<long long> size;
		vector<long long> rank;

	};
	


	struct CombInv{
		const long long MOD = 1e9+7;

		//nPrを返す
		long long Permutation(long long n, long long r){
			long long tmp = 1;
			long long i = n;
			while(i!=n-r){
				tmp *= i;
				tmp %= MOD;
				--i;
			}
			return tmp;
		}

		//x!を返す
		long long Factorial(long long x){
			long long tmp = 1;
			long long i = 1;
			while(i<=x){
				tmp *= i;
				tmp %= MOD;
				++i;
			}
			return tmp;
		}

		//x^pを返す
		long long FastPow(long long x, long long p){
			if(p==1) return x;
			if(p%2==0){
				long long sr = FastPow(x, p/2);
				return (sr*sr)%MOD;
			}else{
				long long sr = FastPow(x, (p-1)/2);
				return ((x*sr)%MOD*sr)%MOD;
			}
		}

		//chi/parをMODで割った余りを返す
		long long FractionalRemainder(long long par, long long chi=1){
			return (chi%MOD*FastPow(par, MOD-2))%MOD;
		}

		//nCrを返す
		long long Combination(long long n, long long r){
			return (Permutation(n,r)*(FractionalRemainder(Factorial(r))))%MOD;
		}
	};



	struct CombDp{
		const long long MOD = 1e9+7;

		//デフォルトでは最大1000C1000まで計算できるよう初期化
		CombDp(long long n=1001) : c(n, vector<long long>(n)){
			for(long long i=0;i<n;++i){
				c.at(i).at(0) = 1;
				c.at(i).at(i) = 1;
				for(long long j=1;j<i;++j){
					c.at(i).at(j) = (c.at(i-1).at(j-1)+c.at(i-1).at(j))%MOD;
				}
			}
		}

		//nCrを返す
		long long Combination(long long n, long long r){
			return c.at(n).at(r);
		}
	
	private:
		vector<vector<long long>> c;
	};



	struct Sieve{
		Sieve(long long n=1e5+1) : isPrime(n,1),factor(n,1){
			isPrime.at(0) = 0; isPrime.at(1) = 0;
			for(long long i=2;i*i<n;++i){
				if(!isPrime.at(i)) continue;
				long long idx = i;
				while(idx<n){
					if(idx!=i) isPrime.at(idx) = 0;
					factor.at(idx) = i;
					idx += i;
				}
			}
		}

		bool IsPrime(long long x){
			return isPrime.at(x);
		}
		
		//素因数を重複ありでvectorとして降順で返す
		vector<long long> PrimeFactors(long long x){
			vector<long long> divisor;
			if(x==0) return divisor;
			while(x!=1){
				divisor.push_back(factor.at(x));
				x /= factor.at(x);
			}	
			return divisor;
		}

		//素因数を重複なしでvectorとして降順で返す
		vector<long long> UniquePrimeFactors(long long x){
			vector<long long> divisor = PrimeFactors(x);
			divisor.erase(unique(divisor.begin(), divisor.end()), divisor.end());
			return divisor;
		}

	private:
		vector<long long> isPrime;
		vector<long long> factor;
	};



	int GCD(int a, int b){
		if(a>b) swap(a,b);
		while(b%a!=0){
			int t = b%a;
			b = a;
			a = t;
		}
		return a;
	}
}
