#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

int main(){
	ll i,j,w,v,N,W;
	cin >> N >> W;
	vector<vector<ll>> dp(N+1, vector<ll>(W+1));
	for(i=1;i<=N;++i){
		cin >> w >> v;
		for(j=1;j<=W;++j){
			if(j-w<0) dp.at(i).at(j) = dp.at(i-1).at(j);
			else dp.at(i).at(j) = max(dp.at(i-1).at(j),dp.at(i-1).at(j-w)+v);
		}
	}	
	cout << dp.at(N).at(W) << endl;
	return 0;
}
