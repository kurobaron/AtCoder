#include <iostream>
using namespace std;

int main(){
	int n,i,a,idx=1,ans=0;
	cin >> n;
	for(i=0;i<n;++i){
		cin >> a;
		if(a==idx){++idx; continue;}
		++ans;
	}
	if(idx==1) ans = -1;
	cout << ans << endl;
	return 0;
}	
