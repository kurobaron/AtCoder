#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

int main(){
	ll i,n,ans=0;
	cin >> n;
	vector<ll> counter(n+1);
	vector<ll> a(n);
	map<ll,ll> m;
	for(i=0;i<n;++i){
		cin >> a.at(i);
		++counter.at(a.at(i));
	}
	for(i=1;i<n+1;++i){
		if(counter.at(i)==0) continue;
		ans += counter.at(i)*(counter.at(i)-1)/2;
	}
	for(i=0;i<n;++i){
		if(m[a.at(i)]>0){
			cout << m[a.at(i)] << endl;
			continue;
		}
		m[a.at(i)] = ans - (counter.at(a.at(i))-1);
		cout << m[a.at(i)] << endl;
	}
	return 0;
}
