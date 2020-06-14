#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int h,w,i,j,y,x,cnt;
	char tmp;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));
	queue<vector<int>> q;
	for(i=0;i<h;++i){
		for(j=0;j<w;++j){
			cin >> tmp;
			if(tmp=='#'){
			       	a.at(i).at(j) = 1;
				q.push({i, j, 0});
			}
			else a.at(i).at(j) = 0;
		}
	}
	while(!q.empty()){
		vector<int> v = q.front(); q.pop();
		y = v.at(0);
		x = v.at(1);
		cnt = v.at(2);
		if(x+1<w && a.at(y).at(x+1)==0){
			a.at(y).at(x+1) = 1;
			q.push({y, x+1, cnt+1});
		}
		if(x-1>=0 && a.at(y).at(x-1)==0){
			a.at(y).at(x-1) = 1;
			q.push({y, x-1, cnt+1});
		}
		if(y+1<h && a.at(y+1).at(x)==0){
			a.at(y+1).at(x) = 1;
			q.push({y+1, x, cnt+1});
		}
		if(y-1>=0 && a.at(y-1).at(x)==0){
			a.at(y-1).at(x) = 1;
			q.push({y-1, x, cnt+1});
		}
	}
	cout << cnt << endl;
	return 0;
}	
