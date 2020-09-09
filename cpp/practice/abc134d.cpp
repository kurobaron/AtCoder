#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,i,idx,cnt;
	cin >> n;
	vector<int> a(n);
	vector<int> ans(n);
	for(i=0;i<n;++i){
		cin >> a.at(i);
		if(i>=n/2) ans.at(i) = a.at(i);
	}
	for(i=n/2-1;i>=0;--i){
		cnt = 0;
		idx = 2*i + 1;
		while(idx<n){
			cnt += ans.at(idx);
			idx += i+1;
		}
		if(cnt%2==0) ans.at(i) = a.at(i);
		else ans.at(i) = (a.at(i)+1)%2;
	}
	cout << cnt+ans.at(0) << endl;
	for(i=0;i<n;++i) if(ans.at(i)==1) cout << i+1 << " ";
	cout << endl;
	return 0;
}
