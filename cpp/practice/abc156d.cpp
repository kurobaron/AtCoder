#include <iostream>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

struct ModCalc{
	const long long MOD = 1e9+7;

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

	long long Combination(long long n, long long r){
		return (Permutation(n,r)*FastPow(Factorial(r),MOD-2))%MOD;
	}
};

int main(){
	ll n,a,b,ans;
	cin >> n >> a >> b;
	ModCalc mc;
	ans = mc.FastPow(2, n) - 1;
	ans -= mc.Combination(n,a);
	if(ans<0) ans += MOD;
	ans -= mc.Combination(n,b);
	if(ans<0) cout << ans+MOD << endl;
	else cout << ans << endl;
	return 0;
}
