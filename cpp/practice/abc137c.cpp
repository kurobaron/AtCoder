#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
using ll = long long;

int main(){
	ll n,i,ans=0;
	string s;
	map<string, ll> m;
	cin >> n;
	for(i=0;i<n;++i){
		cin >> s;
		sort(s.begin(),s.end());
		++m[s];
	}
	for(auto e : m) ans += e.second*(e.second-1)/2;
	cout << ans << endl;
	return 0;
}
