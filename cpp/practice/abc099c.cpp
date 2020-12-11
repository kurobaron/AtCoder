#include <iostream>
#include <vector>
using namespace std;

int dp(int n, vector<int> coin, vector<int> &memo){
	if(n<0) return 1e6;
	if(memo.at(n)!=-1) return memo.at(n);
	int cand = 1e6;
	for(auto e : coin){
		cand = min(cand, dp(n-e,coin,memo)+1);
	}
	memo.at(n) = cand;
	return cand;
}

int main(){
	int N;
	cin >> N;
	vector<int> coin {1,6,9,36,81,216,729,1296,6561,7776,46656,59049};
	vector<int> memo(N+1,-1);
	memo.at(0) = 0;
	cout << dp(N,coin,memo) << endl;
	return 0;
}
