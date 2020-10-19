#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
	ll i,j,k,N;
	cin >> N;
	vector<ll> a(N);
	for(i=0;i<N;++i) cin >> a.at(i);
	vector<vector<vector<ll>>> dp(N,vector<vector<ll>>(N,vector<ll>(2)));
	for(i=0;i<N;++i){
		dp.at(0).at(i).at(0) = a.at(i);
		dp.at(0).at(i).at(1) = -a.at(i);
	}
	for(i=1;i<N;++i){
		for(j=0;j<N-i;++j){
			for(k=0;k<2;++k){
				if(k==0) dp.at(i).at(j).at(k) = max(a.at(j)+dp.at(i-1).at(j+1).at(1),a.at(j+i)+dp.at(i-1).at(j).at(1));
				else dp.at(i).at(j).at(k) = min(-a.at(j)+dp.at(i-1).at(j+1).at(0),-a.at(j+i)+dp.at(i-1).at(j).at(0));
			}
		}
	}
	cout << dp.at(N-1).at(0).at(0) << endl;
	return 0;
}
