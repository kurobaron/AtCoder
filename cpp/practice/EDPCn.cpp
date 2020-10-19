#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll devide(ll n, ll first, ll end, vector<ll> &a, vector<vector<ll>> &dp){
	if(dp.at(first).at(end)>0) return dp.at(first).at(end);
	if(first==end) return 0;
	ll i,cnt=0,minCost=1e18;
	for(i=first;i<=end-1;++i){
		cnt += a.at(i);
		minCost = min(minCost, devide(cnt,first,i,a,dp)+devide(n-cnt,i+1,end,a,dp)); 
	}
	dp.at(first).at(end) = n+minCost;
	return n+minCost;
}

int main(){
	ll i,N,cnt=0;
	cin >> N;
	vector<ll> a(N);
	vector<vector<ll>> dp(N, vector<ll>(N));
	for(i=0;i<N;++i){
		cin >> a.at(i);
		cnt += a.at(i);
	}
	cout << devide(cnt,0,N-1,a,dp) << endl;
	return 0;
}
