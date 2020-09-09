#include <iostream>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

ll powMod(ll a, ll p, ll mod){
	if(p==1) return a;
	if(p%2) return (a*powMod(a, p-1, mod))%mod;
	ll t = powMod(a, p/2, mod);
	return (t*t)%mod;
}	

int main(){
	ll x,y,m,n,k,pre=1,cnt=1;
	cin >> x >> y;
	if((2*x-y)%3!=0||(2*y-x)%3!=0||2*x-y<0||2*y-x<0){
		cout << 0 << endl;
	}else{
		m = (2*x-y)/3;
		n = (2*y-x)/3;
		k = min(m,n);
		while(cnt!=m+n){
			++cnt;
			pre = (pre*cnt)%MOD;
		}		
		cnt = 1;
		while(cnt<k){
			++cnt;
			pre = (pre*powMod(cnt,MOD-2,MOD))%MOD;
		}
		cnt = 1;
		while(cnt<m+n-k){
			++cnt;
			pre = (pre*powMod(cnt,MOD-2,MOD))%MOD;
		}
		cout << pre << endl;
	}
	return 0;
}
