#include <iostream>
using namespace std;
using ll = long long;

int main(){
	ll i,N,x,y,maxw=-2e9,maxz=-2e9,minw=2e9,minz=2e9;
	cin >> N;
	for(i=0;i<N;++i){
		cin >> x >> y;
		maxw = max(maxw,x+y);
		minw = min(minw,x+y);
		maxz = max(maxz,x-y);
		minz = min(minz,x-y);
	}
	cout << max(maxw-minw,maxz-minz) << endl;
	return 0;
}
