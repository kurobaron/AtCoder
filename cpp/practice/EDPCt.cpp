#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
	ll i,j,N;
	string s;
	cin >> N;
	cin >> s;
	vector<vector<ll>> dp(N,vector<ll>(N));
	for(i=0;i<N;++i) dp.at(0).at(i) = 1;
	vector<ll> cs_pre(N);
	for(i=0;i<N;++i) cs_pre.at(i) = i+1;
	for(i=0;i<N-1;++i){
		vector<ll> cs(N-(i+1));
		for(j=0;j<N-(i+1);++j){
			if(s[i]=='<'){
				dp.at(i+1).at(j) = (cs_pre.at(N-(i+1))-cs_pre.at(j))%MOD;
			}else{
				dp.at(i+1).at(j) = cs_pre.at(j);
			}
			cs.at(j) = dp.at(i+1).at(j)%MOD;
			if(j>0) cs.at(j) = (cs.at(j)+cs.at(j-1))%MOD;
		}
		cs_pre = cs;
	}
	if(dp.at(N-1).at(0)<0) dp.at(N-1).at(0) += MOD;
	cout << dp.at(N-1).at(0) << endl;
	return 0;
}

					
