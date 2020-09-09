#include <iostream>
#include <vector>
using namespace std;

int main(){
	int h,w,i,j,k,idx,cnt,ans=0;
	char tmp;
	cin >> h >> w;
	vector<vector<pair<int,int>>> g(h,vector<pair<int,int>>(w));
	for(i=0;i<h;++i){
		for(j=0;j<w;++j){
			cin >> tmp;
			if(tmp=='#') g.at(i).at(j) = make_pair(-1,0);
		}
	}
	for(i=0;i<h;++i){
		for(j=0;j<w;++j){
			if(g.at(i).at(j).first==-1) continue;
			if(g.at(i).at(j).first==0){
				idx = j+1; cnt = 1;
				while(idx<w){
					if(g.at(i).at(idx).first==-1) break;
					++idx;
					++cnt;
				}
				for(k=j;k<idx;++k) g.at(i).at(k).first = cnt;
			}
			if(g.at(i).at(j).second==0){
				idx = i+1; cnt = 1;
				while(idx<h){
					if(g.at(idx).at(j).first==-1) break;
					++idx;
					++cnt;
				}
				for(k=i;k<idx;++k) g.at(k).at(j).second = cnt;
			}
			ans = max(ans, g.at(i).at(j).first+g.at(i).at(j).second-1);
		}
	}
	cout << ans << endl;
	return 0;
}
