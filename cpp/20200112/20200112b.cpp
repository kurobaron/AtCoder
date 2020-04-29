#include <iostream>
#include <stdlib.h>
using namespace std;

int N,K,M,tmp,i=0,cnt=0;

int main(void){
	cin >> N >> K >>M;
	while(cin >> tmp){
		cnt += tmp;
		i++;
		if(i >= N-1){
			break;
		}
	}
	if(N*M - cnt > K){
		cout << -1 << endl;
		return 0;
	}else{
		if(N*M - cnt <= 0){
			cout << 0 << endl;
			return 0;
		}else{
			cout << N*M - cnt << endl;
			return 0;
		}	
	}
}
