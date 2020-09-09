#include <iostream>
using namespace std;
using ll = long long;

int main(){
	ll l,r,w,i,j,ans=2019;
	cin >> l >> r;
	w = r - l;
	if(w>2018) ans = 0;
	else for(i=0;i<w+1;++i) for(j=i+1;j<w+1;++j) ans = min(ans, ((l+i)*(l+j))%2019);
	cout << ans << endl;
	return 0;
}
