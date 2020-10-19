#include <iostream>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

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

int main(){
	ll n,a,b,ans;
	cin >> n >> a >> b;
	CombInv ci;
	ans = ci.FastPow(2, n) - 1;
	ans -= ci.Combination(n,a);
	if(ans<0) ans += MOD;
	ans -= ci.Combination(n,b);
	if(ans<0) cout << ans+MOD << endl;
	else cout << ans << endl;
	return 0;
}
