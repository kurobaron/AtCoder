#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;

struct UnionFind{
	vector<int> p;
	vector<int> size;
	vector<int> rank;
	
	UnionFind(int n=0) : p(n),size(n,1),rank(n,1){
		for(int i=0;i<n;++i) p.at(i) = i;
	}

	void Unite(int x, int y){
		x = Root(x); y = Root(y);
		if(x==y) return;
		if(rank.at(x)<rank.at(y)){
			p.at(x) = y;
			size.at(y) += size.at(x);
		}else{
			p.at(y) = x;
			size.at(x) += size.at(y);
			if(rank.at(x)==rank.at(y)) ++rank.at(x);
		}
	}

	int Size(int x){
		x = Root(x);
		return size.at(x);
	}

	int Rank(int x){
		x = Root(x);
		return rank.at(x);
	}
	
	int Root(int x){
		return p.at(x)==x ? x : p.at(x) = Root(p.at(x));
	}
};	


int main(){
	int n,m,i,a,b;
	ll cnt;
	cin >> n >> m;
	stack<pair<int,int>> st;
	UnionFind uf(n);
	for(i=0;i<m;++i){
		cin >> a >> b;
		--a; --b;
		st.push({a,b});
	}
	stack<ll> ans;
	cnt = (ll)n*(ll)(n-1)/2;
	while(!st.empty()){
		ans.push(cnt);
		a = st.top().first;
		b = st.top().second;
		st.pop();
		if(uf.Root(a)!=uf.Root(b)) cnt -= uf.Size(a)*uf.Size(b);
		uf.Unite(a,b);
	}
	while(!ans.empty()){
		cout << ans.top() << endl;
		ans.pop();
	}
	return 0;
}
