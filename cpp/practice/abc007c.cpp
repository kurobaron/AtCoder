#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int R,C,sy,sx,gy,gx,i,j;
	char tmp;
	queue<int> qr;
	queue<int> qc;
	cin >> R >> C;
	cin >> sy >> sx;
	--sy; --sx;
	cin >> gy >> gx;
	--gy; --gx;
	vector<vector<int>> c(R, vector<int>(C));
	for(i=0;i<R;++i){
		for(j=0;j<C;++j){
			cin >> tmp;
			if(tmp=='#') c[i][j] = 1000;
			else c[i][j] = -1;
		}
	}
	qr.push(sy); qc.push(sx);
	c[sy][sx] = 0;
	while(!qr.empty()){
		int ny = qr.front(); qr.pop();
		int nx = qc.front(); qc.pop();
		if(c[ny][nx+1]<0){
			c[ny][nx+1] = c[ny][nx] + 1;
			qr.push(ny); qc.push(nx+1);
		}
		if(c[ny][nx-1]<0){
			c[ny][nx-1] = c[ny][nx] + 1;
			qr.push(ny); qc.push(nx-1);
		}
		if(c[ny+1][nx]<0){
			c[ny+1][nx] = c[ny][nx] + 1;
			qr.push(ny+1); qc.push(nx);
		}
		if(c[ny-1][nx]<0){
			c[ny-1][nx] = c[ny][nx] + 1;
			qr.push(ny-1); qc.push(nx);
		}
	}
	cout << c[gy][gx] << endl;
	return 0;
}
