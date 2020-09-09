#include <vector>
using namespace std;

namespace atcoder{
	struct UnionFind{
		vector<long long> p;
		vector<long long> size;
		vector<long long> rank;
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
	};

	struct ModCalc{
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

		//nCrを返す
		long long Combination(long long n, long long r){
			return (Permutation(n,r)*FastPow(Factorial(r),MOD-2))%MOD;
		}
	};

	struct DpComb{
		const long long MOD = 1e9+7;
		vector<vector<long long>> c;

		//デフォルトでは最大1000C1000まで計算できるよう初期化
		DpComb(long long n=1001) : c(n, vector<long long>(n)){
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
