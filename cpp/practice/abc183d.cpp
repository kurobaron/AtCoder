#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
	ll i,N,W,si,ti,pi;
	cin >> N >> W;
	vector<ll> t(2*1e5+1);
	for(i=0;i<N;++i){
		cin >> si >> ti >> pi;
		t.at(si) += pi;
		t.at(ti) -= pi;
	}
	if(t.at(0)>W){
		cout << "No" << endl;
		return 0;
	}
	for(i=1;i<=2*1e5;++i){
		t.at(i) += t.at(i-1);
		if(t.at(i)>W){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
