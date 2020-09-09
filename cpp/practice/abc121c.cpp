#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
	ll n,m,i,a,b,ans=0;
	cin >> n >> m;
	vector<pair<ll, ll>> s(n);
	for(i=0;i<n;++i){
		cin >> a >> b;
		s.at(i) = {a,b};
	}
	sort(s.begin(),s.end());
	for(i=0;i<n;++i){
		if(s.at(i).second<m){
			m -= s.at(i).second;
			ans += s.at(i).first*s.at(i).second;
		}else{
			ans += s.at(i).first*m;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
