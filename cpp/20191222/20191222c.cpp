#include <iostream>
using namespace std;

int main(){
	long a,b,i,stk=1;
	cin >> a >> b;
	while(a%2==0 && b%2==0){
		a /= 2;
		b /= 2;
		stk *= 2;
	}
	for(i=3;i<=b/2;i+=2){
		while(a%i==0 && b%i==0){
			a /= i;
			b /= i;
			stk *= i;
		}
	}
	cout << a*b*stk << endl;
	return 0;
}
