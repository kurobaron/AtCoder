#include <iostream>
using namespace std;

int gcd(int a, int b){
	if(a>b) swap(a,b);
	while(b%a!=0){
		int t = b%a;
		b = a;
		a = t;
	}
	return a;
}

int main(){
	int i,j,k,K,tmp,ans=0;
	cin >> K;
	for(i=1;i<=K;++i){
		for(j=1;j<=K;++j){
			for(k=1;k<=K;++k){
				tmp = gcd(i,j);
				ans += gcd(tmp,k);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
