#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

void out(int N, int y, int x, vector<vector<int>> &v, vector<vector<int>> &w){
	if(w[y][x]==-1) return;
	else w[y][x] = -1;
	if(v[y][x]==0){
		out(N, y, x+1, v, w);
		out(N, y, x-1, v, w);
		out(N, y+1, x, v, w);
		out(N, y-1, x, v, w);
	}else w[y][x] = -1;
	return;
}

int main(){
	int N,i,x,y,a,tmp,cnt=0;
	cin >> N;
	vector<vector<int>> p(N, vector<int>(N, 1));
	vector<vector<int>> q(N, vector<int>(N, 1));
	for(i=0;i<N*N;++i){
		if(i/N==0 || i/N==N-1 || i%N==0 || i%N==N-1) q[i/N][i%N] = -1;
		cout << q[i/N][i%N];
		if(i%N==N-1) cout << endl;
	}
	for(i=0;i<N*N;++i){
		cin >> tmp;
		--tmp;
		y = tmp/N;
		x = tmp%N;
		p[x][y] = 0;
		if(y==0){
			out(N, y+1, x, p, q);
		}else if(y==N-1){
			out(N, y-1, x, p, q);
		}else if(x==0){
			out(N, y, x+1, p, q);
		}else if(x==N-1){
			out(N, y, x-1, p, q);
		}else{
			if(q[y][x]==-1){
				out(N, y, x+1, p, q);
				out(N, y, x-1, p, q);
				out(N, y+1, x, p, q);
				out(N, y-1, x, p, q);
			}else{
				
			}
		}
	}
	for(i=0;i<N*N;++i){
		cout << p[i/N][i%N];
		if(i%N==N-1) cout << endl;
	}
	cout << cnt << endl;
	return 0;
}
