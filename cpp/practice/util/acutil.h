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


	struct SegmentTree{
		long long N = 1;
		SegmentTree(long long n=1e5){
			while(n>N) N *= 2;
			tree = vector<long long>(2*N-1);
		}		

		void Update(long long i, long long x, bool isMax=true){
			//i+1枚目の葉の値をxに更新する
			i = N-1+i;
			tree.at(i) = x;
			while(i>0){
				i = (i-1)/2;
				if(isMax) tree.at(i) = max(tree.at(i*2+1),tree.at(i*2+2));
				else tree.at(i) = min(tree.at(i*2+1),tree.at(i*2+2));
			}
		}

		long long Search(long long a, long long b, bool isMax=true){
			//[a,b)の範囲における最大値または最小値を返す
			if(b<=0||a>=N) return isMax ? -1 : INF; 
			else{
				if(isMax) return max(Search(a,b,isMax,0*2+1,0,(0+N)/2), Search(a,b,isMax,0*2+2,(0+N)/2,N));
				else return min(Search(a,b,isMax,0*2+1,0,(0+N)/2), Search(a,b,isMax,0*2+2,(0+N)/2,N));
			}
		}

		

	private:
		vector<long long> tree;
		const long long INF = 1e18;

		long long Search(long long a, long long b, bool isMax, long long k, long long l, long long r){
			//オーバーロード
			//[a,b)の範囲における最大値または最小値を返す
			if(b<=l||a>=r) return isMax ? -1 : INF; 
			if(a<=l&&r<=b) return tree.at(k);
			else{
				if(isMax) return max(Search(a,b,isMax,k*2+1,l,(l+r)/2), Search(a,b,isMax,k*2+2,(l+r)/2,r));
				else return min(Search(a,b,isMax,k*2+1,l,(l+r)/2), Search(a,b,isMax,k*2+2,(l+r)/2,r));
			}
		}
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
	

	//行列の積m1*m2を返す
	vector<vector<long long>> MatMal(vector<vector<long long>> &m1, vector<vector<long long>> &m2, long long r/*=m1の行*/, long long c/*=m2の列*/, long long h/*=m1の列,m2の行*/){
		long long i,j,k,elem,MOD = 1e9+7;
		vector<vector<long long>> matp(r, vector<long long>(c));
		for(i=0;i<r;++i){
			for(j=0;j<c;++j){
				elem = 0;
				for(k=0;k<h;++k){
					elem += m1.at(i).at(k)*m2.at(k).at(j);
					elem %= MOD;
				}
				matp.at(i).at(j) = elem;
			}
		}
		return matp;
	}
				

	//n*nの行列mのp乗を返す
	vector<vector<long long>> MatPow(vector<vector<long long>> &m, long long p, long long n){
		long long i,j,k,MOD = 1e9+7;
		vector<vector<long long>> m_p;
		if(p==1) return m;
		m_p = matpow(m, p/2, n);
		m_p = matmal(m_p, m_p, n, n, n);
		if(p%2==0) return m_p;
		else return matmal(m_p, m, n, n, n);
	}
}
