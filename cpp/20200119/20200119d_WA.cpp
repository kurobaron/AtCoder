#include <iostream>
#include <cmath>
using namespace std;

int roop(int n1, int n2, int p, int N){
	tmp = 0;
	if(n1==n2){
		for(j=1;j<=p-1;j++){
			cal = 1;
			for(k=0;k<=j;k++){
				cal += pow(10,k);
			}
			cal *= 2*pow(10,j);
			cal -= pow(10,j);
			tmp += cal;
		}
		return tmp;
	}else{
		if(N%10*pow(10,p) + N/pow(10,p) < N-N%pow(10,p){
			for(j=1;j<=p-1;j++){
				cal = 0;
				for(k=0;k<=j;k++){
					cal += pow(10,k);
				}
				cal *= 2*pow(10,k);
				tmp += cal;
			}
			return tmp;
		}else if(N%10*pow(10,p) + N/pow(10,p) < N){
		
		}else{
			for(j=1;j<=p-1;j++){
				cal = 0;
				for(k=0;k<=j;k++){
					cal += pow(10,k);
				}
				if(j==p-1){
					cal -= pow(10,p-1);
				}
				cal *= 2*pow(10,k);
				tmp += cal;
			}
			return tmp;
		}
	}
}	

int main(void){
	int N;

	cin >> N;
	if(N < 10){
		cout << N << endl;
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
		cout << cnt << endl;
		return 0;
	}else{
		cnt = 9+9+9+81;
		p = log10(N);
		for(i=10;i<100;i++){
			if(i/10*pow(10,p)+i%10 > N){
				cnt += roop(i/10, i%10, p-1, N);
			}else{
				cnt += roop(i/10, i%10, p, N);	
			}
		}
		cout << cnt << endl;
		return 0;
	}
}
