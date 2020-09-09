#include <iostream>
using namespace std;

int main(){
	int n,i,p,m=1e6,cnt=0;
	cin >> n;
	for(i=0;i<n;++i){
		cin >> p;
		if(p<=m) ++cnt;
		m = min(m,p);
	}
	cout << cnt << endl;
	return 0;
}
