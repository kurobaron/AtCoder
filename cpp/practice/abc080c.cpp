#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;
using ll = long long;

int main(){
	ll i,j,N,cnt,ans=-1e10;
	cin >> N;
	vector<string> S(N);
	vector<vector<ll>> P(N,vector<ll>(11));
	for(i=0;i<N;++i){
		string s = "";
		char c;
		for(j=0;j<10;++j){
			cin >> c;
			s += c;
		}
		S.at(i) = s;
	}	
	for(i=0;i<N;++i) for(j=0;j<11;++j) cin >> P.at(i).at(j);
	for(i=1;i<(1<<10);++i){
		cnt = 0;
		for(j=0;j<N;++j){
			cnt += P.at(j).at((bitset<10>(i)&bitset<10>(S[j])).count());
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
