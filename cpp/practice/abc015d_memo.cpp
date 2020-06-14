#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int search(int n, int w, int k, vector<pair<int, int>> &v, vector<vector<vector<bool>>> &done, vector<vector<vector<int>>> &memo){
	if(n==0) return 0;
	if(done.at(n).at(w).at(k)) return memo.at(n).at(w).at(k);
	int tmp;
	if(w>=v.at(n-1).first && k>0){
		tmp = max(search(n-1, w-v.at(n-1).first, k-1, v, done, memo)+v.at(n-1).second, search(n-1, w, k, v, done, memo));
	}else tmp = search(n-1, w, k, v, done, memo);
	done.at(n).at(w).at(k) = true;
	memo.at(n).at(w).at(k) = tmp;
	return tmp;
}

int main(){
	int w,n,k,i,tmp1,tmp2;
	cin >> w >> n >> k;
	vector<pair<int, int>> v(n);
	vector<vector<vector<bool>>> done(n+1, vector<vector<bool>>(w+1, vector<bool>(k+1)));
	vector<vector<vector<int>>> memo(n+1, vector<vector<int>>(w+1, vector<int>(k+1)));
	for(i=0;i<n;++i){
		cin >> tmp1 >> tmp2;
		v.at(i) = make_pair(tmp1, tmp2);
	}
	int ans = search(n, w, k, v, done, memo);
	cout << ans << endl;
	return 0;
}
