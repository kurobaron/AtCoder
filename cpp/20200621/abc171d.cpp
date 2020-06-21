#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){
	int n,q,i,b,c,tmp;
	long long sum=0,t;
	cin >> n;
	vector<int> a(n);
	vector<int> cnt(1000000);
	vector<long long> ans;
	for(i=0;i<n;++i){
		cin >> tmp;
		++cnt.at(tmp);
		a.at(i) = tmp;
	}
	sum = accumulate(a.begin(),a.end(),0LL);
	cin >> q;
	for(i=0;i<q;++i){
		cin >> b >> c;
		t = (c-b)*cnt.at(b);
		cnt.at(c) += cnt.at(b);
		cnt.at(b) = 0;
		sum += t;
		ans.push_back(sum);
	}
	i = 0;
	while(true){
		cout << ans.at(i) << endl;
		++i;
		if(i==q) break;
	}
	return 0;
}
