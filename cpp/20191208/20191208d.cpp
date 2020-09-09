#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main(){
	int n,i,j;
	ll cnt_0,cnt_1,tmp,ans=0;
	cin >> n;
	vector<ll> a(n);
	for(i=0;i<n;++i) cin >> a.at(i);
	for(i=0;i<60;++i){
		cnt_1=0; cnt_0=0;
		for(j=0;j<n;++j) if((a.at(j)>>i)&1) ++cnt_1;
		cnt_0 = n - cnt_1;
		tmp = (cnt_1*cnt_0)%MOD;
		for(j=0;j<i;++j) tmp = (tmp*2)%MOD;
		ans = (ans+tmp)%MOD;
	}
	cout << ans << endl;
	return 0;
}
