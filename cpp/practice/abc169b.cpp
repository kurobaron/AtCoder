#include <iostream>
using namespace std;

int main(){
	int n,i;
	long long tmp,ans=1,flg=0;
	cin >> n;
	for(i=0;i<n;++i){
		cin >> tmp;
		if(tmp==0){
			ans = 0;
			break;
		}
		if((long long)1000000000000000000/ans<(long long)tmp) flg = 1;
		if(flg==1) continue;
		ans *= tmp;
	}
	if(flg==1 && ans!=0) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}
