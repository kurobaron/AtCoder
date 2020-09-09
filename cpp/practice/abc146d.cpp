#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main(){
	int n,i,a,b,node,used,cnt,chi,cn=0;
	cin >> n;
	vector<vector<int>> g(n);
	vector<pair<int,int>> o(n-1);
	vector<int> p(n); p.at(0)=-1;
	map<pair<int,int>, int> c; c[(make_pair(-1,0))]=0;
	for(i=0;i<n-1;++i){
		cin >> a >> b;
		--a; --b;
		o.at(i) = make_pair(a,b);
		g.at(a).push_back(b);
		g.at(b).push_back(a);
	}
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		node = q.front(); q.pop();
		used = c.at(make_pair(min(node,p.at(node)),max(node,p.at(node))));
		cnt = 1;
		for(i=0;i<g.at(node).size();++i){
			chi = g.at(node).at(i);
			if(chi==p.at(node)) continue;
			p.at(chi) = node;
			q.push(chi);
			if(cnt==used) ++cnt;
			c[make_pair(min(node,chi),max(node,chi))] = cnt;
			++cnt;
			cn = max(cn, c.at(make_pair(min(node,chi),max(node,chi))));
		}
	}
	cout << cn << endl;
	for(i=0;i<n-1;++i) cout << c.at(o.at(i)) << endl;
	return 0;
}	
