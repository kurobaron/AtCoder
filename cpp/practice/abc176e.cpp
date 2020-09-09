#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
	ll h,w,m,i,ht,wt,hmax=0,wmax=0,hcnt=0,wcnt=0,bcnt=0;
	cin >> h >> w >> m;
	vector<ll> bh(h);
	vector<ll> bw(w);
	vector<pair<ll,ll>> vp(m);
	for(i=0;i<m;++i){
		cin >> ht >> wt;
		--ht; --wt;
		++bh.at(ht);
		++bw.at(wt);
		hmax = max(hmax,bh.at(ht));
		wmax = max(wmax,bw.at(wt));
		vp.at(i) = make_pair(ht,wt);
	}
	for(i=0;i<h;++i) if(bh.at(i)==hmax) ++hcnt;
	for(i=0;i<w;++i) if(bw.at(i)==wmax) ++wcnt;
	for(i=0;i<m;++i){
		ht = vp.at(i).first;
		wt = vp.at(i).second;
		if(bh.at(ht)==hmax&&bw.at(wt)==wmax) ++bcnt;
	}
	if(hcnt*wcnt>bcnt) cout << hmax+wmax << endl;
	else cout << hmax+wmax-1 << endl;
	return 0;
}
