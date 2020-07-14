#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main(){
	int h,w,k,i,j,kk,cnt=0,ans=0;
	char tmp;
	cin >> h >> w >> kk;
	vector<vector<char>> c(h, vector<char>(w));
	for(i=0;i<h;++i){
		for(j=0;j<w;++j){
			cin >> tmp;
			c.at(i).at(j) = tmp;
			if(tmp=='#') ++cnt;
		}
	}
	for(i=0;i<(1<<h+w);++i){
		vector<vector<char>> cc(h, vector<char>(w));
		copy(c.begin(),c.end(),cc.begin());
		int cnt_t = cnt;
		for(j=0;j<h+w;++j){
			if((i>>j)&1){
				if(j<h){
					for(k=0;k<w;++k){
						if(cc.at(j).at(k)=='#'){
							--cnt_t;
							cc.at(j).at(k) = '.';
						}
					}
				}else{
					for(k=0;k<h;++k){
						if(cc.at(k).at(j-h)=='#'){
							--cnt_t;
							cc.at(k).at(j-h) = '.';
						}
					}
				}
			}	
		}
		if(cnt_t==kk) ++ans;
	}
	cout << ans << endl;
	return 0;
}
