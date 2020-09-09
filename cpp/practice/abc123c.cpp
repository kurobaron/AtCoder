#include <iostream>
using namespace std;
using ll = long long;

int main(){
	ll n,i,c,bn=1e15+1;
	cin >> n;
	for(i=0;i<5;++i){
		cin >> c;
		bn = min(bn,c);
	}
	if(n%bn==0) cout << n/bn+4 << endl;
	else cout << n/bn+5 << endl;
	return 0;
}
