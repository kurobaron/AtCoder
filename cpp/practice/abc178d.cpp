#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
	ll S,i,j;
	cin >> S;
	vector<ll> v(S+1);
	v.at(0) = 1;
	for(i=1;i<S+1;++i){
		for(j=0;j<=i-3;++j){
			v.at(i) += v.at(j);
			v.at(i) %= MOD;
		}
	}
	cout << v.at(S) << endl;
	return 0;
}
