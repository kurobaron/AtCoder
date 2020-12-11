#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
	ll i,N,ia,ic,ans=0;
	cin >> N;
	vector<ll> A(N);
	vector<ll> B(N);
	vector<ll> C(N);
	for(i=0;i<N;++i) cin >> A.at(i);
	for(i=0;i<N;++i) cin >> B.at(i);
	for(i=0;i<N;++i) cin >> C.at(i);
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	sort(C.begin(),C.end());
	for(i=0;i<N;++i){
		ia = distance(A.begin(),lower_bound(A.begin(),A.end(),B.at(i)));
		ic = distance(C.begin(),upper_bound(C.begin(),C.end(),B.at(i)));
		if(ia==0||ic==N) continue;
		ans += ia*(N-ic);
	}
	cout << ans << endl;
	return 0;
}
