#include <iostream>
#include <vector>
using namespace std;

int main(){
	int i,N,K,ans;
	cin >> N >> K;
	vector<int> A(N);
	for(i=0;i<N;++i) cin >> A.at(i);
	N -= K;
	ans = N%(K-1)==0 ? N/(K-1)+1 : N/(K-1)+2;
	cout << ans << endl;
	return 0;
}
