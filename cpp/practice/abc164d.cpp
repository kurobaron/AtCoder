#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main(){
	ll i,dmod=1,mod=0,ans=0;
	string S;
	cin >> S;
	vector<ll> m(2019); ++m.at(0);
	for(i=0;i<S.length();++i){
		if(i>0) dmod = (dmod*10)%2019;
		mod = ((ll)(S[S.length()-1-i]-'0')*dmod+mod)%2019;
		++m.at(mod);	
	}
	for(i=0;i<2019;++i){
		if(m.at(i)>1) ans += m.at(i)*(m.at(i)-1)/2;
	}
	cout << ans << endl;
	return 0;
}
