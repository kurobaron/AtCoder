#include <iostream>
using namespace std;
using ll = long long;

int main(){
	ll i,n,a,t,cnt=0;
	cin >> n;
	a = n+1;
	t = 1;
	while(a-t>=0){
		a -= t;
		++cnt;
		++t;
	}
	cout << n - cnt + 1 << endl;
	return 0;
}
