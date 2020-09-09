#include <iostream>
using namespace std;

int main(){
	int n,m,i,l_pre,r_pre,l,r;
	cin >> n >> m;
	cin >> l_pre >> r_pre;
	for(i=1;i<m;++i){
		cin >> l >> r;
		if(r<r_pre) r_pre = r;
		if(l>l_pre) l_pre = l;
	}
	if(l_pre>r_pre) r_pre = l_pre-1;
	cout << r_pre-l_pre+1 << endl;
	return 0;
}
