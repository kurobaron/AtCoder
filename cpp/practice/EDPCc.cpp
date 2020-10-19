#include <iostream>
#include <vector>
using namespace std;

int main(){
	int i,j,h,N,ans=0;
	cin >> N;
	vector<vector<int>> dp(N, vector<int>(3));
	for(i=0;i<3;++i) cin >> dp.at(0).at(i);
	for(i=1;i<N;++i){
		for(j=0;j<3;++j){
			cin >> h;
			dp.at(i).at(j) = max(h+dp.at(i-1).at((j+1)%3), h+dp.at(i-1).at((j+2)%3));
		}
	}
	ans = max(dp.at(N-1).at(0),dp.at(N-1).at(1));
	ans = max(ans, dp.at(N-1).at(2));
	cout << ans << endl;
	return 0;
}
