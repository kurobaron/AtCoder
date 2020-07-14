#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <bitset>
#include <cmath>
using namespace std;

long long ptA(int n, int w, vector<int> &V, vector<int> &W){
	int half = n/2;
	int rem = n - half;
	long long ans = 0;
	vector<pair<long long, long long>> H(pow(2,half));
	vector<pair<long long, long long>> R(pow(2,rem));
	for(int i=0;i<(1<<half);++i){
		long long va = 0;
		long long wa = 0;
		for(int j=0;j<half;++j){
			if(1&(i>>j)){
				va += V.at(j+1);
				wa += W.at(j+1);
			}
		}
		if(wa<=w) ans = max(ans, va);
		H.at(i) = make_pair(va, wa);	
	}
	for(int i=0;i<(1<<rem);++i){
		long long va = 0;
		long long wa = 0;
		for(int j=0;j<rem;++j){
			if(1&(i>>j)){
				va += V.at(half+j+1);
				wa += W.at(half+j+1);
			}
		}
		if(wa<=w) ans = max(ans, va);
		R.at(i) = make_pair(va, wa);
	}
	sort(H.begin(), H.end(), [](const pair<long long,long long> &lp, const pair<long long,long long> &rp){return lp.second < rp.second;});
	for(int i=1;i<H.size();++i){
		if(H.at(i-1).first>=H.at(i).first) H.erase(H.begin()+i);
		else if(H.at(i-1).second==H.at(i).second) H.erase(H.begin()+i-1);
	}
	for(int i=0;i<R.size();++i){
		int idx,vb=0,ve=H.size()-1;
		if(H.at(0).second+R.at(i).second>w) continue;
		while((ve-vb)!=1){
			idx = (vb+ve)/2;
			if(H.at(idx).second+R.at(i).second>w) ve = idx;
			else vb = idx;
		}
		if(H.at(ve).second+R.at(i).second<=w) ans = max(ans, H.at(ve).first+R.at(i).first);
		else ans = max(ans, H.at(vb).first+R.at(i).first);
	}
	return ans;
}

long long ptB(int n, int w, long long tot, vector<int> &V, vector<int> &W){
	vector<vector<long long>> dp(n+1,vector<long long>(tot+1, 1000000000000));
	for(int i=0;i<n+1;++i) dp.at(i).at(0) = 0;
	for(int i=1;i<n+1;++i){
		for(int j=0;j<tot+1;++j){
			if(j-V.at(i)<0) dp.at(i).at(j) = dp.at(i-1).at(j);
			else dp.at(i).at(j) = min(dp.at(i-1).at(j-V.at(i))+W.at(i),dp.at(i-1).at(j));
		}
	}
	long long ans = 0;
	for(int i=0;i<tot+1;++i) if(dp.at(n).at(i)<=w) ans = i;
	return ans;
}

long long ptC(int n, int w, vector<int> &V, vector<int> &W){
	vector<vector<long long>> dp(n+1,vector<long long>(w+1));
	for(int i=1;i<n+1;++i){
		for(int j=0;j<w+1;++j){
			if(j-W.at(i)>=0) dp.at(i).at(j) = max(dp.at(i-1).at(j), dp.at(i-1).at(j-W.at(i))+V.at(i));
			else dp.at(i).at(j) = dp.at(i-1).at(j);
		}
	}
	return dp.at(n).at(w);
}

int main(){
	int n,w,i,j,flg=0;
	long long ans,tot=0;
	cin >> n >> w;
	vector<int> W(n+1);
	vector<int> V(n+1);
	for(i=1;i<n+1;++i){
		cin >> V.at(i) >> W.at(i);	
		tot += V.at(i);
		if(W.at(i)>1000) flg = 1;
	}
	if(n<=30) ans = ptA(n, w, V, W);
	else if(flg==1) ans = ptB(n, w, tot, V, W);
	else ans = ptC(n, w, V, W);
	cout << ans << endl;
	return 0;
}
