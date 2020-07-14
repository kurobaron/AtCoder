#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,i,j,ans=0;
	cin >> n;
	vector<int> l(n);
	for(i=0;i<n;++i) cin >> l.at(i);
	sort(l.begin(),l.end());
	for(i=0;i<n-1;++i){
		for(j=i+1;j<n;++j){
			auto iter = lower_bound(l.begin(),l.end(),l.at(i)+l.at(j));
			size_t dist = distance(l.begin(),iter);
			ans += dist - j - 1;
		}
	}
	cout << ans << endl;
	return 0;
}
