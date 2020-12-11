#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main(){
	ll N,M,i,w,ans=INF;
	cin >> N >> M;
	vector<ll> H(N);
	vector<ll> W(M);
	for(i=0;i<N;++i) cin >> H.at(i);
	for(i=0;i<M;++i) cin >> W.at(i);
	sort(H.begin(),H.end());
	vector<ll> sum1((N+1)/2); vector<ll> sum2((N+1)/2);
	for(i=0;i+1<N;i+=2) sum1.at(i/2+1) = sum1.at(i/2) + H.at(i+1) - H.at(i);
	for(i=N-1;i>0;i-=2) sum2.at(i/2-1) = sum2.at(i/2) + H.at(i) - H.at(i-1);
	for(i=0;i<M;++i){
		w = W.at(i);
		ll idx = lower_bound(H.begin(),H.end(),w)-H.begin();
		if(idx%2==1) --idx;
		ans = min(ans,sum1.at(idx/2)+sum2.at(idx/2)+abs(H.at(idx)-w));
	}
	cout << ans << endl;
	return 0;
}
