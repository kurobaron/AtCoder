#include <iostream>
#include <cmath>
using namespace std;

int main(){
	long A,B,X,n1,n2;
	cin >> A >> B >> X;
	n1 = 1;
	n2 = 1000000000;
	while(n1!=n2){
		long cul = A*n2 + B*((long)log10(n2)+1);
		if(X < cul){
			n2 = (n1 + n2)/2;
		}else{
			long tmp = n2 - n1;
			n1 += tmp;
			n2 += tmp;
		}
	}
	if(n1 > 1000000000) cout << 1000000000 << endl;
	else if(A*n2 + B*((long)log10(n2)+1)>X) cout << 0 << endl;
	else cout << n1 << endl;
	return 0;
}
