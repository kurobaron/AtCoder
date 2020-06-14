#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
	int h,w,i,j,sy,sx,gy,gx;
	char tmp;
	cin >> h >> w;
	vector<vector<int>> c(h, vector<int>(w));
	for(i=0;i<h;++i){
		for(j=0;j<w;++j){
			cin >> tmp;
			if(tmp=='s'){
				sy = i;
				sx = j;
				c[i][j] = 1;
			}else if(tmp=='g'){
				gy = i;
				gx = j;
				c[i][j] = -1;
			}else if(tmp=='#') c[i][j] = 1;
			else c[i][j] = -1;
		}
	}
	stack<int> sty;
	stack<int> stx;
	sty.push(sy);
	stx.push(sx);
	while(! sty.empty()){
		int y = sty.top(); sty.pop();
		int x = stx.top(); stx.pop();
		if(x+1<w && c[y][x+1]<0){
			sty.push(y);
			stx.push(x+1);
			c[y][x+1] = 1;
		}
		if(x-1>=0 && c[y][x-1]<0){
			sty.push(y);
			stx.push(x-1);
			c[y][x-1] = 1;
		}
		if(y+1<h && c[y+1][x]<0){
			sty.push(y+1);
			stx.push(x);
			c[y+1][x] = 1;
		}
		if(y-1>=0 && c[y-1][x]<0){
			sty.push(y-1);
			stx.push(x);
			c[y-1][x] = 1;
		}
	}
	if(c[gy][gx]==1) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
