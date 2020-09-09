#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
	ll i,j,n,m,v,b,c,tmp,cnt,i_pre=0,idx=0,nn=0,ans=0;
	cin >> n >> m;
	vector<ll> a(n);
	vector<pair<ll,ll>> li(m);
	vector<ll> d(n);
	for(i=0;i<n;++i){
		cin >> tmp;
		ans += tmp;
		a.at(i) = tmp;
	}
	sort(a.begin(), a.end());
	for(i=0;i<m;++i){
		cin >> b >> c;
		li.at(i) = make_pair(c, b);
	}
	sort(li.rbegin(),li.rend());
	while(1){
		v = li.at(idx).first;
		cnt = li.at(idx).second;
		for(i=i_pre;i<min(n,i_pre+cnt);++i) d.at(i) = v;
		i_pre = i;
		if(i_pre==n||idx==m-1) break;
		++idx;
	}
	for(i=0;i<n;++i){
		if(a.at(i)<d.at(i)) ans -= a.at(i)-d.at(i);
		else break;
	}
	cout << ans << endl;
	return 0;
}
