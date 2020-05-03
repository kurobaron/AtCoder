#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	int N,f,e,i,j,k,cnt=0;
	int count[10][10] = {0};
	cin >> N;
	for(i=1;i<=N;i++){
		f = i/(pow(10,(int)log10(i)));
		e = i%10;
		count[f][e]++;
	}
	for(j=0;j<10;j++){
		for(k=0;k<10;k++){
			cnt += count[j][k]*count[k][j];
		}
	}
	cout << cnt << endl;
	return 0;
}
