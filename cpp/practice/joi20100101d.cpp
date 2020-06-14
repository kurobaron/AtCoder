#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
	int n,k,i;
	cin >> n;
	cin >> k;
	vector<string> nums(n);
	vector<string> ans;
	for(i=0;i<n;++i){
		cin >> nums.at(i);
	}
	sort(nums.begin(), nums.end());
	do{
		string tmp;
		for(i=0;i<k;++i){
			tmp += nums.at(i);
		}
		if(find(ans.begin(), ans.end(), tmp)==ans.end()) ans.push_back(tmp);
	}while(next_permutation(nums.begin(), nums.end()));
	cout << ans.size() << endl;
	return 0;
}
