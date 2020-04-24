#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void){
	int H,N,t,i=0;
	int *A;

	cin >> H >> N;
	A = (int *)malloc(sizeof(int)*N);
	while(cin >> t){
		A[i] = t;
		i++;
		if(i>=N){
			break;
		}
	}
	for(i=0;i<N;i++){
		H -= A[i];
	}
	if(H<=0){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	free(A);

	return 0;
}
