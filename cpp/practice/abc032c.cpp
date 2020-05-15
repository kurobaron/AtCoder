#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int N,K,ans=0,j=0,flg=0;
	long long pro=1;
	cin >> N >> K;
	vector<int> S(N);
	for(int i=0;i<N;++i){
		cin >> S[i];
		if(S[i]==0) flg = 1;
	}
	if(flg==1){
	       	cout << N << endl; 
		return 0;
	}
	for(int i=0;i<N;++i){
		while(j<N && pro*S[j]<=K){
			pro *= S[j];
			++j;
		}
		ans = max(ans,j-i);
		if(j==i) ++j;
		else pro /= S[i];
	}
	cout << ans << endl;
	return 0;
}
