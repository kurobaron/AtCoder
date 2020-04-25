#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	int a,b,i,ans=0;

	cin >> a >> b;
	if(a <= b){
		for(i=0;i<b;i++){
			ans += a*pow(10,i);
		}
		cout << ans << endl;
		return 0;
	}else{
		for(i=0;i<a;i++){
			ans += b*pow(10,i);
		}
		cout << ans << endl;
		return 0;
	}
}	
