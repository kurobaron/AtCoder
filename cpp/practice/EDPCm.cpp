#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
	ll i,j,N,K;
	cin >> N >> K;
	vector<ll> a(N);
	for(i=0;i<N;++i) cin >> a.at(i);
	vector<vector<ll>> dp(N+1, vector<ll>(K+1));
	vector<vector<ll>> s(N+1, vector<ll>(K+1));
	for(i=0;i<=K;++i) s.at(0).at(i) = 1;
	for(i=1;i<=N;++i){
		for(j=0;j<=K;++j){
			if(a.at(i-1)>=j) dp.at(i).at(j) = s.at(i-1).at(j);
			else dp.at(i).at(j) = s.at(i-1).at(j) - s.at(i-1).at(j-a.at(i-1)-1);
			dp.at(i).at(j) %= MOD;
			if(j==0) s.at(i).at(j) = dp.at(i).at(j);
			else s.at(i).at(j) = (dp.at(i).at(j)+s.at(i).at(j-1))%MOD;
		}
	}
	if(dp.at(N).at(K)<0) dp.at(N).at(K) += MOD;
	cout << dp.at(N).at(K) << endl;
	return 0;
}
