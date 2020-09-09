#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
	int n,i,flg=0;
	ll a,b,now;
	cin >> n;
	vector<ll> t;
	map<ll, ll> m;
	for(i=0;i<n;++i){
		cin >> a >> b;
		if(m.find(b)==m.end()) t.push_back(b);
		m[b] += a;
	}
	sort(t.begin(),t.end());
	now = 0;
	for(auto e : t){
		now += m[e];
		if(now>e){
			flg = 1;
			break;
		}
	}
	if(flg) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}
