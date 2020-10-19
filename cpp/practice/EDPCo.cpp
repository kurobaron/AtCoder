#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
	ll i,j,k,N;
	cin >> N;
	vector<vector<ll>> dp(N+1, vector<ll>(1<<N));
	dp.at(0).at(0) = 1;
	vector<vector<ll>> a(N, vector<ll>(N));
	for(i=0;i<N;++i){
		for(j=0;j<N;++j){
			cin >> a.at(i).at(j);
		}
	}
	for(i=1;i<=N;++i){
		for(j=0;j<(1<<N);++j){
			if(__builtin_popcount(j)!=i) continue;
			for(k=0;k<N;++k){
				if(((j>>k)&1)&&a.at(i-1).at(k)){
					dp.at(i).at(j) = (dp.at(i).at(j)+dp.at(i-1).at(j^(1<<k)))%MOD;
				}
			}
		}
	}
	if(dp.at(N).at((1<<N)-1)<0) dp.at(N).at((1<<N)-1)+=MOD;
	cout << dp.at(N).at((1<<N)-1) << endl;
	return 0;
}
