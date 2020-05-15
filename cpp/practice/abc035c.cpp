#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

int main(){
	int N,Q,l,r,i;
	cin >> N >> Q;
	vector<int> s(N+1);
	for(i=0;i<Q;++i){
		cin >> l >> r;
		++s[l-1];
		++s[r];
	}
	if(s[0]%2==1) s[0] = 1;
	else s[0] = 0;
	for(i=1;i<N;++i){
		s[i] = (s[i]%2)^(s[i-1]);
	}	
	for(i=0;i<N;++i){
		cout << s[i];
		if(i==N-1) cout << endl;
	}
	return 0;
}
