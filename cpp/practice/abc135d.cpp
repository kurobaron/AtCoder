#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main(){
	string s;
	int n,i,j,k,supNow,supPre=1;
	cin >> s;
	vector<vector<ll>> dp(s.length()+1, vector<ll>(13));
	dp.at(0).at(0) = 1;
	for(i=1;i<s.length()+1;++i){
		n = s[s.length()-i]=='?' ? -1 : s[s.length()-i] - '0';
		supNow = i==1 ? 1 : supPre*10%13;
		if(n!=-1){
			n = n*supNow%13;
			for(j=0;j<13;++j){
				dp.at(i).at((j+n)%13) += dp.at(i-1).at(j);
			}
		}else{
			for(k=0;k<10;++k){
				n = k*supNow%13;
				for(j=0;j<13;++j){
					dp.at(i).at((j+n)%13) += dp.at(i-1).at(j);
				}
			}
		}	
		supPre = supNow;
		for(j=0;j<13;++j) dp.at(i).at(j) %= MOD;
	}
	cout << dp.at(s.length()).at(5) << endl;
	return 0;
}
