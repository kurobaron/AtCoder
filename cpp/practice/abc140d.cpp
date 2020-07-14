#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,k,i,cnt=0,cnt_out=0,cnt_in=0,ans=0;
	char s_pre,s_now;
	cin >> n >> k;
	cin >> s_pre;
	if(s_pre=='L') ++cnt_out;
	else ++cnt_in;
	for(i=0;i<n-1;++i){
		cin >> s_now;
		if(i==n-2&&s_now=='R') ++cnt_out;
		if(i==n-2&&s_now=='L') ++cnt_in;
		if(s_pre=='R'&&s_now=='L') ++cnt;
		else if(s_pre==s_now) ++ans;
		s_pre = s_now;
	}
	if(cnt_in==2) --cnt;
	if(k<=cnt) ans += k*2;
	else if(cnt_out==1) ans += cnt*2;
	else ans += cnt*2 + 1;
	cout << ans << endl;
	return 0;
}
