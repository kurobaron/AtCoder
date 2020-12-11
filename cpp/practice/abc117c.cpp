#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int i,N,M,ans=0;
	cin >> N >> M;
	if(N>=M){
		cout << 0 << endl;
		return 0;
	}
	vector<int> X(M);
	for(i=0;i<M;++i) cin >> X.at(i);
	sort(X.begin(),X.end());
	vector<int> delt(M-1);
	for(i=0;i<M-1;++i){
		delt.at(i) = X.at(i+1)-X.at(i);
		ans += delt.at(i);
	}
	sort(delt.begin(),delt.end());
	for(i=0;i<N-1;++i){
		ans -= delt.at(M-2-i);
	}
	cout << ans << endl;
	return 0;
}
