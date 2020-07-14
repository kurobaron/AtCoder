#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
	int n,k,r,s,p,i,cnt,idx,ans=0;
	char pre;
	cin >> n >> k;
	cin >> r >> s >> p;
	vector<char> t(n);
	vector<int> v(n);
	map<char, int> pt;
	pt['r'] = p; pt['s'] = r; pt['p'] = s;
	for(i=0;i<n;++i){
		cin >> t.at(i);
		ans += pt[t.at(i)];
	}
	for(i=0;i<n;++i){
		if(v.at(i)==1) break;
		cnt = 1;
		pre = t.at(i);
		idx = i+k;
		while(idx<n){
			v.at(idx) = 1;
			if(t.at(idx)==pre) ++cnt;
			else{
				if(cnt>1){
					ans -= pt[pre]*(cnt/2);
					cnt = 1;
				}
			}
			pre = t.at(idx);
			idx += k;
		}
		if(cnt>1){
			ans -= pt[pre]*(cnt/2);
			cnt = 1;
		}
	}
	cout << ans << endl;
	return 0;
}
