#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSeparated(int i, int j, int h, int w, vector<vector<char>> s){
	vector<pair<int,int>> p = {{i+1,j},{i-1,j},{i,j+1},{i,j-1}};
	for(auto e : p){
		if(e.first>=h||e.first<0||e.second>=w||e.second<0) continue;
		if(s.at(e.first).at(e.second)=='#') return false;
	}
	return true;
}

int main(){
	int i,j,H,W;
	string ans = "Yes";
	cin >> H >> W;
	vector<vector<char>> S(H,vector<char>(W));
	for(i=0;i<H;++i) for(j=0;j<W;++j) cin >> S.at(i).at(j);
	for(i=0;i<H;++i){
		for(j=0;j<W;++j){
			if(S.at(i).at(j)=='#'){
				if(isSeparated(i,j,H,W,S)) ans = "No";
			}
		}
	}
	cout << ans << endl;
	return 0;
}
