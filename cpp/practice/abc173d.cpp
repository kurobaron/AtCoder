#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,i;
	long long ans=0;
	cin >> n;
	vector<long long> a(n);
	for(i=0;i<n;++i) cin >> a.at(i);
	sort(a.begin(),a.end(),greater<long long>());
	if(n%2==0) for(i=0;i<(n-2)/2;++i) ans += a.at(i+1)*2;
	else{
		for(i=0;i<(n-2)/2;++i) ans += a.at(i+1)*2;
		ans += a.at((n-2)/2+1);
	}
	ans += a.at(0);
	cout << ans << endl;
	return 0;
}
