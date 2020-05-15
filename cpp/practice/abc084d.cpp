#include <iostream>
#include <vector>
using namespace std;

int main(){
	int i,j,Q;
	vector<int> s(100001);
	vector<int> p(100001, 1);
	p[0] = 0;
	p[1] = 0;
	for(i=2;i*i<=100000;i++){
		if(p[i]==0)continue;
		else{
			for(j=2;j*i<=100000;j++){
				p[j*i] = 0;
			}
		}
	}
	for(i=3;i<=100000;i=i+2){
		if(p[i]==1 && p[(i+1)/2]==1){
			s[i] = s[i-2]+1;
		}
		else{
			s[i] = s[i-2];
		}
	}
	cin >> Q;
	vector<int> l(Q);
	vector<int> r(Q);
	for(i=0;i<Q;i++){
		cin >> l[i] >> r[i];
	}
	for(i=0;i<Q;i++){
		cout << s[r[i]] - s[l[i]-2] << endl;
	}
	return 0;
}
