#include <iostream>
#include <vector>
using namespace std;

int main(){
	int i,x,idx,m;
	cin >> x;
	vector<int> v(1000000);
	for(i=2;i<1000;++i){
		if(v.at(i)==0){
			idx = i;
			m = 2;
			while(idx*m<1000000){
				v.at(idx*m) = 1;
				++m;
			}
		}
	}
	for(i=x;i<1000000;++i){
		if(v.at(i)==0){
			cout << i << endl;
			break;
		}
	}
	return 0;
}
