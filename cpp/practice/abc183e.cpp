#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
	ll i,j,H,W,r_yoko;;
	cin >> H >> W;
	vector<vector<ll>> dp(H,vector<ll>(W));
	vector<vector<char>> mp(H,vector<char>(W));
	dp.at(0).at(0) = 1;
	for(i=0;i<H;++i){
		for(j=0;j<W;++j){
			cin >> mp.at(i).at(j);
		}
	}
	vector<ll> r_nana(H+W-1);
	vector<ll> r_tate(W);
	for(i=0;i<H;++i){
		r_yoko = 0;
		for(j=0;j<W;++j){
			if(mp.at(i).at(j)=='#'){
				r_yoko = 0;
				r_tate.at(j)=0;
				r_nana.at(j-i+H-1)=0;
				continue;
			}
			dp.at(i).at(j) += r_yoko+r_tate.at(j);
			dp.at(i).at(j) += r_nana.at(j-i+H-1);
			dp.at(i).at(j) %= MOD;
			r_tate.at(j) += dp.at(i).at(j);
			r_tate.at(j) %= MOD;
			r_yoko += dp.at(i).at(j);
			r_yoko %= MOD;	
			r_nana.at(j-i+H-1) += dp.at(i).at(j);
			r_nana.at(j-i+H-1) %= MOD;
		}
	}
	cout << dp.at(H-1).at(W-1) << endl;
	return 0;
}
