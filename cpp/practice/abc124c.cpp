#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	int i,j,c,cnt,ans=1e6;
	cin >> s;
	for(i=0;i<2;++i){
		c = i;
		cnt  = 0;
		for(j=0;j<s.length();++j){
			if((int)s[j]-48!=c) ++cnt;
			c = (c+1)%2;
		}
		ans = min(ans,cnt);
	}
	cout << ans << endl;
	return 0;
}

