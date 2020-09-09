#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,i;
	cin >> n;
	vector<int> d(n);
	for(i=0;i<n;++i) cin >> d.at(i);
	sort(d.begin(),d.end());
	cout << d.at(n/2)-d.at(n/2-1) << endl;
	return 0;
}
