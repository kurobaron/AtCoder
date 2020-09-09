#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
	ll n,i,j,ans=0;
	cin >> n;
	for(i=1;i<n+1;++i){
		for(j=1;i*j<n+1;++j){
			ans += i*j;
		}
	}
	cout << ans << endl;
	return 0;
}
