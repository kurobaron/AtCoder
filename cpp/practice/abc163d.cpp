#include <iostream>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
	ll i,N,K,first=0,last=0,ans=0;
	cin >> N >> K;
	for(i=0;i<K-1;++i){first += i; last += N-i;}
	for(i=K-1;i<N+1;++i){
		first += i;
		last += N-i;
		ans += last - first + 1;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
