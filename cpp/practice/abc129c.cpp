#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main(){
	int n,m,i,a;
	cin >> n >> m;
	vector<ll> dp(n+1);
	vector<bool> broken(n+1);
	dp.at(0) = 1;
	for(i=0;i<m;++i){
		cin >> a;
		broken.at(a) = true;
	}
	dp.at(1) = broken.at(1) ? 0 : 1;
	for(i=2;i<=n;++i){
		if(broken.at(i)) dp.at(i) = 0;
		else dp.at(i) = dp.at(i-2) + dp.at(i-1);
		dp.at(i) %= MOD;
	}
	cout << dp.at(n) << endl;
	return 0;
}
