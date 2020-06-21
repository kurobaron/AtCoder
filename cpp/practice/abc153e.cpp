#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int h,n,i,j;
	cin >> h >> n;
	vector<int> a(n+1);
	vector<int> b(n+1);
	vector<vector<int>> dp(n+1, vector<int>(h+1,1000000000));
	for(i=1;i<n+1;++i) cin >> a.at(i) >> b.at(i);
	dp.at(0).at(0) = 0;
	for(i=1;i<n+1;++i){
		dp.at(i).at(0) = 0;
		for(j=0;j<h+1;++j){
			if(j-a.at(i)>=0) dp.at(i).at(j) = min(dp.at(i-1).at(j), dp.at(i).at(j-a.at(i))+b.at(i));
			else dp.at(i).at(j) = min(b.at(i),dp.at(i-1).at(j));
		}
	}
	cout << dp.at(n).at(h) << endl;
	return 0;
}
