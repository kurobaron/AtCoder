#include <iostream>
using namespace std;

int main(){
	long long i,n,ans,tmp;
	cin >> n;
	ans = n-1;
	for(i=2;i*i<=n;++i){
		if(n%i!=0) continue;
		ans = n/i+i-2;
	}
	cout << ans << endl;
	return 0;
}	
		
