#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int main(){
	int i,j,H,W,x,y,cnt;
	char c;
	cin >> H >> W;
	vector<vector<char>> mp(H,vector<char>(W));
	vector<vector<int>> rt(H,vector<int>(W,-1));
	vector<vector<pair<int,int>>> tp(26);
	vector<bool> flg(26);
	queue<tuple<int,int,int>> q;
	for(i=0;i<H;++i){
		for(j=0;j<W;++j){
			cin >> c;
			mp.at(i).at(j) = c;
			if(c=='.'||c=='#'||c=='S'||c=='G'){
				if(c=='S') q.push(make_tuple(i,j,0));
				continue;
			}
			tp.at((int)(c-'a')).push_back({i,j});	
		}
	}
	while(!q.empty()){
		y = get<0>(q.front());
		x = get<1>(q.front());
		cnt = get<2>(q.front());
		q.pop();
		if(rt.at(y).at(x)==-1) rt.at(y).at(x) = cnt;
		else continue;
		if(mp.at(y).at(x)=='G'){
			cout << rt.at(y).at(x) << endl;
			return 0;
		}
		if(x-1>=0){
			if(mp.at(y).at(x-1)!='#'&&rt.at(y).at(x-1)==-1){
				q.push(make_tuple(y,x-1,cnt+1));
			}
		}
		if(x+1<W){
			if(mp.at(y).at(x+1)!='#'&&rt.at(y).at(x+1)==-1){
				q.push(make_tuple(y,x+1,cnt+1));
			}
		}
		if(y-1>=0){
			if(mp.at(y-1).at(x)!='#'&&rt.at(y-1).at(x)==-1){
				q.push(make_tuple(y-1,x,cnt+1));
			}
		}
		if(y+1<H){
			if(mp.at(y+1).at(x)!='#'&&rt.at(y+1).at(x)==-1){
				q.push(make_tuple(y+1,x,cnt+1));
			}
		}
		if(mp.at(y).at(x)!='#'&&mp.at(y).at(x)!='.'&&mp.at(y).at(x)!='S'&&mp.at(y).at(x)!='G'){
			if(flg.at((int)(mp.at(y).at(x)-'a'))==false){
				flg.at((int)(mp.at(y).at(x)-'a')) = true;
				for(auto &e : tp.at((int)(mp.at(y).at(x)-'a'))){
					if(e.first==y&&e.second==x) continue;
					if(rt.at(e.first).at(e.second)==-1) q.push(make_tuple(e.first,e.second,cnt+1));
				}
			}
		}
	}	
	cout << -1 << endl;
	return 0;
}
