#include <iostream>
#include <vector>
using namespace std;

int main(){
	int i,N,ans,tot=0;
	cin >> N;
	vector<int> A(N+2);
	for(i=1;i<N+1;++i) cin >> A.at(i);
	for(i=1;i<N+2;++i) tot += abs(A.at(i)-A.at(i-1));
	for(i=1;i<N+1;++i){
		ans = tot-abs(A.at(i+1)-A.at(i))-abs(A.at(i)-A.at(i-1));
		ans += abs(A.at(i+1)-A.at(i-1));
		cout << ans << endl;
	}
	return 0;
}
