#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main(){
	ll i,j,N,r=0,g=0,b=0,ans=0,st=1;
	string S;
	cin >> N >> S;
	for(i=0;i<N;++i){
		if(S[i]=='R') ++r;
		if(S[i]=='G') ++g;
		if(S[i]=='B') ++b;
	}
	ans = r*g*b;
	while(1){
		if(st*2>=N) break;
		for(i=0;i+st*2<N;++i){
			if(S[i]!=S[i+st]&&S[i]!=S[i+st*2]&&S[i+st]!=S[i+st*2]) --ans;
		}
		++st;
	}	
	cout << ans << endl;
	return 0;
}
