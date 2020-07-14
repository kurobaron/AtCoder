#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int h,n,i,j,a,b;
	cin >> h >> n;
	vector<int> dp(h+1,1000000000);
	dp.at(0) = 0;
	for(i=0;i<n;++i){
		cin >> a >> b;
		for(j=0;j<h+1;++j){
			if(j-a<0) dp.at(j) = min(dp.at(j), b);
			else dp.at(j) = min(dp.at(j-a)+b,dp.at(j));
		}
	}
	cout << dp.at(h) << endl;
	return 0;
}
