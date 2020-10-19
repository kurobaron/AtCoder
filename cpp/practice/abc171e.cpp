#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
using ll = long long;

int main(){
	ll i,N,s=0;
	cin >> N;
	vector<ll> a(N);
	for(i=0;i<N;++i){
		cin >> a.at(i);
		s ^= a.at(i);
	}
	for(i=0;i<N;++i) cout << (ll)(s^a.at(i)) << " ";
	cout << endl;
	return 0;
}
