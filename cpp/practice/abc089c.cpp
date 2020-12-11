#include <iostream>
#include <string>
#include <map>
using namespace std;
using ll = long long;

int main(){
	ll i,j,k,N,ans=0;
	string Si;
	map<ll,ll> mp;
	cin >> N;
	for(i=0;i<N;++i){
		cin >> Si;
		switch(Si[0]){
			case 'M':
				++mp[0];
				break;
			case 'A':
				++mp[1];
				break;
			case 'R':
				++mp[2];
				break;
			case 'C':
				++mp[3];
				break;
			case 'H':
				++mp[4];
		}
	}
	for(i=0;i<5;++i){
		for(j=i+1;j<5;++j){
			for(k=j+1;k<5;++k){
				ans += mp[i]*mp[j]*mp[k];
			}
		}
	}
	cout << ans << endl;
	return 0;
}	
