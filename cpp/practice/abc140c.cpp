#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,i,ans=0;
	cin >> n;
	vector<int> b(n-1);
	for(i=0;i<n-1;++i) cin >> b.at(i);
	for(i=0;i<n-2;++i) ans += min(b.at(i),b.at(i+1));
	ans += b.at(0);
	ans += b.at(b.size()-1);
	cout << ans << endl;
	return 0;
}
