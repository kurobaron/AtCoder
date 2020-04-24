#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main(void){
	int N,K,t,i=0;
	long cnt=0;
	int *H;

	cin >> N >> K;
	H = (int *)malloc(sizeof(int)*N);
	while(cin >> t){
		H[i] = t;
		i++;
		if(i>=N){
			break;
		}
	}
	sort(H,H+N,greater<int>());
	for(i=K;i<N;i++){
		cnt += H[i];
	}
	cout << cnt << endl;
	free(H);

	return 0;
}

