#include <iostream>
#include <string>
#include <bitset>
using namespace std;
const int INF = 1e9;

int main(){
	int i,j,cnt,cnt1,ans=INF;
	string N;
	cin >> N;
	for(i=0;i<(1<<N.length());++i){
		cnt = 0; cnt1 = 0;
		for(j=0;j<N.length();++j){
			if((i>>j)&1){
				cnt += (int)(N[j]-'0');
				++cnt1;
			}
		}	
		if(cnt%3==0){
			if(N.length()-cnt1<ans) ans = N.length()-cnt1;
		}
	}
	if(ans==N.length()) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}
