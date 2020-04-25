#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	int N;

	cin >> N;
	if(N < 10){
		cout << N;
		return 0;
	}else if(N < 100){
		cnt = 9;
		for(i=10;i<=N;i++){
			if(i%10!=0 && i%10*10+i/10<=N){
				cnt += 1;
				if(i%10==i/10){
					cnt+=1;
				}
			}
		}
		cout << cnt;
		return 0;
	}else{
		cnt = 9+9+9+81;
		n = log10(N)+1;
		for(i=10;i<100;i++){
			if(i%10==0){
				continue;
			}
			for(j=1;j<n-2;j++){
				cnt += pow(10,j);
				if(i%10==1/10){
					cnt +=j+1;
				}
			}
				
