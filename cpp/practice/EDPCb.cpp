#include <iostream>
#include <vector>
using namespace std;

int main(){
	int i,j,N,K;
	cin >> N >> K;
	vector<int> h(N);
	vector<int> dp(N,1e9+1);
	dp.at(0) = 0;
	for(i=0;i<N;++i) cin >> h.at(i);
	for(i=0;i<N;++i){
		for(j=1;j<=K;++j){
			if(i+j<N){
				dp.at(i+j) = min(dp.at(i+j),dp.at(i)+abs(h.at(i+j)-h.at(i)));
			}
		}
	}
	cout << dp.at(N-1) << endl;
	return 0;
}
