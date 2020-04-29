#include <iostream>
#include <stdlib.h>
using namespace std;

int N,i=0,j,tmp,num,ran,cnt=0;
int *P;

int search(int t, int r, int a[]){
		for(i=0;i<r;i++){
			if(a[i] == t){
				return i;
			}
		}
		return -1;
	}

int main(void){
	cin >> N;
	P = (int *)malloc(sizeof(int)*N);
	while(cin >> num){
		P[i] = num;
		i++;
		if(i == N){
			break;
		}
	}
	ran = N;
	for(j=1;j<N+1;j++){
		tmp = search(j, ran, P);
		if(tmp >= 0){
			ran = tmp;
			cnt += 1;
		}else{
			continue;
		}
	}
	cout << cnt << "\n";
	free(P);
	return 0;
}
