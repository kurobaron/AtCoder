#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(){
	int h,w,i,j,ch,cw,dh,dw,nh,nw,nv;
	cin >> h >> w;
	vector<vector<char>> s(h,vector<char>(w));
	vector<vector<int>> c(h,vector<int>(w,1e7));
	cin >> ch >> cw;
	--ch; --cw;
	cin >> dh >> dw;
	--dh; --dw;
	for(i=0;i<h;++i){
		for(j=0;j<w;++j){
			cin >> s.at(i).at(j);
		}
	}
	c.at(ch).at(cw) = 0;
	deque<pair<int,int>> q;
	q.push_front({ch,cw});
	while(q.size()){
		nh = q.front().first;
		nw = q.front().second;
		nv = c.at(nh).at(nw);
		q.pop_front();
		for(i=-2;i<=2;++i){
			for(j=-2;j<=2;++j){
				if(nh+i<0||nh+i>=h) continue;
				if(nw+j<0||nw+j>=w) continue;
				if(s.at(nh+i).at(nw+j)=='#') continue;
				if(i==0&&j==0) continue;
				if(c.at(nh+i).at(nw+j)>nv){
					if(abs(i)+abs(j)==1){
						c.at(nh+i).at(nw+j) = nv;
						q.push_front({nh+i,nw+j});
					}else if(c.at(nh+i).at(nw+j)==1e7){
						c.at(nh+i).at(nw+j) = nv+1;
						q.push_back({nh+i,nw+j});
					}
				}
			}
		}
	}
	if(c.at(dh).at(dw)==1e7) cout << -1 << endl;
	else cout << c.at(dh).at(dw) << endl;
	return 0;
}
