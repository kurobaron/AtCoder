#include <iostream>
using namespace std;

int main(void){
	int x,i,flg=0;
	cin >> x;
	while(flg==0){
		if(x==2||x==3||x==5||x==7){
			cout << x << endl;
			return 0;
		}
		if(x%2==0){
			x += 1;
			continue;
		}
		for(i=3;i<x/2;i+=2){
			if(x%i==0){
				x += 1;
				flg = 1;
				break;
			}
		}	
		if(flg==1){flg = 0;}
		else{flg = 1;}
	}
	cout << x << endl;
	return 0;
}
