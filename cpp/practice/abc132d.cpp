#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main(){
	ll N,K,i,j,rDiv,nDiv,numDiv,rIns,nIns,numIns;	
	cin >> N >> K;
	vector<vector<ll>> comb(N+1, vector<ll>(N+1));
	comb.at(0).at(0) = 1;
	for(i=1;i<N+1;++i){
		comb.at(i).at(0) = 1;
		for(j=1;j<i;++j){
			comb.at(i).at(j) = comb.at(i-1).at(j-1)+comb.at(i-1).at(j);
			comb.at(i).at(j) %= MOD;
		}
		comb.at(i).at(i) = 1;
	}
	for(i=1;i<K+1;++i){
		rDiv = i-1;
		nDiv = K-1;
		numDiv = comb.at(nDiv).at(rDiv);
		rIns = i;
		nIns = N-K+1;
		if(rIns>nIns) numIns = 0;
		else numIns = comb.at(nIns).at(rIns);
		cout << (numDiv*numIns)%MOD << endl;
	}
	return 0;
}
