#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N,i,j=0;
	long long ans=0;
	cin >> N;
	vector<int> a(N);
	for(i=0;i<N;++i){
		cin >> a[i];
	}
	for(i=0;i<N;++i){
		while(j+1<N && a[j+1]>a[j]){
			++j;
		}
		ans += j-i+1;
		if(i==j) ++j;
	}
	cout << ans << endl;
	return 0;
}
