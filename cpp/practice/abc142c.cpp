#include <iostream>
#include <vector>
using namespace std;

int main(){
	long long n,i,tmp;
	cin >> n;
	vector<long long> a(n);
	for(i=0;i<n;++i){
		cin >> tmp;
		a.at(tmp-1) = i+1;
	}
	for(i=0;i<n;++i) cout << a.at(i) << " ";
	cout << endl;
	return 0;
}
