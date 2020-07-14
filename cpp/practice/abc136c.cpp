#include <iostream>
using ll = long long;
using namespace std;

int main(){
	int n,i;
	bool ans = true;
	ll h,h_max;
	cin >> n;
	h_max = 0;
	for(i=0;i<n;++i){
		cin >> h;
		if(h-h_max<-1) ans = false;
		h_max = max(h_max, h);
	}	
	if(ans) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
