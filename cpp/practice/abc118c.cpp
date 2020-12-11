#include <iostream>
#include <vector>
using namespace std;

int GCD(int a, int b){
	while(b%a!=0){
		int tmp = b%a;
		b = a;
		a = tmp;
	}
	return a;
}

int main(){
	int i,N;
	cin >> N;
	vector<int> A(N);
	for(i=0;i<N;++i) cin >> A.at(i);
	int ans = A.at(0);
	for(i=1;i<N;++i) ans = GCD(ans, A.at(i));
	cout << ans << endl;
	return 0;
}
