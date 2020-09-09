#include <iostream>
#include <vector>
using namespace std;

int root(int x, vector<int> &par){
	return par.at(x)==x ? x : par.at(x) = root(par.at(x),par);
}

int unite(int x, int y, vector<int> &par, vector<int> &pop){
	x = root(x,par);
	y = root(y,par);
	if(x==y) return 0;
	else{
		par.at(y) = x;
		pop.at(x) += pop.at(y);
		return pop.at(x);
	}
}

int main(){
	int n,m,i,a,b,ans=1;
	cin >> n >> m;
	vector<int> par(n);
	for(i=0;i<n;++i) par.at(i) = i;
	vector<int> pop(n,1);
	for(i=0;i<m;++i){
		cin >> a >> b;
		--a; --b;
		ans = max(ans, unite(a,b,par,pop));
	}
	cout << ans << endl;
	return 0;
}
