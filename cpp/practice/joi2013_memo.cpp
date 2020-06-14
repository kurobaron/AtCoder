#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int dp(int n, int c, vector<vector<int>> &li, vector<vector<bool>> &done, vector<vector<int>> &memo){
	if(done.at(n).at(c)) return memo.at(n).at(c);
	if(n==0) return 0;
	int tmp=0;
	for(int i=0;i<li.at(n-1).size();++i){
		int pt = abs(li.at(n).at(c)-li.at(n-1).at(i))+dp(n-1, i, li, done, memo);
		if(tmp<pt) tmp = pt;
	}
	done.at(n).at(c) = true;
	memo.at(n).at(c) = tmp;
	return tmp;
}

int main (){
	int d,n,i,j,t_low,t_high,pt,tmp;
	cin >> d >> n;
	vector<vector<int>> li(d, vector<int>());
	vector<vector<int>> memo(d, vector<int>());
	vector<vector<bool>> done(d, vector<bool>());
	vector<int> t(d);
	for(i=0;i<d;++i) cin >> t.at(i);
	for(i=0;i<n;++i){
		cin >> t_low >> t_high >> pt;
		for(j=0;j<d;++j){
			if(t_low<=t.at(j) && t.at(j)<=t_high){
				li.at(j).push_back(pt);
				memo.at(j).push_back(0);
				done.at(j).push_back(false);
			}
		}
	}
	int ans = 0;
	for(i=0;i<li.at(d-1).size();++i){
		int tmp = dp(d-1, i, li, done, memo);
		if(ans<tmp) ans = tmp;
	}
	cout << ans << endl;
	return 0;
}
