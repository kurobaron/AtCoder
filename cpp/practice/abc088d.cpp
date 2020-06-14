#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int h,w,i,j,y,x,cnt=0;
	queue<int> qy;
	queue<int> qx;
	cin >> h >> w;
	vector<vector<char>> s(h, vector<char>(w));
	vector<vector<int>> d(h, vector<int>(w));
	for(i=0;i<h;++i){
		for(j=0;j<w;++j){
			cin >> s[i][j];
			if(s[i][j]=='.') cnt += 1;
		}
	}
	qy.push(0);
	qx.push(0);
	d[0][0] = 1;
	while(!qy.empty()){
		y = qy.front(); qy.pop();
		x = qx.front(); qx.pop();
		if(x+1<w && s[y][x+1]=='.' && d[y][x+1]==0){
			qy.push(y);
			qx.push(x+1);
			d[y][x+1] = d[y][x]+1;
		}
		if(x-1>=0 && s[y][x-1]=='.' && d[y][x-1]==0){
			qy.push(y);
			qx.push(x-1);
			d[y][x-1] = d[y][x]+1;
		}
		if(y+1<h && s[y+1][x]=='.' && d[y+1][x]==0){
			qy.push(y+1);
			qx.push(x);
			d[y+1][x] = d[y][x]+1;
		}
		if(y-1>=0 && s[y-1][x]=='.' && d[y-1][x]==0){
			qy.push(y-1);
			qx.push(x);
			d[y-1][x] = d[y][x]+1;
		}
	}
	if(d[h-1][w-1]==0) cout << -1 << endl;
	else cout << cnt - d[h-1][w-1] << endl;
	return 0;
}
