#include <iostream>
#include <vector>
using namespace std;

int main(){
	int i,N;
	cin >> N;
	vector<int> h(N);
	vector<int> dp(N,1e9+1);
	dp.at(0) = 0;
	for(i=0;i<N;++i) cin >> h.at(i);
	for(i=0;i<N;++i){
		if(i+1<N) dp.at(i+1) = min(dp.at(i+1),dp.at(i)+abs(h.at(i+1)-h.at(i)));
		if(i+2<N) dp.at(i+2) = min(dp.at(i+2),dp.at(i)+abs(h.at(i+2)-h.at(i)));
	}
	cout << dp.at(N-1) << endl;
	return 0;
}
