#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
	ll i,j,H,W;
	cin >> H >> W;
	vector<vector<char>> mp(H,vector<char>(W));
	vector<vector<ll>> dp(H,vector<ll>(W));
	for(i=0;i<H;++i){
		for(j=0;j<W;++j){
			cin >> mp.at(i).at(j);
		}
	}
	dp.at(0).at(0) = 1;
	for(i=0;i<H;++i){
		for(j=0;j<W;++j){
			if(i+1<H&&mp.at(i+1).at(j)=='.'){
				dp.at(i+1).at(j) += dp.at(i).at(j);
				dp.at(i+1).at(j) %= MOD;
			}
			if(j+1<W&&mp.at(i).at(j+1)=='.'){
				dp.at(i).at(j+1) += dp.at(i).at(j);
				dp.at(i).at(j+1) %= MOD;
			}
		}
	}
	cout << dp.at(H-1).at(W-1) << endl;
	return 0;
}
