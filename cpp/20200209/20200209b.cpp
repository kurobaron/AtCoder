#include <iostream>
using namespace std;

int main(void){
	string S;
	int i;
	cin >> S;
	for(i=0;i<S.length();i++){
		S[i] = 'x';
	}
	cout << S << "\n";
}
