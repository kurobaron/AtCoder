#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
	ll i,n,ans=0;
	cin >> n;
	vector<pair<ll,ll>> s1(1e5+1);
	vector<pair<ll,ll>> s2(1e5+1);
	for(i=0;i<1e5+1;++i){
		s1.at(i).second = i;
		s2.at(i).second = i;
	}
	for(i=0;i<n;++i){
		if(i%2==0){
			ll tmp;
			cin >> tmp;
			++s1.at(tmp).first;
		}else{
			ll tmp;
			cin >> tmp;
			++s2.at(tmp).first;
		}
	}
	sort(s1.rbegin(),s1.rend());
	sort(s2.rbegin(),s2.rend());
	if(s1.at(0).second!=s2.at(0).second) ans = n/2-s1.at(0).first+n/2-s2.at(0).first;
	else ans = min(n/2-s1.at(0).first+n/2-s2.at(1).first,n/2-s1.at(1).first+n/2-s2.at(0).first);
	cout << ans << endl;
	return 0;
}

