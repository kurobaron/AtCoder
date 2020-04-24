#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	int i,n;
	long H,cnt=0;

	cin >> H;
	for(i=0;i<40;i++){
		if(pow(2,i) <= H && H < pow(2,i+1)){
			n = i;
			break;
		}
	}
	for(i=0;i<=n;i++){
		cnt += pow(2,i);
	}
	cout << cnt << endl;

	return 0;
}
