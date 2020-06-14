#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int d,g,i,j,cnt,num,idx,ans=1000;
	cin >> d >> g;
	vector<int> p(d);
	vector<int> c(d);
	for(i=0;i<d;++i){
		cin >> p.at(i) >> c.at(i);
	}
	for(i=0;i<(1<<d);++i){
		cnt = 0;
		num = 0;
		idx = 0;
		for(j=0;j<d;++j){
			if((i>>j)&1==1){
				cnt += p[j]*((j+1)*100)+c[j];
				num += p[j];
			}
			else idx = max(idx, j);
		}
		if(cnt>=g) ans = min(ans, num);
		else{
			for(j=0;j<p[idx];++j){
				cnt += (idx+1)*100;
				++num;
				if(cnt>=g){
					ans = min(ans,num);
					break;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
