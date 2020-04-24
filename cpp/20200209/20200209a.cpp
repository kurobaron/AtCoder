#include <iostream>
using namespace std;

int main(void){
	string S,T,U;
	int A,B;
	cin >> S >> T;
	cin >> A >> B;
	cin >> U;
	if(U == S){
		A--;
	}else if(U == T){
		B--;
	}
	cout << A << " " << B << "\n";
	return 0;
}
