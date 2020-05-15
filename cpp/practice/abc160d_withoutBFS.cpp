#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	int N,X,Y,i,j,d;
	cin >> N >> X >> Y;
	--X; --Y;
	vector<int> ans(N);
	for(i=0;i<N;i++){
		for(j=i+1;j<N;j++){
			d = min(abs(j-i),abs(X-i)+abs(Y-j)+1);
			d = min(d, abs(Y-i)+abs(X-j)+1);
			ans[d]++;
		}
	}
	for(i=1;i<N;i++) cout << ans[i] << endl;
	return 0;
}
