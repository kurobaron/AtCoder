#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

int main(){
	ll a,b,i,t,la=0,lb=0,d,cnt,ans=0;
	vector<ll> bin_a(40);
	vector<ll> bin_b(40);
	cin >> a >> b; --a;
	t = a;
	while(t!=0){
		t /= 2;
		++la;
	}
	t = b;
	while(t!=0){
		t /= 2;
		++lb;
	}
	for(i=0;i<40;++i){
		if(i+1>la) break;
		d = pow(2,i+1);
		cnt = (d/2)*((a+1)/d);
		if((a+1)%d>0){
			cnt += max((a+1)%d-d/2, 0ll);
		}
		bin_a.at(i) = cnt;
	}
	for(i=0;i<40;++i){
		if(i+1>lb) break;
		d = pow(2,i+1);
		cnt = (d/2)*((b+1)/d);
		if((b+1)%d>0){
			cnt += max((b+1)%d-d/2, 0ll);
		}
		bin_b.at(i) = cnt;
	}
	for(i=0;i<40;++i) ans += (bin_b.at(i)-bin_a.at(i))%2==0 ? 0 : pow(2,i);
	cout << ans << endl;
	return 0;
}
