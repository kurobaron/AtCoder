#include <iostream>
#include <vector>
using namespace std;

int find_route(int st, int gl, int hv, vector<vector<int>> &pt, vector<bool> passed){
	passed.at(st) = true;
	int ans = 1e9;
	for(int i=0;i<10;++i){
		if(passed.at(i)) continue;
		int cand;
		if(i==gl) cand = hv + pt.at(st).at(i);
		else cand = find_route(i, gl, hv+pt.at(st).at(i), pt, passed);
		ans = min(ans, cand);
	}
	return ans;
}

int main(){
	int i,j,H,W,ans=0;
	cin >> H >> W;
	vector<vector<int>> c(10, vector<int>(10));
	vector<vector<int>> A(H, vector<int>(W));
	vector<int> minpt(10);
	vector<bool> passed(10);
	for(i=0;i<10;++i) for(j=0;j<10;++j) cin >> c.at(i).at(j);
	for(i=0;i<H;++i) for(j=0;j<W;++j) cin >> A.at(i).at(j);
	for(i=0;i<10;++i){
		if(i==1) continue;
		minpt.at(i) = find_route(i,1,0,c,passed);
	}
	for(i=0;i<H;++i){
		for(j=0;j<W;++j){
			if(A.at(i).at(j)==1||A.at(i).at(j)==-1) continue;
			ans += minpt.at(A.at(i).at(j));
		}
	}
	cout << ans << endl;
	return 0;
}
