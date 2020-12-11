#include <iostream>
using namespace std;
using ll = long long;

int main(){
	ll i,N,M,ans=1;
	cin >> N >> M;
	for(i=1;i*i<=M;++i){
		if(M%i==0){
			if(i>=N) ans = max(ans,M/i);
			else if(M/i>=N) ans = max(ans,i);
			else break;
		}
	}
	cout << ans << endl;
	return 0;
}
