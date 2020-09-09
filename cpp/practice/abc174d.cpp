#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,i,ans=0,it_l,it_r;
	cin >> n;
	vector<char> c(n);
	for(i=0;i<n;++i) cin >> c.at(i);
	it_l = 0; it_r = n-1;
	while(it_l<it_r){
		if(c.at(it_l)=='W'){
			while(c.at(it_r)!='R'){
				--it_r;
				if(it_l==it_r) break;
			}
			if(it_l<it_r){
				++ans;
				--it_r;
			}
		}
		++it_l;
	}
	cout << ans << endl;
	return 0;
}
