#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
	ll n,k,pi,i,j,loc,tot,now,ans=-1e10;
	cin >> n >> k;
	vector<ll> p(n);
	vector<ll> c(n);
	for(i=0;i<n;++i){
		cin >> pi; --pi;
		p.at(i) = pi;
	}
	for(i=0;i<n;++i) cin >> c.at(i);
	for(i=0;i<n;++i){
		loc = i;
		tot = 0;
		vector<ll> s;
		while(1){
			loc = p.at(loc);
			tot += c.at(loc);
			s.push_back(c.at(loc));
			if(loc==i) break;
		}
		now = 0;
		for(j=0;j<s.size();++j){
			now += s.at(j);
			if(tot>0) ans = max(ans, now+tot*((k-j-1)/(ll)s.size()));
			else ans = max(ans, now);
			if(j+1==k) break;
		}
	}
	cout << ans << endl;
	return 0;
}
