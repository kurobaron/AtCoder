#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
	ll n,i,N,R=-1;
	cin >> n;
	vector<ll> a(n);
	for(i=0;i<n;++i) cin >> a.at(i);
	sort(a.begin(),a.end());
	N = *(a.end()-1);
	for(i=0;i<n;++i){
		if(min(a.at(i),N-a.at(i))>R){
			R = a.at(i);
		}else break;
	}
	cout << N << " " << R << endl;
	return 0;
}
			
