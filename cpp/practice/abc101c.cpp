#include <iostream>
#include <vector>
using namespace std;

int main(){
	int i,N,K,ans;
	cin >> N >> K;
	vector<int> A(N);
	for(i=0;i<N;++i) cin >> A.at(i);
	auto it = A.begin();
	while(it!=A.end()){
		if(*it==1){
			int idx = distance(A.begin(),it);
			ans = idx%(K-1)==0 ? idx/(K-1) : idx/(K-1)+1;
			idx += idx%(K-1);
			ans += (N-idx-1)%(K-1)==0 ? (N-idx-1)/(K-1) : (N-idx-1)/(K-1)+1;
		}
		++it;
	}
	cout << ans << endl;
	return 0;
}
