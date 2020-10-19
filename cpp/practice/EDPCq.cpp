#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll findMax(ll a, ll b, ll k, ll l, ll r, vector<ll> &v){
	if(l>b||r<a) return -1;
	if(a<=l&&r<=b) return v.at(k);
	else return max(findMax(a,b,k*2+1,l,(l+r)/2,v),findMax(a,b,k*2+2,(l+r)/2+1,r,v));
}

void update(ll i, ll x, ll N, vector<ll> &v){
	i = N-1+i;
	v.at(i) = x;
	while(i>0){
		i = (i-1)/2;
		v.at(i) = max(v.at(i*2+1),v.at(i*2+2));
	}
}

int main(){
	ll i,N,now,n=1,ans=-1;
	cin >> N;
	vector<ll> h(N);
	vector<ll> a(N);
	while(n<N) n *= 2;
	vector<ll> dp(2*n-1);
	for(i=0;i<N;++i) cin >> h.at(i);
	for(i=0;i<N;++i) cin >> a.at(i);
	for(i=0;i<N;++i){
		now = a.at(i);
		if(h.at(i)>1) now += findMax(0,h.at(i)-2,0,0,n-1,dp);
		ans = max(ans,now);
		update(h.at(i)-1,now,n,dp);
	}		
	cout << ans << endl;
	return 0;
}
