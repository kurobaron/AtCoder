#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
using ll = long long;

int main(){
	int x,y,z,i,ia=0,ib=0,ic=0,cnt=0;
	ll k;
	cin >> x >> y >> z >> k;
	vector<ll> a(x);
	vector<ll> b(y);
	vector<ll> c(z);
	for(i=0;i<x;++i) cin >> a.at(i);	
	for(i=0;i<y;++i) cin >> b.at(i);
	for(i=0;i<z;++i) cin >> c.at(i);
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	sort(c.rbegin(), c.rend());
	priority_queue<tuple<ll,int,int,int>> q;
	map<tuple<int,int,int>,int> mp;
	q.push({a.at(ia)+b.at(ib)+c.at(ic),ia,ib,ic});
	++mp[{ia,ib,ic}];
	while(1){
		cout << get<0>(q.top()) << endl;
		ia = get<1>(q.top()); ib = get<2>(q.top()); ic = get<3>(q.top());
		q.pop(); ++cnt;
		if(cnt==k) return 0;
		if(ia<x-1){
			if(mp[{ia+1,ib,ic}]==0){
				q.push({a.at(ia+1)+b.at(ib)+c.at(ic),ia+1,ib,ic});
				++mp[{ia+1,ib,ic}];
			}
		}
		if(ib<y-1){
			if(mp[{ia,ib+1,ic}]==0){
				q.push({a.at(ia)+b.at(ib+1)+c.at(ic),ia,ib+1,ic});
				++mp[{ia,ib+1,ic}];
			}
		}
		if(ic<z-1){
			if(mp[{ia,ib,ic+1}]==0){
				q.push({a.at(ia)+b.at(ib)+c.at(ic+1),ia,ib,ic+1});
				++mp[{ia,ib,ic+1}];
			}
		}
	}
}
