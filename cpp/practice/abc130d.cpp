#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

int main(){
	ll n,k,i,r=0,cnt=0,ans=0;
	cin >> n >> k;
	vector<int> a(n);
	for(i=0;i<n;++i) cin >> a.at(i);
	for(i=0;i<n;++i){
		while(cnt<k&&r<n){
			cnt += a.at(r);
			++r;
		}
		if(cnt>=k){
			--r; cnt -= a.at(r);
		}
		cnt -= a.at(i);
		ans += r - i;
	}
	cout << (n+1)*n/2 - ans << endl;
	return 0;
}
