#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int i,K,N,ans=1e9+1;
	cin >> N >> K;
	vector<int> h(N);
	for(i=0;i<N;++i) cin >> h.at(i);
	sort(h.rbegin(),h.rend());
	for(i=0;i+K-1<N;++i){
		ans = min(ans, h.at(i)-h.at(i+K-1));
	}
	cout << ans << endl;
	return 0;
}
