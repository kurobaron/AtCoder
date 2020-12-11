#include <iostream>
using namespace std;
using ll = long long;

int main(){
	ll N,M;
	cin >> N >> M;
	if(N==2||M==2) cout << 0;
	else if(N==1||M==1){
		if(max(N,M)==1) cout << 1;
		else cout << max(N,M)-2;
	}else cout << (N-2)*(M-2);
	cout << endl;
	return 0;
}
