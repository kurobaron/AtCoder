#include <iostream>
using namespace std;
using ll = long long;

int main(){
	int n,i,cnt=0;
	ll a,m=1e9+7,ans=0;
	cin >> n;
	for(i=0;i<n;++i){
		cin >> a;
		if(a<0){
			++cnt;
			a *= -1;
		}
		m = min(m,a);
		ans += a;
	}
	if(cnt%2==0) cout << ans << endl;
	else cout << ans-2*m << endl;
	return 0;
}
