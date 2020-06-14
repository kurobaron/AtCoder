#include <iostream>
#include <vector>
using namespace std;

bool isMakable(int i, int n, vector<vector<bool>> &done, vector<vector<bool>> &memo, vector<int> &nums){
	if(i==0) return false;
	if(done.at(i).at(n)) return memo.at(i).at(n);
	bool makable;
	if(nums.at(i-1)<n){
		makable = isMakable(i-1, n-nums.at(i-1), done, memo, nums) || isMakable(i-1, n, done, memo, nums) || n==nums.at(i-1);
	}else{
		makable = isMakable(i-1, n, done, memo, nums) || n==nums.at(i-1);
	}
	done.at(i).at(n) = true;
	memo.at(i).at(n) = makable;
	return makable;
}

int main(){
	int i,n,cnt=0;
	cin >> n;
	vector<int> nums(n);
	vector<vector<bool>> done(n+1, vector<bool>(n*100+1));
	vector<vector<bool>> memo(n+1, vector<bool>(n*100+1));
	for(i=0;i<n;++i) cin >> nums.at(i);
	for(i=0;i<n*100+1;++i) if(isMakable(n, i, done, memo, nums)) ++cnt;
	cout << cnt+1 << endl;
	return 0;
}

