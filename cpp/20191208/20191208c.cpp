#include <iostream>
using namespace std;

int count(int n){
	if(n==0) return 0;
	return (n & 1) + count(n >> 1);
}

void search(){
	int N,ans;
	int x[15][14],y[15][14];
	int A[15];
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> A[i];
		for(int j=0;j<A[i];j++){
			cin >> x[i][j] >> y[i][j];
		}
	}
	ans = 0;
	for(int i=1;i<(1 << N);i++){
		bool ok = true;
		for(int j=0;j<N;j++){
			if(!(i & (1 << j))) continue;
			for(int k=0;k<A[j];k++){
				if(((i >> (x[j][k]-1)) & 1) ^ y[j][k]) ok = false;
			}
		}
		if(ok) ans = max(ans, count(i));
	}
	cout << ans << endl;
}

int main(){
	search();
	return 0;
}
