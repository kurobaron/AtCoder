#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
	ll i,j,k,D;
	string K;
	cin >> K;
	cin >> D;
	vector<vector<vector<ll>>> dp(K.length()+1,vector<vector<ll>>(2,vector<ll>(D)));
	dp.at(0).at(0).at(0) = 1;
	for(i=0;i<K.length();++i){
		for(j=0;j<D;++j){
			for(k=0;k<10;++k){
				dp.at(i+1).at(1).at((j+k)%D) = (dp.at(i+1).at(1).at((j+k)%D)+dp.at(i).at(1).at(j))%MOD;
			}
			for(k=0;k<(ll)(K[i]-'0');++k){
				dp.at(i+1).at(1).at((j+k)%D) = (dp.at(i+1).at(1).at((j+k)%D)+dp.at(i).at(0).at(j))%MOD;
			}
			dp.at(i+1).at(0).at((j+(ll)(K[i]-'0'))%D) = (dp.at(i+1).at(0).at((j+(ll)(K[i]-'0'))%D)+dp.at(i).at(0).at(j))%MOD;
		}
	}
	cout << (dp.at(K.length()).at(1).at(0)+dp.at(K.length()).at(0).at(0)+MOD-1)%MOD << endl;
	return 0;
}
