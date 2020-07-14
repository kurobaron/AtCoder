#include <iostream>
using namespace std;
using ll = long long;

int main(){
	int n,i,cnt=0,ans=0;
	ll h,h_pre=0;
	cin >> n;
	for(i=0;i<n;++i){
		cin >> h;
		if(h<=h_pre) ++cnt;
		else{
			ans = max(ans,cnt);
			cnt = 0;
		}
		h_pre = h;
	}
	ans = max(ans, cnt);
	cout << ans << endl;
	return 0;
}
