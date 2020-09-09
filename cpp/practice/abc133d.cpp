#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
	int n,i;
	ll pre,cnt1=0,cnt2=0;
	cin >> n;
	vector<ll> a(n);
	for(i=0;i<n;++i){
		cin >> a.at(i);
		cnt1 += a.at(i);
		if(i%2==1) cnt2 += 2*a.at(i);
	}
	pre = cnt1 - cnt2;
	cout << pre << " ";
	for(i=0;i<n-1;++i){
		pre = a.at(i)*2-pre;
		cout << pre << " ";
	}
	return 0;
}
