#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
	int n,i;
	ll ans=0,sup=0;
	cin >> n;
	vector<ll> a(n+1);
	vector<ll> b(n);
	for(i=0;i<n+1;++i) cin >> a.at(i);
	for(i=0;i<n;++i) cin >> b.at(i);
	for(i=0;i<n;++i){
		ans += a.at(i)>=sup ? sup : a.at(i);
		a.at(i) -= sup;
		if(a.at(i)<=0) sup = b.at(i); 
		else if(a.at(i)>=b.at(i)){
			sup = 0;
			ans += b.at(i);
		}else{
			sup = b.at(i) - a.at(i);
			ans += a.at(i);
		}
	}
	ans += a.at(n)>=sup ? sup : a.at(n);
	cout << ans << endl;
	return 0;
}
	
