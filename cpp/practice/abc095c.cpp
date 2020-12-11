#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int i,N,br,bl;
	cin >> N;
	vector<int> X(N);
	vector<int> sX(N);
	for(i=0;i<N;++i){
		cin >> X.at(i);
	}
	sX = X;
	sort(sX.begin(),sX.end());
	bl = sX.at((N-1)/2);
	br = sX.at(N/2);
	for(i=0;i<N;++i){
		if(X.at(i)<=bl) cout << br << endl;
		else cout << bl << endl;
	}
	return 0;
}
