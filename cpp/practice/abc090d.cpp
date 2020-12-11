#include <iostream>
using namespace std;
using ll = long long;

int main(){
	ll i,N,K,d,ans=0;
	cin >> N >> K;
	for(i=1;i<=N;++i){
		if(i>=K) ans += (N-i);
		if(i>K){
			d = i-K;
			ans += d*((N-i+1)/i);
			ans += max((ll)0,(N-i+1)%i-K);
		}
	}
	cout << ans << endl;
	return 0;
}
