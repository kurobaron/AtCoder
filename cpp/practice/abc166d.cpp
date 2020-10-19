#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int i,j,X;
	cin >> X;
	for(i=-120;i<=120;++i){
		for(j=-120;j<=120;++j){
			if(i<0&&j>0) continue;
			if(pow(i,5)-pow(j,5)==X){
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}
}
