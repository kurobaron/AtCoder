#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
	ll n,i,num,have=0,mon=1000;
	cin >> n;
	vector<ll> pr(n);
	vector<ll> di(n);
	for(i=0;i<n;++i) cin >> pr.at(i);
	for(i=0;i<n-1;++i){
		if(pr.at(i)<pr.at(i+1)&&!have){
			num = mon/pr.at(i);
			mon %= pr.at(i);
			have += num;
			di.at(i) = mon;
			continue;
		}
		if(pr.at(i)<pr.at(i+1)&&have){
			di.at(i) = mon;
			continue;
		}
		if(pr.at(i)>pr.at(i+1)&&!have){
			di.at(i) = mon;
			continue;
		}
		if(pr.at(i)>pr.at(i+1)&&have){
			mon += have*pr.at(i);
			have = 0;
			di.at(i) = mon;
			continue;
		}
		if(pr.at(i)==pr.at(i+1)){
			di.at(i) = mon;
			continue;
		}
	}
	di.at(n-1) = mon + have*pr.at(n-1);
	sort(di.rbegin(),di.rend());
	cout << di.at(0) << endl;
	return 0;
}
