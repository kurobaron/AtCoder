#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

int root(int x, vector<int> &v){
	return v[x]==x ? x : v[x]=root(v[x], v);
}

void unit(int x, int y, vector<int> &v, vector<int> &r){
	x = root(x, v);
	y = root(y, v);
	if(x==y) return;
	if(r[x]<r[y]) v[x] = y;
	else{
		v[y] = x;
		if(r[x]==r[y]) ++r[x];
	}
	return;
}

int main(){
	int N,K,L,i,t1,t2;
	cin >> N >> K >> L;
	vector<int> p1(N);
	vector<int> p2(N);
	vector<int> r1(N, 1);
	vector<int> r2(N, 1);
	map<tuple<int, int>, int> mp;
	for(i=0;i<N;++i){
		p1[i] = i;
		p2[i] = i;
	}
	for(i=0;i<K;++i){
		cin >> t1 >> t2;
		--t1; --t2;
		unit(t1, t2, p1, r1);
	}
	for(i=0;i<L;++i){
		cin >> t1 >> t2;
		--t1; --t2;
		unit(t1, t2, p2, r2);
	}
	for(i=0;i<N;++i){
		tuple<int, int> t = make_tuple(root(i, p1), root(i, p2));
		++mp[t];
	}
	for(i=0;i<N;++i){
		tuple<int, int> t = make_tuple(root(i, p1), root(i, p2));
		cout << mp[t] << " ";
		if(i==N-1) cout << endl;
	}
		
	return 0;
}
