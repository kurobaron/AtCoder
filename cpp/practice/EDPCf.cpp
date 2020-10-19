#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string s,t,ans="";
	int i,j;
	cin >> s >> t;
	vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1));
	for(i=1;i<=s.length();++i){
		for(j=1;j<=t.length();++j){
			if(s[i-1]==t[j-1]) dp.at(i).at(j) = dp.at(i-1).at(j-1)+1;
			else dp.at(i).at(j) = max(dp.at(i-1).at(j),dp.at(i).at(j-1));
		}
	}
	--i; --j;
	while(dp.at(i).at(j)>0){
		if(dp.at(i).at(j)==dp.at(i-1).at(j)) --i;
		else if(dp.at(i).at(j)==dp.at(i).at(j-1)) --j;
		else{
			ans = s[i-1]+ans;
			--i; --j;
		}
	}
	cout << ans << endl;
	return 0;
}
