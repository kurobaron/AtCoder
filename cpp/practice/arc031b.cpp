#include <iostream>
#include <vector>
using namespace std;
const int INF = 1000000;

void exp(int n, int y, int x, vector<vector<int>> &v, vector<vector<int>> &m){
	v[y][x] = INF;
	if(x+1<10){
		if(v[y][x+1]==0) exp(n, y, x+1, v, m);
		else if(v[y][x+1]<0) v[y][x+1] = n; 
		else if(v[y][x+1]!=n && v[y][x+1]!=INF){
			v[y][x+1] = n;
			m[y][x+1] += 1;
		}
	}
	if(x-1>=0){
		if(v[y][x-1]==0) exp(n, y, x-1, v, m);
		else if(v[y][x-1]<0) v[y][x-1] = n; 
		else if(v[y][x-1]!=n && v[y][x-1]!=INF){
			v[y][x-1] = n;
			m[y][x-1] += 1;
		}
	}
	if(y+1<10){
		if(v[y+1][x]==0) exp(n, y+1, x, v, m);
		else if(v[y+1][x]<0) v[y+1][x] = n; 
		else if(v[y+1][x]!=n && v[y+1][x]!=INF){
			v[y+1][x] = n;
			m[y+1][x] += 1;
		}
	}
	if(y-1>=0){
		if(v[y-1][x]==0) exp(n, y-1, x, v, m);
		else if(v[y-1][x]<0) v[y-1][x] = n; 
		else if(v[y-1][x]!=n && v[y-1][x]!=INF){
			v[y-1][x] = n;
			m[y-1][x] += 1;
		}
	}
	return;
}
int main(){
	int i,j,cnt=0;
	char tmp;
	vector<vector<int>> mp(10, vector<int>(10));
	vector<vector<int>> a(10, vector<int>(10));
	for(i=0;i<10;++i){
		for(j=0;j<10;++j){
			cin >> tmp;
			if(tmp=='o') mp[i][j] = 0;
			else mp[i][j] = -1;
		}
	}
	for(i=0;i<10;++i){
		for(j=0;j<10;++j){
			if(mp[i][j]==0){
				cnt += 1;
				exp(cnt, i, j, mp, a);
			}
		}
	}
	for(i=0;i<10;++i){
		for(j=0;j<10;++j){
			if(a[i][j]==cnt-1){
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
