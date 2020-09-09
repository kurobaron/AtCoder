#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
	int i,ans,ia,ib=0;
	ll n,m,k,A,B;
	cin >> n >> m >> k;
	vector<ll> a(n+1);
	vector<ll> b(m+1);
	for(i=1;i<n+1;++i){
		cin >> A;
		a.at(i) = a.at(i-1)+A;
	}
	for(i=1;i<m+1;++i){
		cin >> B;
		b.at(i) = b.at(i-1)+B;
	}
	for(i=n;i>=0;--i){
		if(a.at(i)<=k){
			ans = i;
			ia = i;
			break;
		}
	}
	while(ia>=0){
		while(a.at(ia)+b.at(ib)<=k){
			++ib;
			if(ib>m) break;
		}
		--ib;
		ans = max(ans, ia+ib);	
		--ia;
	}
	cout << ans << endl;
	return 0;
}
