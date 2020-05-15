#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int a,b,n,ans;
	vector<int> s(1000000+1);
	cin >> n;
	for(int i=0;i<n;++i){
		cin >> a >> b;
		++s[a];
		--s[b+1];
	}
	ans = s[0];
	for(int i=1;i<1000000+1;++i){
		s[i] = s[i-1] + s[i];
		ans = max(ans, s[i]);
	}
	cout << ans << endl;
	return 0;
}
