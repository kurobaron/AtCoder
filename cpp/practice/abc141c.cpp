#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
	ll n,k,q,i,idx;
	cin >> n >> k >> q;
	vector<int> a(n);
	for(i=0;i<q;++i){
		cin >> idx;
		++a.at(idx-1);
	}
	for(i=0;i<n;++i){
		if(a.at(i)+k-q>0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
