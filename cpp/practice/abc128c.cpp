#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main(){
	int n,m,i,j,k,s,cnt,ans=0;
	bool ok;
	cin >> n >> m;
	vector<vector<int>> sw(m);
	vector<int> p(m);
	for(i=0;i<m;++i){
		cin >> k;
		for(j=0;j<k;++j){
			cin >> s; --s;
			sw.at(i).push_back(s);
		}
	}
	for(i=0;i<m;++i) cin >> p.at(i);
	for(i=0;i<(1<<n);++i){
		ok = true;
		for(j=0;j<m;++j){
			cnt = 0;
			for(auto e : sw.at(j)) if((i>>e)&1) ++cnt;
			if(cnt%2!=p.at(j)){
				ok = false;
				break;
			}
		}
		if(ok) ++ans;
	}
	cout << ans << endl;
	return 0;
}
