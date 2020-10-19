#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1e11+1;

int main(){
	ll i,j,N,W,w,v;
	cin >> N >> W;
	vector<vector<ll>> dp(N+1, vector<ll>(1e5+1, INF));
	for(i=0;i<=N;++i) dp.at(i).at(0) = 0;
	for(i=1;i<=N;++i){
		cin >> w >> v;
		for(j=0;j<=1e5;++j){
			if(j-v<0||dp.at(i-1).at(j-v)==INF) dp.at(i).at(j) = dp.at(i-1).at(j);
			else dp.at(i).at(j) = min(dp.at(i-1).at(j), dp.at(i-1).at(j-v)+w);
		}
	}
	for(i=1e5;i>=0;--i){
		if(dp.at(N).at(i)<=W){
			cout << i << endl;
			return 0;
		}
	}
}
