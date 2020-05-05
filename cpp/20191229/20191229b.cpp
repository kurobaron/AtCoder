#include <iostream>
using namespace std;

int main(void){
	long i,nt,na,K;
	cin >> nt >> na >> K;
	nt -= K;
	if(nt<0){
		na += nt;
	}
	if(nt<0){nt = 0;}
	if(na<0){na = 0;}
	cout << nt << " " << na << endl;
	return 0;
}
