#include <iostream>
using namespace std;
using ll = long long;

int main(){
	int flgC=0,flgD=0,flgCD=0;
	ll i,a,b,c,d,cd,A,B,tmp,cntC,cntD,cntCD;
	cin >> a >> b >> c >> d;
	cntC = (b-a+1)/c;
	cntD = (b-a+1)/d;
	B = d>=c? d : c;
	A = d>=c? c : d;
	while(A!=0){
		tmp = B;
		B = A;
		A = tmp%A;
	}
	cd = B*c/B*d/B;
	cntCD = (b-a+1)/(cd);
	if((b-a+1)%c>=c-(a-1+c*cntC)%c) ++cntC;
	if((b-a+1)%d>=d-(a-1+d*cntD)%d) ++cntD;
	if((b-a+1)%cd>=cd-(a-1+cd*cntCD)%cd) ++cntCD;
	cout << b-a+1-cntC-cntD+cntCD << endl;
	return 0;
}
