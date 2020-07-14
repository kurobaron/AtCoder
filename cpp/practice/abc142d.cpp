#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	long long  a,b,i,idx,tmp,gca,ans=1;
	cin >> a >> b;
	while(1){
		tmp = b%a;
		if(tmp==0) break;
		b = a;
		a = tmp;
	}
	gca = a;
	vector<long long> v((long long)sqrt(gca)+1);
	for(i=2;i<(long long)sqrt(gca)+1;++i){
		if(v.at(i)==1 || a%i!=0) continue;
		else{
			++ans;
			idx = i;
			while(idx<(long long)sqrt(gca)+1){
				v.at(idx) = 1;
				idx += i;
			}
			while(a%i==0) a /= i;
		}
	}
	if(a>1) ++ans;
	cout << ans << endl;
	return 0;
}
