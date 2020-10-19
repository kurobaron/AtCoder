#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

ll dp(ll x, ll p, ll c, vector<vector<ll>> &node, vector<pair<ll,ll>> &memo, vector<pair<bool,bool>> &done){
	if(p!=-1&&node.at(x).size()==1){
		memo.at(x).first = 1;
		memo.at(x).second = 1;
		return 1;
	}
	if(c==0){
		if(done.at(x).first) return memo.at(x).first;
		ll v = 1;
		for(auto &e : node.at(x)){
			if(e==p) continue;
			ll tmp = dp(e, x, 0, node, memo, done);
			tmp = (tmp+dp(e, x, 1, node, memo, done))%MOD;
			v = (v*tmp)%MOD;
		}
		done.at(x).first = true;
		memo.at(x).first = v;
		return v;
	}else{
		if(done.at(x).second) return memo.at(x).second;
		ll v = 1;
		for(auto &e : node.at(x)){
			if(e==p) continue;
			ll tmp = dp(e, x, 0, node, memo, done);
			v = (v*tmp)%MOD;
		}
		done.at(x).second = true;
		memo.at(x).second = v;
		return v;
	}
}

int main(){
	ll i,N,x,y,ans;
	cin >> N;
	vector<vector<ll>> node(N);
	vector<pair<ll,ll>> memo(N);
	vector<pair<bool,bool>> done(N);
	for(i=0;i<N-1;++i){
		cin >> x >> y;
		--x; --y;
		node.at(x).push_back(y);
		node.at(y).push_back(x);
	}
	ans = (dp(0, -1, 0, node, memo, done)+dp(0, -1, 1, node, memo, done))%MOD;
	while(ans<0) ans += MOD;
	cout << ans << endl;
	return 0;
}
