#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

int main(){
	ll i,j,N,K,l,r,tmp;
	cin >> N >> K;
	vector<pair<ll,ll>> vp(K);
	for(i=0;i<K;++i){
		cin >> l >> r;
		vp.at(i) = {l,r};
	}	
	vector<ll> dp(N);
	vector<ll> s(N);
	dp.at(0) = 1;
	s.at(0) = 1;
	for(i=1;i<N;++i){
		for(j=0;j<K;++j){
			l = vp.at(j).first;
			r = vp.at(j).second;
			tmp = l;
			l = i-r;
			r = i-tmp;
			if(l<=0) dp.at(i) += r<0 ? 0:s.at(r);
			else dp.at(i) += s.at(r)-s.at(l-1);
			dp.at(i) %= MOD;
			s.at(i) = (s.at(i-1)+dp.at(i))%MOD;
		}
	}	
	if(dp.at(N-1)<0) dp.at(N-1)+=MOD;
	cout << dp.at(N-1) << endl;
	return 0;
}
