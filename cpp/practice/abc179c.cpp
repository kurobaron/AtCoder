#include <iostream>
using namespace std;
using ll = long long;

int main(){
	ll i,j,N,ans=0;
	cin >> N;
	for(i=1;i<=N;++i){
		for(j=1;i*j<N;++j){
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
