#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dp(int x, vector<vector<int>> &node, vector<int> &memo){
	if(memo.at(x)>=0) return memo.at(x);
	if(node.at(x).size()==0){
		memo.at(x) = 0;
		return 0;
	}
	int tmp,l=0;
	for(auto &e : node.at(x)){
		tmp = dp(e, node, memo)+1;
		l = max(l, tmp);
	}
	memo.at(x) = l;
	return l;	
}

int main(){
	int i,N,M,x,y,ans=0;
	cin >> N >> M;
	vector<int> memo(N,-1);
	vector<vector<int>> node(N);
	for(i=0;i<M;++i){
		cin >> x >> y;
		--x; --y;
		node.at(x).push_back(y);
	}
	for(i=0;i<N;++i) ans = max(ans, dp(i, node, memo));
	cout << ans << endl;
	return 0;
}
