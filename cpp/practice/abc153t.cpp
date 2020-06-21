#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int h,n,i,j;
	cin >> h >> n;
	vector<int> dp(h+1, 10000001);
	dp.at(0) = 0;
	for(i=0;i<n;++i){
		int a,b;
		cin >> a >> b;
		for(j=0;j<h;++j){
			int nj = min(j+a,h);
			dp.at(nj) = min(dp.at(nj),dp.at(j)+b);
			cout << j << ": " << nj << ": " << dp.at(nj) << endl;
		}
	}
	cout << dp.at(h) << endl;
	return 0;
}
