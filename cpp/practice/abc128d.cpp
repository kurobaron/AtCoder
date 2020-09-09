#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;

int main(){
	int N,K,i,j,k,r,l,n,surp;
	ll ans=0;
	cin >> N >> K;
	vector<ll> v(N);
	for(i=0;i<N;++i) cin >> v.at(i);
	n = min(N,K);
	for(i=0;i<=n;++i){
		for(r=0;r<=i;++r){
			vector<ll> lis;
			l = i - r;
			for(j=0;j<r;++j) lis.push_back(*(v.end()-1-j));
			for(k=0;k<l;++k) lis.push_back(v.at(k));
			sort(lis.begin(),lis.end());
			surp = K - i;
			while(surp){
				if(lis.size()==0) break;
				if(lis.at(0)<0) lis.erase(lis.begin());
				else break;
				--surp;
			}
			ans = max(ans, accumulate(lis.begin(), lis.end(), 0LL));
		}
	}
	cout << ans << endl;
	return 0;
}
