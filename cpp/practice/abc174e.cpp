#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

bool CanSplit(ll t, ll s, vector<ll> &a){
	ll cnt = 0;
	for(ll i=0;i<a.size();++i){
		if(a.at(i)<=s) continue;
		cnt += a.at(i)%s==0 ? a.at(i)/s-1 : a.at(i)/s;
		if(cnt>t) return false;
	}
	return true;
}
int main(){
	ll i,N,K,l,r;
	cin >> N >> K;
	vector<ll> A(N);
	for(i=0;i<N;++i) cin >> A.at(i);
	l = 0; r = 1e9;
	while(r-l!=1){
		if(CanSplit(K,(l+r)/2, A)) r = (l+r)/2;
		else l = (l+r)/2;
	}
	cout << r << endl;
	return 0;
}
