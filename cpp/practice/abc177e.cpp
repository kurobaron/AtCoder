#include <iostream>
#include <vector>
#include <map>
using namespace std;

int gcd(int a, int b){
	if(a>b) swap(a,b);
	while(b%a!=0){
		int tmp = b%a;
		b = a;
		a = tmp;
	}
	return a;
}

int main(){
	int n,i,j,jud,t;
	cin >> n;
	vector<int> a(n);
	for(i=0;i<n;++i) cin >> a.at(i);
	vector<int> e(1e6+1);
	vector<int> d(1e6+1);
	for(i=2;i*i<=1e6;++i){
		if(e.at(i)==1) continue;
		for(j=i;j<=1e6;j+=i){
			e.at(j) = 1;
			d.at(j) = i;
		}
	}
	jud = a.at(0);
	for(i=1;i<n;++i) jud = gcd(jud,a.at(i));
	if(jud>1) cout << "not coprime" << endl;
	else{
		map<int,pair<int,int>> mp;
		for(i=0;i<n;++i){
			t = a.at(i);
			while(t!=1){
				if(e.at(t)==0) d.at(t) = t;
				if(mp[d.at(t)].first!=i&&mp[d.at(t)].second==1){
					cout << "setwise coprime" << endl;
					return 0;
				}
				mp[d.at(t)] = {i,1};
				t /= d.at(t);
			}
		}
		cout << "pairwise coprime" << endl;
	}
	return 0;
}
