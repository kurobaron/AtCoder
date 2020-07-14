#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int n,q,i,idx,a,b;
	cin >> n >> q;
	vector<int> p(n);
	vector<int> par(n);
	vector<bool> done(n);
	vector<vector<int>> node(n);
	queue<int> qu;
	for(i=0;i<n-1;++i){
		cin >> a >> b;
		--a; --b;
		node.at(a).push_back(b);
		node.at(b).push_back(a);
	}
	for(i=0;i<q;++i){
		cin >> a >> b;
		--a;
		p.at(a) += b;
	}
	qu.push(0);
	while(!qu.empty()){
		idx = qu.front(); qu.pop();
		done.at(idx) = true;
		if(idx!=0) p.at(idx) += p.at(par.at(idx));
		for(auto e : node.at(idx)){
			if(!done.at(e)){
				par.at(e) = idx;
				qu.push(e);
			}
		}
	}
	for(i=0;i<n;++i) cout << p.at(i) << " ";
	cout << endl;
	return 0;
}
