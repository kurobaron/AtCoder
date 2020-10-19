#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
	ll N,X,M,ans,cnt=0,tmp=0,flg=0;
	cin >> N >> X >> M;
	vector<bool> done(M);
	vector<pair<ll,ll>> s(M);
	ans = X;
	done.at(X) = true;
	while(1){
		X = (X*X)%M;
		tmp += X;
		++cnt;
		if(cnt==N-1){
			ans += tmp;
			break;
		}
		if(done.at(X)){
			ans += s.at(X).second;
			cnt -= s.at(X).first;
			ans += ((N-1-s.at(X).first)/cnt)*(tmp-s.at(X).second);
			flg = 1;
			break;
		}
		s.at(X) = {cnt,tmp};
		done.at(X) = true;
	}
	if(flg){
		cnt = (N-1-s.at(X).first)%cnt;
		while(cnt){
			ans += (X*X)%M;
			X = (X*X)%M;
			--cnt;
		}
	}
	cout << ans << endl;
	return 0;
}
