#include <iostream>
#include <vector>
using namespace std;

int main(){
	int i,n,k,cnt=0,idx=0,max_val;
	double num=0,ans=0;
	cin >> n >> k;
	vector<int> p(n);
	vector<double> e(1001);
	for(i=1;i<1001;++i){
		num += (double)i;
		e.at(i) = num/i;
	}
	for(i=0;i<n;++i){
		cin >> p.at(i);
		if(i<k) cnt += p.at(i); 
	}
	max_val = cnt;
	for(i=0;i<n-k;++i){
		cnt -= p.at(i);
		cnt += p.at(i+k);	
		if(cnt>max_val){
			max_val = cnt;
			idx = i+1;
		}
	}
	for(i=idx;i<idx+k;++i) ans += e.at(p.at(i));
	printf("%.12f\n", ans);
	return 0;
}
