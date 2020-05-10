#include <iostream>
using namespace std;

int main(){
	int N;
	string S;
	
	cin >> N;
	cin >> S;
	for(int i=0;i<S.length();i++){
		S[i] += N;
		if((int)S[i] > 90){
			S[i] = (int)S[i] - 26;
		}
	}
	cout << S << endl;
	return 0;
}
