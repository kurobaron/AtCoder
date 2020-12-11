#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main(){
	ll i,N,ans=12;
	cin >> N;
	for(i=1;i*i<=N;++i){
		if(N%i==0){
			ans = min(ans, (ll)(to_string(N/i).length()));
		}
	}
	cout << ans << endl;
	return 0;
}	
