#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
	ll i,N,sum=0,now=0,pre=0,edge=0,ans=0;
	cin >> N;
	vector<ll> A(N);
	for(i=0;i<N;++i) cin >> A.at(i);
	for(i=0;i<N;++i){
		sum += A.at(i);
		now = pre + sum;
		if(now>pre){
			if(now-pre>edge) edge = now-pre;
			if(now>ans) ans = now;
		}
		if(i>0) if(pre+edge>ans) ans = pre+edge;
		pre = now;
	}
	cout << ans << endl;
	return 0;
}
