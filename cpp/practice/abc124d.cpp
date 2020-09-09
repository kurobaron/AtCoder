#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	int n,k,i,inv=0,l=0,r=0,ans=0;
	char c;
	cin >> n >> k;
	vector<int> v(n);
	for(i=0;i<n;++i){
		cin >> c;
		v.at(i) = (int)c - 48;
	}
	if(v.at(0)==0) ++inv;
	while(r<n){
		while(inv<=2*k){
			++r;
			if(r>=n) break;
			if(v.at(r)!=v.at(r-1)) ++inv;
		}
		ans = max(ans, r-l);
		while(1){
			++l;
			if(l>=n) break;
			if(v.at(l)==1&&v.at(l-1)==0){
				inv -= 2;
				break;
			} 
		}	
	}
	cout << ans << endl;
	return 0;
}
