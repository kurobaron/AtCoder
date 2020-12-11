#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
	ll i,N,b,ans=0;
	cin >> N;
	if(N==1){
		cout << 0 << endl;
		return 0;
	}
	vector<ll> A(N);
	for(i=0;i<N;++i){
		cin >> A.at(i);
		A.at(i) -= (i+1);
	}
	sort(A.begin(),A.end());
	if(N%2==1) b = A.at(N/2);
	else b = (A.at(N/2-1)+A.at(N/2))/2;
	for(i=0;i<N;++i){
		ans += abs(A.at(i)-b);
	}
	cout << ans << endl;
	return 0;
}
