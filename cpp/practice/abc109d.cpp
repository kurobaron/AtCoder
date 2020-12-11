#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll GCD(ll a, ll b){
	while(b%a!=0){
		ll tmp = b%a;
		b = a;
		a = tmp;
	}
	return a;
}

int main(){
	ll i,N,X,dt;
	cin >> N >> X;
	vector<ll> x(N+1);
	for(i=0;i<N;++i) cin >> x.at(i);
	x.at(N) = X;
	sort(x.begin(),x.end());
	dt = x.at(1)-x.at(0);
	for(i=0;i<N;++i){
		dt = GCD(dt,x.at(i+1)-x.at(i));
	}
	cout << dt << endl;
	return 0;
}
