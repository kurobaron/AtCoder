#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main(){
	int i,j,h,w,ih,iw,cnt=0,ans=0;
	cin >> h >> w;
	vector<vector<char>> s(h, vector<char>(w));
	for(i=0;i<h;++i){
		for(j=0;j<w;++j){
			cin >> s.at(i).at(j);
		}
	}
	for(i=0;i<h;++i){
		for(j=0;j<w;++j){
			if(s.at(i).at(j)=='#') continue;
			vector<vector<int>> done(h, vector<int>(w));
			queue<tuple<int,int,int>> q;
			q.push({i,j,0});
			while(!q.empty()){
				ih = get<0>(q.front());
				iw = get<1>(q.front());
				cnt = get<2>(q.front());
				q.pop();
				if(ih<0||ih>=h) continue;
				if(iw<0||iw>=w) continue;
				if(s.at(ih).at(iw)=='#') continue;
				if(done.at(ih).at(iw)) continue;
				done.at(ih).at(iw) = 1;
				ans = max(ans, cnt);
				q.push({ih+1,iw,cnt+1});
				q.push({ih-1,iw,cnt+1});
				q.push({ih,iw+1,cnt+1});
				q.push({ih,iw-1,cnt+1});
			}
		}
	}
	cout << ans << endl;
	return 0;
}
