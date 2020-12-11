#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
	ll i,j,H,W,N,M,x,y,cnt;
	bool l_on;
	cin >> H >> W >> N >> M;
	vector<vector<ll>> b(H,vector<ll>(W));
	vector<vector<ll>> l(H,vector<ll>(W));
	for(i=0;i<N;++i){
		cin >> x >> y;
		--x; --y;
		l.at(x).at(y) = 1;
	}
	for(i=0;i<M;++i){
		cin >> x >> y;
		--x; --y;
		b.at(x).at(y) = 1;
	}
	vector<vector<ll>> ans(H,vector<ll>(W));
	cnt = 0;
	for(i=0;i<H;++i){
		l_on=false;
		for(j=0;j<W;++j){
			if(l_on==false&&l.at(i).at(j)==1) l_on=true;
			if(l_on==true&&b.at(i).at(j)==1) l_on=false;
			if(l_on==true&&ans.at(i).at(j)==0&&b.at(i).at(j)==0){
				ans.at(i).at(j) = 1;
				++cnt;
			}
		}
	}
	for(i=H-1;i>=0;--i){
		l_on=false;
		for(j=W-1;j>=0;--j){
			if(l_on==false&&l.at(i).at(j)==1) l_on=true;
			if(l_on==true&&b.at(i).at(j)==1) l_on=false;
			if(l_on==true&&ans.at(i).at(j)==0&&b.at(i).at(j)==0){
				ans.at(i).at(j) = 1;
				++cnt;
			}
		}
	}
	for(j=0;j<W;++j){
		l_on=false;
		for(i=0;i<H;++i){
			if(l_on==false&&l.at(i).at(j)==1) l_on=true;
			if(l_on==true&&b.at(i).at(j)==1) l_on=false;
			if(l_on==true&&ans.at(i).at(j)==0&&b.at(i).at(j)==0){
				ans.at(i).at(j) = 1;
				++cnt;
			}
		}
	}
	for(j=W-1;j>=0;--j){
		l_on=false;
		for(i=H-1;i>=0;--i){
			if(l_on==false&&l.at(i).at(j)==1) l_on=true;
			if(l_on==true&&b.at(i).at(j)==1) l_on=false;
			if(l_on==true&&ans.at(i).at(j)==0&&b.at(i).at(j)==0){
				ans.at(i).at(j) = 1;
				++cnt;
			}
		}
	}
	
	cout << cnt << endl;
	return 0;
}
