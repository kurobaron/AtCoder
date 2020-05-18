#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N,Q,l,r;
	string S;
	cin >> N >> Q;
	cin >> S;
	vector<int> cnt(N);
	vector<int> ans(Q);
	for(int i=1;i<N;++i){
		if(S[i]=='C' && S[i-1]=='A') cnt[i] = cnt[i-1] + 1;
		else cnt[i] = cnt[i-1];
	}
	for(int i=0;i<Q;++i){
		cin >> l >> r;
		ans[i] = cnt[r-1] - cnt[l-1];
	}
	for(int i=0;i<Q;++i) cout << ans[i] << endl;
	return 0;
}
