#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main(){
	int n,i,v,u,w;
	cin >> n;
	queue<tuple<int,int,int>> q;
	vector<int> a(n,-1);
	tuple<int,int,int> t;
	cin >> v >> u >> w;
	--v; --u;
	if(w%2==0){a.at(v) = 0; a.at(u) = 0;}
	else{a.at(v) = 0; a.at(u) = 1;}
	for(i=1;i<n-1;++i){
		cin >> v >> u >> w;
		--v; --u;
		if(a.at(v)==-1&&a.at(u)==-1){
			q.push(make_tuple(v, u, w));	
			continue;
		}
		if(a.at(v)!=-1){
			if(w%2==0) a.at(u) = a.at(v);
			else a.at(u) = (a.at(v)+1)%2;
		}
		if(a.at(u)!=-1){
			if(w%2==0) a.at(v) = a.at(u);
			else a.at(v) = (a.at(u)+1)%2;
		}
	}
	while(!q.empty()){
		t = q.front(); q.pop();
		v = get<0>(t); u = get<1>(t); w = get<2>(t);
		if(a.at(v)==-1&&a.at(u)==-1){
			q.push(t);	
			continue;
		}
		if(a.at(v)!=-1){
			if(w%2==0) a.at(u) = a.at(v);
			else a.at(u) = (a.at(v)+1)%2;
		}
		if(a.at(u)!=-1){
			if(w%2==0) a.at(v) = a.at(u);
			else a.at(v) = (a.at(u)+1)%2;
		}
	}
	for(i=0;i<n;++i) cout << a.at(i) << endl;
	return 0;
}
